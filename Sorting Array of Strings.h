//
//  Sorting Array of Strings.h
//  Hacker-Rank-Problems-C
//
//  Created by dev-zgr on 16.12.2022.
//

#ifndef Sorting_Array_of_Strings_h
#define Sorting_Array_of_Strings_h
#endif /* Sorting_Array_of_Strings_h */

/*
 The following section declares function protypes
 */


int lexicographic_sort(const char* a, const char* b);
int lexicographic_sort_reverse(const char* a, const char* b);
int sort_by_number_of_distinct_characters(const char* a, const char* b);
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b));






int lexicographic_sort(const char* a, const char* b) {
int number = strcmp(a, b);                              // calculates if string a is greater or less than b
if(number >0){                                          // This section determines the return value based on number
    return 0;
}else if (number == 0) {              // if string are equal returns 1 or string a is less than string b returns 0
 return 1;
}else {
return 1;
}
}



int lexicographic_sort_reverse(const char* a, const char* b) {
int number = strcmp(a, b);                          // calculates if string is greater or less than b
if(number > 0){                                     // if section determines what output 1 or 0 will be returned
    return 1;
}else if (number == 0) {
return 1;
}else{
    return 0;
}
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    float dstnc_a = 0;                              // distinc characters in b
    float dstnc_b =  0;                             // distinc characters in a
    for(int i = 0; i<strlen(a); i++){              //  This loop iterates over the string indices
        float count = 0;                           // set number of character in string to 0
        char *pivot = strchr(a, a[i]);               // set pivot point to first occurence of character
        while(pivot != NULL){                        // while pivot point isnt null set pivot to next character
            pivot++;
            pivot = strchr(pivot, a[i]);               // set pivot to next occurence of character if isnt set to NUll
            count++;                                   // increase count by one
        }
        dstnc_a += 1 / count;            //incerase dstnc a by 1/count ex: if string is aaa it will incraese 1/3 for 3 times
    }
    for(int i = 0; i<strlen(b); i++){                  // do same for string b
        float count = 0;
        char *pivot = strchr(b, b[i]);
        while(pivot != NULL){
            pivot++;
            pivot = strchr(pivot, b[i]);
            pivot++;
        }
        dstnc_b += 1/count;
    }
    int result = dstnc_a - dstnc_b;             // subtrack a and b's distinc characters
    if (result<0){                              // if section determines the return respect to result
        return 1;
    }else if(result>0){
        return 0;
    }else {
    return lexicographic_sort(a, b);
    }
}

int sort_by_length(const char* a, const char* b) {
    
    
    /* This function compares string respect to its lengts */
    
    unsigned long a_0 = strlen(a);          //get booth strings
    unsigned long b_0 = strlen(b);
    if (a_0<b_0){                           // return 1 or 0 respect to their greatness relation
        return 1;
    }else if (a_0>b_0){
        return 0;
    }else{
        return lexicographic_sort(a, b);
    }
    
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    /* This function takes the argument as string list
     (char**), lenght of strnig array  and comparision
     function and sorts them with insertion sort */
    
    
for(int j = 1; j<len;j++){                      // from index 1 to lenght
    char *key = arr[j];                         // chose key in arr(j)
    int left_arm = j - 1;                       // set left arm to j -1
    while(left_arm >= 0 && cmp_func(key,arr[left_arm])){            // this section checks and finds where key should occur
        arr[left_arm+1] = arr[left_arm];
        left_arm--;
        
    }
    arr[left_arm+1] = key;                                          // places key to right place
}

}
