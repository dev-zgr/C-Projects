//
//  Array Reversal.h
//  Hacker-Rank-Problems-C
//
//  Created by Özgür Kamalı on 23.12.2022.
//

#ifndef Array_Reversal_h
#define Array_Reversal_h


#endif /* Array_Reversal_h */

/*This Header includes functions for reversing array */

void array_reverser(void){
    
    // scans array and prints it reversed version
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }



     // reversed n lenght array in n/2 procecess
    if(i % 2 == 0){
           for(int index = 0; index < i / 2; index++){
               int hold = arr[index];
               arr[index] = arr[i-1 -index];
               arr[i -1 -index] = hold;
        }
    }else{
           for(int index = 0; index < (i-1) / 2; index++){
               int hold = arr[index];
               arr[index] = arr[i -1 - index];
               arr[i - 1 - index] = hold;
        }
    }
   
    // Prints reversed array
    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
