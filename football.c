#include <stdio.h>
#include "football.h"

//td2 is 8 points 
//tdfg is 7 points
//td is 6 points
//fg is 3 points
//safety is 2 points
void print_combinations(int points) {
    printf("Possible combinations of scoring plays if a team’s score is %d:\n", points);
    
    for (int td2 = 0; td2 * 8 <= points; td2++) { 
        for (int tdfg = 0; tdfg * 7 + td2 * 8 <= points; tdfg++) {
            for (int td = 0; td * 6 + tdfg * 7 + td2 * 8 <= points; td++) {
                for (int fg = 0; fg * 3 + td * 6 + tdfg * 7 + td2 * 8 <= points; fg++) {
                    for (int safety = 0; safety * 2 + fg * 3 + td * 6 + tdfg * 7 + td2 * 8 <= points; safety++) {
                        if (safety * 2 + fg * 3 + td * 6 + tdfg * 7 + td2 * 8 == points) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, tdfg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int count_combinations(int points) {
    int count = 0;
    
    for (int td2 = 0; td2 * 8 <= points; td2++) { 
        for (int tdfg = 0; tdfg * 7 + td2 * 8 <= points; tdfg++) {
            for (int td = 0; td * 6 + tdfg * 7 + td2 * 8 <= points; td++) {
                for (int fg = 0; fg * 3 + td * 6 + tdfg * 7 + td2 * 8 <= points; fg++) {
                    for (int safety = 0; safety * 2 + fg * 3 + td * 6 + tdfg * 7 + td2 * 8 <= points; safety++) {
                        if (safety * 2 + fg * 3 + td * 6 + tdfg * 7 + td2 * 8 == points) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}
