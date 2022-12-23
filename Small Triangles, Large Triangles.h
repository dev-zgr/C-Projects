//
//  Small Triangles, Large Triangles.h
//  Hacker-Rank-Problems-C
//
//  Created by Özgür Kamalı on 23.12.2022.
//

#ifndef Small_Triangles__Large_Triangles_h
#define Small_Triangles__Large_Triangles_h
#endif
/* this header includes a functions/ structures for sorting triangles respect to their ared*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    
    // This structre defines triangles side
    
    
    int a;
    int b;
    int c;
};
typedef struct triangle triangle;


void sort_by_area(triangle* tr, int n) {
    
    
// This function calculates the areas of triangles and prints triangles sides respect to sorting
    
    
float unsorted[100] = {0};
int indexes[100] = {0};
    
// calculates and records triangles areas
for(int i= 0; i<n; i++){
    float a = tr[i].a;
    float b = tr[i].b;
    float c = tr[i].c;
    float p = ( a + b +c) / 2.0;
    unsorted[i] = sqrt(p* (p-a) * (p-b) * (p-c));
    indexes[i] = i;
}
    
// Sorts triangles respect to their ares
for(int tries = 0; tries <n-1; tries++){
    int holder = unsorted[0];
    int holder_index = indexes[tries];
    for(int subber = 0; subber < tries; subber++){
        if(holder > unsorted[subber]){
            unsorted[tries] = unsorted[subber];
            unsorted[subber] = holder;
            indexes[holder_index] = subber;
            indexes[subber] = holder_index;
        }
    }
}
    
// Prints  each triangles sides
for(int l=0; l<0;l++){
    int a = tr[indexes[l]].a;
    int b = tr[indexes[l]].b;
    int c = tr[indexes[l]].c;
    printf("%d %d %d\n",a,b,c);
}

}
