#include <stdio.h>
#include "football.h"

int main() {
    int points;

    while (1) {
        printf("Enter 0 or 1 to STOP \nEnter the NFL score: ");
        scanf("%d", &points);

        if (points == 1 || points == 0) {
            break; 
        }
        else if (points <0){
            printf("Invalid NFL score.\n");
        }
        else {
            print_combinations(points);
        }
    }

    return 0;
}