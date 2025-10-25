/*
Christian Won
Wonc@purdue.edu
Section 004
Eric Matson
*/
#include<stdio.h>
#include<stdbool.h>
#define ROWS 6
#define COLS 6

int rows = 0;
int cols = 0;

char maze[ROWS][COLS] = {      //Defining the maze
       {'S','#','#','#','#','#'},
       {'.','.','.','.','.','#'},
       {'#','.','#','#','#','#'},
       {'#','.','#','#','#','#'},
       {'.','.','.','#','.','G'},
       {'#','#','.','.','.','#'}
};

enum Dir { //Declaring conditions for switch case
    N,
    S,
    E,
    W
};

void mazeGo(enum Dir D) {
    maze[rows][cols] = '+'; //adding character to show movement

    switch(D) //switch satment to traverse maze
    {
        case N:
            if(maze[rows - 1][cols] == '.' || maze[rows - 1][cols] == 'G') { //move North
                rows -= 1;
                break;
            }
            else {
                return;
            }
        case S:
            if(maze[rows + 1][cols] == '.' || maze[rows + 1][cols] == 'G') { //Move South
                rows += 1;
                break;
            }
            else {
                return;
            }
        case E:
            if(maze[rows][cols + 1] == '.' || maze[rows][cols + 1] == 'G') { //Move Ease
                cols += 1;
                break;
            }
            else {
                return;
            }
        case W:
            if(maze[rows][cols - 1] == '.' || maze[rows][cols - 1] == 'G') {//Move West
                cols -= 1;
                break;
            }
            else {
                return;
            }
    }
    mazeGo(S); //Recursive calls to each direction
    mazeGo(E);
    mazeGo(N);
    mazeGo(W);
}

void printMaze() {
    for(int i = 0; i < 6; i++){ //Loop through 2D array to print maze
        for(int j = 0; j < 6; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}


int main() {
    printf("===================\n");
    printf("Initial State: \n");
    printf("===================\n");
    printMaze();// Print initial state
    printf("===================\n");
    printf("Final State: \n"); 
    printf("===================\n");
    mazeGo(S); //Start recursive trversal of maze
    printMaze();//Print final state
    return 0; //Return
}
