/*
Name: Jana Frady
KUID: 3085051
Lab Session: Thursday 4 p.m.
Lab Assignment Number: 04
Program Description: This program receives a score and determines all possible combinations of scoring plays that could result from the score.
Collaborators: None
*/

#include <stdio.h>

// defines different scores
#define TD2pt 8
#define TD1pt 7
#define TD 6
#define field 3
#define safety 2

void combination(int score){
    // keeps track of how many of each point value possible
    int safe = 0;
    int fieldgoal = 0;
    int touchd = 0;
    int td_1pt = 0;
    int td_2pt = 0;

    while(1){
        if (td_2pt*TD2pt + td_1pt*TD1pt + touchd*TD + fieldgoal*field + safe*safety == score){ //checks if score matches
            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td_1pt, touchd, fieldgoal, safe);
        }

        safe++;
        if (safe*safety > score){ // checks safety
            safe = 0;
            fieldgoal++;
        }

        if (fieldgoal*field > score){ // checks fieldgoal
            fieldgoal = 0;
            touchd++;
        }

        if (touchd*TD > score){ // checks touchdown
            touchd = 0;
            td_1pt++;
        }

        if (td_1pt*TD1pt > score){ // checks touchdown 1 point
            td_1pt = 0;
            td_2pt++;
        }

        if (td_2pt*TD2pt > score){ // checks touchdown 2 point
            break;
        }
    }
}

int main(){
    // initializes program by asking user for input and checking to see if valid
    int score = 2;
    while (score != 0 || score != 1){
        int score;
        printf("\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d",&score);
        
        if (score == 0 || score == 1){ // quits program
            printf("Goodbye\n");
            break;
        } else if (score < 0){
            printf("Invalid Input\n");
        }
        combination(score);
    }
}