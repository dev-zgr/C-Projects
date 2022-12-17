//
//  Sorting Array of Strings.h
//  Hacker-Rank-Problems-C
//
//  Created by Özgür Kamalı on 16.12.2022.
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
int number = strcmp(a, b);
if(number > 0){
    return 1;
}else if (number == 0) {
return 1;
}else{
    return 0;
}
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    float dstnc_a = 0;
    float dstnc_b =  0;
    for(int i = 0; i<strlen(a); i++){
        float count = 0;
        char *set = strchr(a, a[i]);
        while(set != NULL){
            set++;
            set = strchr(set, a[i]);
            count++;
        }
        dstnc_a += 1 / count;
    }
    for(int i = 0; i<strlen(b); i++){
        float count = 0;
        char *set = strchr(b, b[i]);
        while(set != NULL){
            set++;
            set = strchr(set,b[i]);
            count++;
        }
        dstnc_b += 1/count;
    }
    int result = dstnc_a - dstnc_b;
    if (result<0){
        return 1;
    }else if(result>0){
        return 0;
    }else {
    return lexicographic_sort(a, b);
    }
}

int sort_by_length(const char* a, const char* b) {
    unsigned long a_0 = strlen(a);
    unsigned long b_0 = strlen(b);
    if (a_0<b_0){
        return 1;
    }else if (a_0>b_0){
        return 0;
    }else{
        return lexicographic_sort(a, b);
    }
    
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
for(int j = 1; j<len;j++){
    char *key = arr[j];
    int left_arm = j - 1;
    while(left_arm >= 0 && cmp_func(key,arr[left_arm])){
        arr[left_arm+1] = arr[left_arm];
        left_arm--;
        
    }
    arr[left_arm+1] = key;
}

}
