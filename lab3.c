#include<stdio.h>
#include<string.h>

int factorial(int n);
void runHanoi(int n, char x, char y, char z);
void reverse(char str[], int l, int r);

void runHanoi(int n, char x, char y, char z) {
    if(n == 1) {
        printf("Moved disk from %c to %c\n", x, z);
    }
    else {
        runHanoi(n-1, x,z,y);
        runHanoi(1,x,y,z);
        runHanoi(n-1,y,x,z);
    }
}

int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

void reverse(char str[], int l, int r) {
    if(l <= r) {
        return;
    }
    else {
        char temp;
        str[l] = temp;
        str[l] = str[r];
        str[r] = temp;
        reverse(str, l + 1, r - 1);
    }
}

int main() {
    int choice = 0;

    while(1) {
        printf("=======================================\n");
        printf("MENU:\n");
        printf("=======================================\n");
        printf("1. Factorial\n");
        printf("2. Towers of Hanoi\n");
        printf("3. Reverse\n");
        printf("4. Exit\n");
        scanf(" %d", &choice);

        if(choice == 4) {
            return 0;
        }
        else if(choice == 1) {
            int num = 0; 
            printf("What number would you like to find the factorial: ");
            scanf("%d", &num);
            printf("The factorial of %d is : %d\n", num, factorial(num));
            continue;
        }
        else if(choice == 2) {
            int disks = 0;
            char x = 'A';
            char y = 'B';
            char z = 'C';
            printf("How many disks: ");
            scanf("%d", &disks);
            runHanoi(disks,x,y,z);
            continue;
        }
        else if(choice == 3) {
            char str[30] = "";
            printf("Please enter a string to reverse: ");
            scanf("%[^\n]", str);
            printf("String before: %s\n", str);
            reverse(str, 0, strlen(str) - 1);
            printf("String after : %s\n\n", str);
            continue;
        }
        else {
            printf("Please entera number 1 - 4\n");
            continue;
        }


    }



}
