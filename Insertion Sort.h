//
//  Insertion Sort.h
//  Hacker-Rank-Problems-C
//
//  Created by Özgür Kamalı on 24.12.2022.
//
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef Insertion_Sort_h
#define Insertion_Sort_h


/* This header includes functions for simulating  and see detailed movements in insertion sort */

#endif /* Insertion_Sort_h */



// Common prototypes for functions
char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);




int Sorter(int arr_count, int* arr) {
    
    // Insertion sort algorithm prints every move it does.
    
    int record = 0 ;
    for (int index = 1; index < arr_count;index++){
        int arm = arr[index];
        int left_arm = index -1;
        while(arr[left_arm]> arm && left_arm >=0){
            arr[left_arm+1] = arr[left_arm];
            left_arm--;
            arr[left_arm+1] = arm;
            record+= 1;
        }
    }
    for(int i = 0; i<arr_count; i++){
        printf("%d",arr[i]);
    }
    return record;
}




char* readline() {
    
    // Reads data from input and forms it
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}





char* ltrim(char* str) {
    
    // left trims the inputs string
    
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}






char* rtrim(char* str) {
    
    // Right trims the input string
    
    
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}





char** split_string(char* str) {
    
    //Splits string delimitted by ' '
    
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}





int parse_int(char* str) {
    
    // Parses the string
    
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}



// Followind command opens the file and reads every line consisting integers. Sorts them and prints every move.

/*
 
 
 int main(){
     FILE* fptr = fopen(getenv("Your File Path"), "w");

     int n = parse_int(ltrim(rtrim(readline())));

     char** arr_temp = split_string(rtrim(readline()));

     int* arr = malloc(n * sizeof(int));

     for (int i = 0; i < n; i++) {
         int arr_item = parse_int(*(arr_temp + i));

         *(arr + i) = arr_item;
     }

     int result = runningTime(n, arr);

     fprintf(fptr, "%d\n", result);

     fclose(fptr);

     return 0;
 }*/
