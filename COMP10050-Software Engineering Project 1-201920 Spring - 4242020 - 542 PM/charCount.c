#include <stdio.h>

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#define STR_NUM 5
#define MAX_LEN 80
#define CHAR_NUM 26

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
 * This function counts the characters in the sentences stored in InputStrings
 * and stores them in the 2D array charCount
 *
 */
void countCharacters(char inputStrings [][MAX_LEN], int charCount[][CHAR_NUM]) {
    char lowerString[MAX_LEN];

    //initialize charCount
    for(int i =0; i < STR_NUM; i++)
        for(int j =0;  j< CHAR_NUM; j++)
            charCount[i][j] = 0;

    for(int i =0; i< STR_NUM; i++){
        //converts a string into lower case letters
        toLower(inputStrings[i], lowerString);
        for (int j =0; j < strlen(inputStrings[i]); j++){
            //increments the cell in char count associated with the corresponding character
            switch(lowerString[j]){
                case 'a': charCount[i][0]++;
                            break;
                case 'b': charCount[i][1]++;
                            break;
                case 'c': charCount[i][2]++;
                    break;
                case 'd': charCount[i][3]++;
                    break;
                case 'e': charCount[i][4]++;
                    break;
                case 'f': charCount[i][5]++;
                    break;
                case 'g': charCount[i][6]++;
                    break;
                case 'h': charCount[i][7]++;
                    break;
                case 'i': charCount[i][8]++;
                    break;
                case 'j': charCount[i][9]++;
                    break;
                case 'k': charCount[i][10]++;
                    break;
                case 'l': charCount[i][11]++;
                    break;
                case 'm': charCount[i][12]++;
                    break;
                case 'n': charCount[i][13]++;
                    break;
                case 'o': charCount[i][14]++;
                    break;
                case 'p': charCount[i][15]++;
                    break;
                case 'q': charCount[i][16]++;
                    break;
                case 'r': charCount[i][17]++;
                    break;
                case 's': charCount[i][18]++;
                    break;
                case 't': charCount[i][19]++;
                    break;
                case 'u': charCount[i][20]++;
                    break;
                case 'v': charCount[i][21]++;
                    break;
                case 'w': charCount[i][22]++;
                    break;
                case 'x': charCount[i][23]++;
                    break;
                case 'y': charCount[i][24]++;
                    break;
                case 'z': charCount[i][25]++;
                    break;
                default: break;

            }
        }

    }


}



/*
 * This function prints the number of characters
 * stored in the array charCount
 */
void printCharCount(int charCount [][CHAR_NUM]) {
    printf("The number of chanracters is:\n");
    for (int i = 0; i < STR_NUM; i++) {
        for (int j = 0; j < CHAR_NUM; j++)
            printf("%d ", charCount[i][j]);
    printf("\n");
    }
}

int main() {
    //2D array storing the strings provided as input
    char inputStrings[STR_NUM][MAX_LEN];
    //2D array storing information about the number of characters
    int charCount[STR_NUM][CHAR_NUM];

    insertStrings(inputStrings);
    countCharacters(inputStrings, charCount);
    printCharCount(charCount);
}
