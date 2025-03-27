#include <stdio.h>
#include "football.h"

//td2 is 8 points 
//tdfg is 7 points
//td is 6 points
//fg is 3 points
//safety is 2 points

void print_combinations(int points) { //void type because we only want to print
    printf("Possible combinations of scoring plays if a team’s score is %d:\n", points);
    
    for (int td2 = 0; td2 * 8 <= points; td2++) { //for each td2 that can fit inside points, incrememt td2 by 1
        for (int tdfg = 0; tdfg * 7 + td2 * 8 <= points; tdfg++) { //for each tdfg that can fit inside (points - td2), incrememt tdfg by 1
            for (int td = 0; td * 6 + tdfg * 7 + td2 * 8 <= points; td++) { //for each td that can fit inside (points - td2 - tdfg),
                                                                            // incrememt td by 1
                for (int fg = 0; fg * 3 + td * 6 + tdfg * 7 + td2 * 8 <= points; fg++) { //for each fg that can fit inside 
                                                                                    //(points - td2 - tdfg - td), incrememt fg by 1
                    for (int safety = 0; safety * 2 + fg * 3 + td * 6 + tdfg * 7 + td2 * 8 <= points; safety++) { //for each safety that can fit 
                                                                                                        //inside (points - td2 - tdfg - td - fg),
                                                                                                        // incrememt fg by 1
                        if (safety * 2 + fg * 3 + td * 6 + tdfg * 7 + td2 * 8 == points) { //if all of the possible ways to score's count's
                                                                                        //match the points value exactly
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, tdfg, td, fg, safety); //print combination
                        }
                    }
                }
            }
        }
    }
}

int count_combinations(int points) {
    int count = 0; //initialize integer value count at 0
    
    for (int td2 = 0; td2 * 8 <= points; td2++) { //similar logic to void print_combinations()
        for (int tdfg = 0; tdfg * 7 + td2 * 8 <= points; tdfg++) {
            for (int td = 0; td * 6 + tdfg * 7 + td2 * 8 <= points; td++) {
                for (int fg = 0; fg * 3 + td * 6 + tdfg * 7 + td2 * 8 <= points; fg++) {
                    for (int safety = 0; safety * 2 + fg * 3 + td * 6 + tdfg * 7 + td2 * 8 <= points; safety++) {
                        if (safety * 2 + fg * 3 + td * 6 + tdfg * 7 + td2 * 8 == points) {
                            count++; //only we increment count by 1 instead of printing the combination.
                        }
                    }
                }
            }
        }
    }
    return count; //final result
}
