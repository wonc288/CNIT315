/*
Christian Won
Wonc@purdue.edu
Section 004
Eric Matson
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int one = 0; //Number of type 1 boxes
    int two = 0; //Number of type 2 boxes
    int totalVolume = 0; // Total space in container
    int twoVolume = 0; // Volume of type1 boxes
    int oneVolume = 0; //Volume of type2 boxes
    int cost1 = 20; //Cost of type1 box
    int cost2 = 35; //Cost of type2 box
    int totalCost = 0; // Total cost on containers
    int remainingVolume = 0; // Volume remaining
    int remaining2 = 0; //Number of type2 boxs after type one
    int discount = 0; //Discount amount

    totalVolume = 40 * 8 * 8; //Calculate total volume of container
    remainingVolume = totalVolume; //set remaining volume
    printf("Total space = %d cubic feet\n\n", totalVolume);

    printf("How many Type 1 containers do you want: ");
    scanf("%d", &one); //Get input for type one boxes
    oneVolume = one; //Calculate type1 box
    if(one > totalVolume) { // Input validation
        printf("Too large!\n");
        return 1;
    }
    else if(one < 0) {
        printf("No negatives!\n");
        return 1;
    }
    totalCost += cost1 * one;
    remainingVolume -= oneVolume;
    remaining2 = remainingVolume / 4;
    printf("Remaining space: %d cubic feet\n", remainingVolume);
    printf("Remaining Type2 boxes: %d\n\n", remaining2);

    printf("How many Type 2 containers do you want: ");
    scanf("%d", &two);
    twoVolume = two * 4;
    if (twoVolume > remainingVolume) { // Input validation
        printf("Too large!\n");
        return 1;
    }
    else if(two < 0) {
        printf("No negatives!\n");
        return 1;
    }
    totalCost += cost2 * two; //Calculate total cost
    remainingVolume -= twoVolume;// Calculate remaining volume

    printf("\nRemaining volume is %d cubic feet\n", remainingVolume);
    printf("Total cost before discount: $%d\n", totalCost);

    discount = 2 * remainingVolume;//calculate discount
    totalCost -= discount;
    if(discount > totalCost) { //Check for min price
        totalCost = 0;
    }
    printf("Discount: $%d\n\n", discount);
    printf("Total cost after discount: $%d\n", totalCost);

    printf("Program has ended...\n");

    return 0;
}
