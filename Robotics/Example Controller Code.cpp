#include <iostream>

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <tf/transform_listener.h>

class RobotDriver
{
private:
  //! The node handle we'll be using
  ros::NodeHandle nh_;
  //! We will be publishing to the "/base_controller/command" topic to issue commands
  ros::Publisher cmd_vel_pub_;
  tf::TransformListener listener_;

public:
  //! ROS node initialization
  RobotDriver(ros::NodeHandle &nh)
  {
    nh_ = nh;
    //set up the publisher for the cmd_vel topic
    cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
  }

  //! Drive forward a specified distance based on odometry information
  bool driveForwardOdom(double distance)
  {
      //wait for the listener to get the first message
      listener_.waitForTransform("base_footprint", "odom",
                                 ros::Time(0), ros::Duration(1.0));

      //we will record transforms here
      tf::StampedTransform start_transform;
      tf::StampedTransform current_transform;

      //record the starting transform from the odometry to the base frame
      listener_.lookupTransform("base_footprint", "odom",
                                ros::Time(0), start_transform);

      //we will be sending commands of type "twist"
      geometry_msgs::Twist base_cmd;
      //the command will be to go forward at 0.25 m/s
      base_cmd.linear.y = base_cmd.angular.z = 0;
      base_cmd.linear.x = 0.5;

      ros::Rate rate(10.0);
      bool done = false;
      while (!done && nh_.ok())
      {
        //send the drive command
        cmd_vel_pub_.publish(base_cmd);
        rate.sleep();
        //get the current transform
        try
        {
          listener_.lookupTransform("base_footprint", "odom",
                                    ros::Time(0), current_transform);
        }
        catch (tf::TransformException ex)
        {
          ROS_ERROR("%s",ex.what());
          break;
        }
        //see how far we've traveled
        tf::Transform relative_transform =
          start_transform.inverse() * current_transform;
        double dist_moved = relative_transform.getOrigin().length();

        if(dist_moved > distance) done = true;
      }
      if (done) return true;
      return false;
  }


  bool turnOdom(bool clockwise, double radians)
  {
      while(radians < 0) radians += 2*M_PI;
      while(radians > 2*M_PI) radians -= 2*M_PI;

      //wait for the listener to get the first message
      listener_.waitForTransform("base_footprint", "odom",
                                 ros::Time(0), ros::Duration(1.0));

      //we will record transforms here
      tf::StampedTransform start_transform;
      tf::StampedTransform current_transform;

      //record the starting transform from the odometry to the base frame
      listener_.lookupTransform("base_footprint", "odom",
                                ros::Time(0), start_transform);

      //we will be sending commands of type "twist"
      geometry_msgs::Twist base_cmd;
      //the command will be to turn at 0.75 rad/s
      base_cmd.linear.x = base_cmd.linear.y = 0.0;
      base_cmd.angular.z = 0.75;
      if (clockwise) base_cmd.angular.z = -base_cmd.angular.z;

      //the axis we want to be rotating by
      tf::Vector3 desired_turn_axis(0,0,1);
      if (!clockwise) desired_turn_axis = -desired_turn_axis;

      ros::Rate rate(10.0);
      bool done = false;
      while (!done && nh_.ok())
      {
        //send the drive command
        cmd_vel_pub_.publish(base_cmd);
        rate.sleep();
        //get the current transform
        try
        {
          listener_.lookupTransform("base_footprint", "odom",
                                    ros::Time(0), current_transform);
        }
        catch (tf::TransformException ex)
        {
          ROS_ERROR("%s",ex.what());
          break;
        }
        tf::Transform relative_transform =
          start_transform.inverse() * current_transform;
        tf::Vector3 actual_turn_axis =
          relative_transform.getRotation().getAxis();
        double angle_turned = relative_transform.getRotation().getAngle();
        if ( fabs(angle_turned) < 1.0e-2) continue;

        if ( actual_turn_axis.dot( desired_turn_axis ) < 0 )
          angle_turned = 2 * M_PI - angle_turned;

        if (angle_turned > radians) done = true;
      }
      if (done) return true;
      return false;
  }

  //! Loop forever while sending drive commands based on keyboard input
  bool driveKeyboard()
  {
    std::cout << "Type a command and then press enter.  "
      "Use '+' to move forward, 'l' to turn left, "
      "'r' to turn right, '.' to exit.\n";

    //we will be sending commands of type "twist"
    geometry_msgs::Twist base_cmd;

    char cmd[50];
    while(nh_.ok()){

      std::cin.getline(cmd, 50);
      if(cmd[0]!='+' && cmd[0]!='l' && cmd[0]!='r' && cmd[0]!='.')
      {
        std::cout << "unknown command:" << cmd << "\n";
        continue;
      }

      base_cmd.linear.x = base_cmd.linear.y = base_cmd.angular.z = 0;   
      //move forward
      if(cmd[0]=='+'){
    	driveForwardOdom(1.0);
        //base_cmd.linear.x = 0.25;
      } 
      //turn left (yaw) and drive forward at the same time
      else if(cmd[0]=='l'){
        //base_cmd.angular.z = 0.75;
        turnOdom(false, M_PI/2);
      } 
      //turn right (yaw) and drive forward at the same time
      else if(cmd[0]=='r'){
    	//base_cmd.angular.z = -0.75;
        turnOdom(true, M_PI/2);
        //base_cmd.linear.x = 0.25;
      } 
      //quit
      else if(cmd[0]=='.'){
        break;
      }

      //publish the assembled command
      cmd_vel_pub_.publish(base_cmd);

    }
    return true;
  }

 };

int main(int argc, char** argv)
{
  //init the ROS node
  ros::init(argc, argv, "robot_driver");
  ros::NodeHandle nh;

  RobotDriver driver(nh);
  driver.driveKeyboard();
}
