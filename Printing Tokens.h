//
//  Printing Tokens.h
//  Hacker-Rank-Problems-C
//
//  Created by Özgür Kamalı on 24.12.2022.
//

#ifndef Printing_Tokens_h
#define Printing_Tokens_h


#endif /* Printing_Tokens_h */

/* This header includes functions for printing every seperate word in newline  delimitted by ' '  */



void tokenPrinter(void){
    
    // Scans a string from used and puts \n when encount with ' ' 
    
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    for(int index = 0; index < strlen(s); index++){
        if(s[index] == ' '){
            puts("");
            continue;
        }
        printf("%c", s[index]);
    }
}
