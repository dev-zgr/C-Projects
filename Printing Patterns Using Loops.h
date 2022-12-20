//
//  Printing Patterns Using Loops.h
//  Hacker-Rank-Problems-C
//
//  Created by Özgür Kamalı on 20.12.2022.
//

#ifndef Printing_Pattern_Using_Loops_h
#define Printing_Pattern_Using_Loops_h
#endif

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void pattern_printer(int n){
    /* this function prints  n by n square pattern that numbers
     decrease throught the center of square*/
    
    for(int row = 0; row < (2*n -1); row++){                // iterate over 2*-1 for patter
        int symbol = n;                                     // set start symbol to n
        int efective_row = row;
        if (row >= n){                                      // while row >= n set efective_row to total row - current row -1
            efective_row = (2*n -1) - efective_row -1;      // this will let help to print patter to reverse after center
        }
        for(int left = 0; left < efective_row; left++){     // print left side of row first and decrease symbol by one
            printf("%d ",symbol);
            symbol--;
        }
        for(int middle = 0; middle < (2*(n-efective_row)-1); middle++){ // print middle of row then
            printf("%d ",symbol);
        }
        for(int right = 0; right <efective_row ; right++){ //print right side row incrementig it by one
            symbol++;
            printf("%d ", symbol);
        }
        puts("");                                          // print new line at the end of row
    }
    
}

