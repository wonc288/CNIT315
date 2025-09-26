/*
Christian Won
Wonc@purdue.edu
Section 004
Eric Matson
*/
#include<stdio.h>
#include<math.h> 
#define pi 3.14
#define MAX 2640 
#define MIN 1000 

float calculateWatered(float r);
float notWatered(float x, float y);
float calculateWater(float x);
float calculateTime(float r);

float calculateWatered(float r) { //Function to calculate area watered
    float area = 0;
    area = pi * r * r;
    return area;
}
float notWatered(float x, float y) { //Function to calculate area not watered
    return pow(x,2) - y;
}
float calculateWater(float x) { //Function to calculate water needed
    return x * 0.17;
}
float calculateTime(float r) {//Function to calculate time needed to water
    float circumference = 2 * pi * r;
    return circumference / 18;
}

int main() {
    int choice = 0;
    int count = 0;
    int side = 0;
    float radius = 0;
    float watered = 0;


    printf("Would you like to calculate farm size output?(0 for yes/1 for no): "); //Get input to decide whether to do calculation
    scanf("%d", &choice);
    if(choice == 1) {
        return 1;
    }
    else {
        while(1) { //Validate input
            printf("Enter a side length for the field 1000ft - 2640ft: ");
            scanf("%d", &side);
            if(side < MIN || side > MAX) {
                printf("Invalid entry, enter a valid number\n");
                continue;
            }
            else {
                break;
            }
        }
        printf("Doing calculations...\n");
        radius = side / 2;
        watered = calculateWatered(radius);
        printf("Area getting watered: %.2f ft^2\n", watered); //Output area watered
        count++; //Increment count when calculation completes
        printf("Area not being watered: %.2f ft^2\n", notWatered(side, watered));//Output area not watered
        count++;
        printf("Gallons of water needed: %.2f gallons\n", calculateWater(watered));//Output water needed
        count++;
        printf("Time needed to water: %.2f hours\n", calculateTime(radius));//Output time needed
        count++;
    }

    printf("Program has ended"); //End Program
    return count;
}
