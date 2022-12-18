//
//  Querying the Document.h
//  Hacker-Rank-Problems-C
//
//  Created by Özgür Kamalı on 18.12.2022.
//

/*This Header includes function for querying the string documents  also this functions can be used for Hackerrank Querying the Document problems solutions*/

#ifndef Querying_the_Document_h
#define Querying_the_Document_h
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
#endif


char** sentence_word_organizer(char   *sentence);



char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    /* returns kth words in nth sentence it nth paragraph  in  char* format */
return document[n-1][m-1][k-1];
}



char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    /* returns kth sentence in nth paragraph  in  char** format */
return document[m-1][k-1];
}



char*** kth_paragraph(char**** document, int k) {
    /* returns kth paragraph in char *** format */
    
return document[k-1];
}



char** sentence_word_organizer(char   *sentence){

    //This function takes parameter as sentence and returns a array that contains seperated by words
    
    char *word = strtok(sentence, " ");                         // set first word to slice that seperated by " " in sentence
    char **word_list = NULL;                                    // set return string
    int word_count = 1;                                         // word count used to hold index of word in array
    while(word != NULL){                                        // iterate over str tok to access words seperated by " "
        if(word_count == 1){                                    // if its first word allocate memory for word list
            word_list = calloc(sizeof(char**), 1);
            char *memstr = malloc(sizeof(char*));              // allocate memory for word and assign word to it
            memstr = word;
            word_list[0] = memstr;                             // assign first words memory adress to word list[0]
            word = strtok(NULL, " ");
            word_count++;                                       // increase word count by one
        }
        char *mem_str = malloc(sizeof(char*));                  // assign memory for new word
        mem_str = word;                                         // assign memory to word
        word_list = (char**)realloc(word_list, sizeof(char*) * word_count);     //update word list size
        word_list[word_count-1] = mem_str;                     // assign word to related field in word_list
        word_count++;                                          // increase word count by one
        word = strtok(NULL, " ");                              // tokenize the new string
        
    }
    return word_list;                                          // return array
}




char**** get_document(char* text){
 
    /*This function converts  (\n) , (.)  and ( ) seperated string to paragraps ,sentences , words nested into each other.
      in return value docu[p][s][w] , p represented paragraps sepereted by (\n) , s represent sentences seperated by (.)
     w represent words seperated by () */
    
    char ****document = NULL;                                  // initialize document structrure to Null
    char *paragraf = strtok(text, "\n");                       // divide text to paragraps seperated by (\n)
    int paragraf_count = 1;                                   // index counter for placing paragraps in correct position
    while(paragraf != NULL){                                  //iterate over paragraps to place paragraps
        if(paragraf_count == 1){                              // if paragrap didnt initialized initalize it and assing paragraph to correct position
            document = calloc(1, sizeof(char***));
            char ***temp = malloc(sizeof(char***));
            temp = (char***)paragraf;
            paragraf_count++;
            document[0] = temp;
            paragraf = strtok(NULL, "\n");
        }
        char ***mem_str = malloc(sizeof(char***));    // if paragraph initialized reallocate its memory size and assing paragraph to correct position
        mem_str = (char***)paragraf;
        document = (char****)realloc(document, sizeof(char***) * paragraf_count);
        document[paragraf_count-1] = mem_str;
        paragraf_count++;
        paragraf = strtok(NULL, "\n");
    }
    
    for(int index = 0; index < paragraf_count-1;index++){       // evaluate every paragraph
        char *sentence = (char*)document[index];                // get paragraps to divide into sentences
        int sentence_count = 1;
        char *words = strtok(sentence, ".");                    // tokenize paragraps with (.)
        char ***temp_list = NULL;                               // initalize temp list to assing related index in document
        while(words != NULL){
            if(sentence_count == 1){                            // if temp list isnt initalized initialize it and assign sentence to correct position
                temp_list = calloc(sizeof(char**), 1);
                char **temp = malloc(sizeof(char**));
                temp = (char**)words;
                sentence_count++;
                temp_list[0] = temp;
                words = strtok(NULL, ".");
            }
            char **mem_str = malloc(sizeof(char**));            // if temp list initialized realloc its size and assign sentences to correct
            mem_str = (char**)words;                            // position in temp list
            temp_list = (char***)realloc(temp_list, sentence_count);
            temp_list[sentence_count-1] = mem_str;
            sentence_count++;
            words = strtok(NULL, ".");
            
        }                                                      // call word organizer for discriminat sentence into words
        for(int subindex = 0; subindex< sentence_count-1; subindex++){
            char *string = (char*)temp_list[subindex];
            temp_list[subindex] = sentence_word_organizer(string);  // asssing word list into related field in templist
        }
        document[index] = temp_list;                                // assing temp list into related field in document
        
    }
    return document;                                                // returns document

}



char* get_input_text(void){
    /* gets input text */
    
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    
    memset(doc, 0, sizeof(doc));
    getchar();
    
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    /*Prints words returned in char *char type*/
    printf("%s", word);
}

void print_sentence(char** sentence) {
    /*Prints sentences returned in char **document type*/
    
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
}




void print_paragraph(char*** paragraph) {
    /*Prints paragraphs returned in char ***document type*/
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}
