
// Requested sample time in milliseconds
int sampleTime = 22;

#define SAMPLE_TIME_DIFFERENCE ( 1.5 )
float dt = ( 1.0 * sampleTime + SAMPLE_TIME_DIFFERENCE ) / 1000.0;

// Robot position in m
float robotPosition = 0.0;

/**
    Sensor fusion constants
**/
float gainAngularVelocity = 1.3;
float gainAngle = 21.7;
float gainRobotSpeed = 86.3;
float gainRobotPosition = 350.0;


float robotAngle = 0.0;// Angle (integrated from angular rate) in degrees

float gyroRateBias;// Current of gyro rate bias in deg/s

float gyroRate;// Currently measured gyro rate in deg/s

/**
 * Get gyro rate based on a single reading
 */
float getGyroRate()
{
  // Originally an average was used in Balanc3r, but a single reading actually seems to be more stable
   return getGyroRate( gyroSensor );
}


/**
 * Calibration of gyro
 */
float calibrate()
{
   int numberOfReadings = 100;
   playSound( soundBeepBeep );
   writeDebugStreamLine( "Resetting gyro, keep robot still" );
  resetGyro( gyroSensor );
  // This sleep is very important!
  // If not used, the gyro readings will be way off afterwards
   sleep( 3000 );

   gyroRateBias = 0.0;
   // Make a few test readings prior to actual calibration
   for( int i = 0; i < numberOfReadings; i++ ) {
      gyroRateBias += getGyroRate();
   }
   gyroRateBias /= numberOfReadings;
   writeDebugStreamLine("Initial gyroRateBias (not used): %f", gyroRateBias );
   sleep( 500 );
   gyroRateBias = 0.0;
   sleep(100);
   for( int i = 0; i < numberOfReadings; i++ ) {
      gyroRateBias += getGyroRate();
   }
   gyroRateBias /= numberOfReadings;
   writeDebugStreamLine("Second gyroRateBias (not used): %f", gyroRateBias );
   sleep(500);
   gyroRateBias = 0.0;
   // And now do the actual calibration
   for( int i = 0; i < numberOfReadings; i++ ) {
      gyroRateBias += getGyroRate();
   }
   gyroRateBias /= numberOfReadings;
   writeDebugStreamLine("Third gyroRateBias (used): %f", gyroRateBias );
   playSound( soundDownwardTones );
   sleep( 100 );
   return gyroRateBias;
}

/**
 * Reads gyro and estimates angle and angular velocity TODO units?
 */
void readGyro()
{
   // Estimate of the current robotAngleBias due to drifting gyro
   static float robotAngleBias = 0.0;
   // This seems to be rather high. Corresponds to a full new update every ~100-300 ms (for dt = 20 ms and gyroRateBiasUpdateRatio = 0.2)...
   float gyroRateBiasUpdateRatio = 0.2;
   // Update ratio of robotAngleBias; should probably be way lower than gyroRateBiasUpdateRatio
   float robotAngleBiasUpdateRatio = 0.0; 
   float currentGyroRateMeasurement = getGyroRate();
   // Estimate gyroRateBias rate by updating the value slowly
   // By multiplying with dt we make scale meanUpdateRatio to 1 sec
   gyroRateBias = gyroRateBias * ( 1 - dt * gyroRateBiasUpdateRatio ) +
      currentGyroRateMeasurement * dt * gyroRateBiasUpdateRatio;
   // Angular velocity can be computed directly now
   gyroRate = currentGyroRateMeasurement - gyroRateBias;
   // We note that the above update is "slow" compared to sample rate; thus
   // for drifting values of the gyro rate bias, the esimated value will always lack behind.
   // This again means that the integrated gyro rate (the angle of the robot) will drift.
   // In principle this is not a problem as the combined sensor value also includes the robot position
   // and the robot position can then make up for the drift (and this can be seen as the robot 
   // slowly drifts in its position).
   // On the other hand we would like to have a good estimate of the angle.
   // In order to correct this we use the robot position over time to correct the angle
   // TODO we need a better way to do this; using the encoders really only works for a stationary robot
   //      In any case, we have set robotAngleBiasUpdateRatio = 0.0 , so this part is not used at all
   //      But this also means that the robotAngle eventually drifts a looong way from 0, thus triggering 
   //      an error scenario at some point in time
   robotAngleBias = robotAngleBias * ( 1 - dt * robotAngleBiasUpdateRatio ) -
      ( robotPosition * gainRobotPosition / gainAngle ) * dt * robotAngleBiasUpdateRatio;
   // And angle is computed based on integration from last epoch
   robotAngle += gyroRate * dt - robotAngleBias;
}

// call calibrate() at the start of your task main function 
// i.e gyroRateBias = calibrate();
// then when you need to, read the gyro and update gyroRateBias and robot angle
// using readGyro();
