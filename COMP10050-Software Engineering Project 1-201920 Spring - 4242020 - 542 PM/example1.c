//
//  example1.c
//  
//
//  Created by Lili on 24/01/2018.
//

#include <stdio.h>
#include <math.h>

float calculateSD(float data[]);

int main()
{
    int i;
    float data[10];
    
    /*This is used to read  10 float numbers from the console
     and place them into array data */
    printf("Enter 10 elements: ");
    for(i=0; i < 10; ++i)
        scanf("%f", &data[i]);
    
    /* prints on the console the standard deviation of the numbers
     * inserted as input
     */
    printf("\nStandard Deviation = %.6f", calculateSD(data));
    
    return 0;
}

//the function claculating the standard deviation
float calculateSD(float data[])
{
    //initialise sum, mean and the variance result
    float sum = 0.0, mean, variance = 0.0;
    
    int i;
    
    //sums the float numbers provided as input
    for(i=0; i<10; ++i)
    {
        sum += data[i];
    }
    
    //calculates the mean
    mean = sum/10;
    
    ////It first calcluate the variance,
    // by calculating the deviations of each data point from the mean,
    // squares the result of each, sum all of them  and divide the result by 10
    for(i=0; i<10; ++i)
        variance += pow(data[i] - mean, 2);
    
    variance = variance/10;
    
    
    // It returns the standard deviation by calculating the square root of the variance
    return sqrt(variance);
}
