#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
  double pidState;      	// Last position input
  double integralState;      	// Integrator state
  double integralMax, integralMin;  	
  // Maximum and minimum allowable integrator state
  double	integralGain,    	// integral gain
        	proportionalGain,    	// proportional gain
         	derivativeGain;     	// derivative gain
}PID;


double UpdatePID(PID * pid, double error, double position)
{
    double proportionalTerm, //proportional gain
    derivateTerm,        //derivative gain
    integralTerm;        //integral gain

    proportionalTerm = pid->proportionalGain * error;   
    // calculate the proportional term
    // calculate the integral state with appropriate limiting
    pid->integralState += error;
    if (pid->integralState > pid->integralMax) 
    {
        pid->integralState = pid->integralMax;
    }
    else if (pid->integralState < pid->integralMin)
    {
        pid->integralState = pid->integralMin;
    }
  
    integralTerm = pid->integralGain * pid->integralState;  // calculate the integral term
    derivateTerm = pid->derivativeGain * (position - pid->pidState);
    
    pid->pidState = position;

    return proportionalTerm + integralTerm - derivateTerm;
}

int * generate_array(int input){
    int size = 10;
    int *elements = malloc(sizeof(int)*input);

    // inizialize
    for (int i = 0; i < input; ++i){elements[i] = i;}

    for (int i = input - 1; i > 0; --i) {
      // generate random index
      int w = rand()%i;
      // swap items
      int t = elements[i];
      elements[i] = elements[w];
      elements[w] = t;
    }
    
    return elements;
}

int main(int argc,char *argv[])
{
    if(argc<2)
    {
        printf("Please enter a setpoint number\r\n");
    }
    
    PID *pid = malloc(sizeof(PID));
    
    pid->proportionalGain = 0.20; // play with these values
    pid->integralGain = 0.01;     // what happens when you do ?
    pid->derivativeGain = 0.10;   // does the PID react quicker ?
    
    int setpoint = atoi(argv[1]);
    
    int * elements = generate_array(setpoint);
    
    double err = 0;
    
    double position = (double)elements[0];
    double correction = UpdatePID(pid, position-setpoint, position);
        
    for(int y=0;y<15;y++){
        position -= correction;
        correction = UpdatePID(pid, position-setpoint, position);
        printf("Setpoint %d | current position %lf | correction (PID) %lf\r\n",setpoint,position,correction);
    }
    
    return 0;
}
