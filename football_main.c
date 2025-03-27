#include <stdio.h>
#include "football.h"

int main() {
    int points; //initialize points as integer value.

    while (1) {
        printf("Enter 0 or 1 to STOP \nEnter the NFL score: "); //user prompt
        scanf("%d", &points); //scan formatted string

        if (points == 1 || points == 0) { //if the user enters a 0 or 1.
            break; //exit the program
        }
        else if (points < 0){ //if the user gives invalid input i.e. a negative score.
            printf("Invalid NFL score.\n"); //Error message
        }
        else { //for all other valid inputs
            print_combinations(points); //show football score possibilities
        }
    }

    return 0; //finish running program
}