#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#define STR_NUM 5
#define MAX_LEN 80

/*
 * This function asks the user to input 5 strings
 * and writes them in the array "inputStrings"
 */
void insertStrings(char inputStrings [][MAX_LEN]){
    printf("Insert %d Strings as input\n", STR_NUM);
    for(int i =0; i < STR_NUM; i++){
        printf("String %d: ", i+1);

        //reads strings from the standard input (stdin)
        fgets(inputStrings[i],MAX_LEN, stdin);

        //removes the carriage return character from the input strings
        if(inputStrings[i][strlen(inputStrings[i])-1] == '\n'){
            inputStrings[i][strlen(inputStrings[i])-1] = '\0';
        }
    }
}

/*
 * This function converts inputString in a string having all
 * lowercase letters and copies the result in lowerString
 */
void toLower(char inputString[], char lowerString[]){

    for(int i = 0; i< strlen(inputString); i++){
        // function to lower converts a character in its lower case version
        lowerString[i] = tolower(inputString[i]);
    }
}



/*
 * This function sorts an input array using the insertion sort algorithm
 *
 */
void insertionSort(char inputStrings [][MAX_LEN]) {
    int i, j;

    char swap[MAX_LEN], lowerString1[MAX_LEN], lowerString2[MAX_LEN];
    for (i = 1; i < STR_NUM; i++) {
        j = i;

        // before comparing strings at positions j and j-1
        // it is necessary to convert them into lowercase strings
        toLower(inputStrings[j], lowerString1);
        toLower(inputStrings[j-1], lowerString2);

        while (j > 0 && strcmp(lowerString1, lowerString2) < 0) {
            // swapping of strings is performed using strcpy
            strcpy(swap, inputStrings[j]);
            strcpy(inputStrings[j], inputStrings[j - 1]);
            strcpy(inputStrings[j - 1], swap);
            j--;
            toLower(inputStrings[j], lowerString1);
            toLower(inputStrings[j-1], lowerString2);
        }
    }
}



/*
 * This function prints a set of strings provided as input
 */
    void printStrings(char inputStrings [][MAX_LEN]){
        printf("The list of ordered strings is:\n");
        for(int i =0; i< STR_NUM; i++)
            printf("%s\n",inputStrings[i] );
    }


int main() {
    char inputStrings[STR_NUM][MAX_LEN];
    insertStrings(inputStrings);
    insertionSort(inputStrings);
    printStrings(inputStrings);

}
