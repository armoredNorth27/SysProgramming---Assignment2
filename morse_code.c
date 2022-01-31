#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Transforms an input letter into its morse code
char* letter_to_morse(char *letter){
    //Convert input letter to capital
    char uppercaseLetter = toupper(*letter);

    //Return the morse code version of the input letter
         if(uppercaseLetter == 'A'){return ".-";}
    else if(uppercaseLetter == 'B'){return "-...";}
    else if(uppercaseLetter == 'C'){return "-.-.";}
    else if(uppercaseLetter == 'D'){return "-..";}
    else if(uppercaseLetter == 'E'){return ".";}
    else if(uppercaseLetter == 'F'){return "..-.";}
    else if(uppercaseLetter == 'G'){return "--.";}
    else if(uppercaseLetter == 'H'){return "....";}
    else if(uppercaseLetter == 'I'){return "..";}
    else if(uppercaseLetter == 'J'){return ".---";}
    else if(uppercaseLetter == 'K'){return "-.-";}
    else if(uppercaseLetter == 'L'){return ".-..";}
    else if(uppercaseLetter == 'M'){return "--";}
    else if(uppercaseLetter == 'N'){return "-.";}
    else if(uppercaseLetter == 'O'){return "---";}
    else if(uppercaseLetter == 'P'){return ".--.";}
    else if(uppercaseLetter == 'Q'){return "--.-";}
    else if(uppercaseLetter == 'R'){return ".-.";}
    else if(uppercaseLetter == 'S'){return "...";}
    else if(uppercaseLetter == 'T'){return "-";}
    else if(uppercaseLetter == 'U'){return "..-";}
    else if(uppercaseLetter == 'V'){return "...-";}
    else if(uppercaseLetter == 'W'){return ".--";}
    else if(uppercaseLetter == 'X'){return "-..-";}
    else if(uppercaseLetter == 'Y'){return "-.--";}
    else if(uppercaseLetter == 'Z'){return "--..";}
    else if(uppercaseLetter == ' '){return " ";}
    else{return "?";} 
}

//Tranforms the morse code of a letter into a letter of the alphabet
char* morse_to_letter(char *morseLetter){
    //Return the letter of the alphabet that 
    //corresponds to the input morse code
         if( strcmp(morseLetter, ".-") == 0 ){return "a";}
    else if( strcmp(morseLetter, "-...") == 0 ){return "b";}
    else if( strcmp(morseLetter, "-.-.") == 0 ){return "c";}
    else if( strcmp(morseLetter, "-..") == 0 ){return "d";}
    else if( strcmp(morseLetter, ".") == 0 ){return "e";}
    else if( strcmp(morseLetter, "..-.") == 0 ){return "f";}
    else if( strcmp(morseLetter, "--.") == 0 ){return "g";}
    else if( strcmp(morseLetter, "....") == 0 ){return "h";}
    else if( strcmp(morseLetter, "..") == 0 ){return "i";}
    else if( strcmp(morseLetter, ".---") == 0 ){return "j";}
    else if( strcmp(morseLetter, "-.-") == 0 ){return "k";}
    else if( strcmp(morseLetter, ".-..") == 0 ){return "l";}
    else if( strcmp(morseLetter, "--") == 0 ){return "m";}
    else if( strcmp(morseLetter, "-.") == 0 ){return "n";}
    else if( strcmp(morseLetter, "---") == 0 ){return "o";}
    else if( strcmp(morseLetter, ".--.") == 0 ){return "p";}
    else if( strcmp(morseLetter, "--.-") == 0 ){return "q";}
    else if( strcmp(morseLetter, ".-.") == 0 ){return "r";}
    else if( strcmp(morseLetter, "...") == 0 ){return "s";}
    else if( strcmp(morseLetter, "-") == 0 ){return "t";}
    else if( strcmp(morseLetter, "..-") == 0 ){return "u";}
    else if( strcmp(morseLetter, "...-") == 0 ){return "v";}
    else if( strcmp(morseLetter, ".--") == 0 ){return "w";}
    else if( strcmp(morseLetter, "-..-") == 0 ){return "x";}
    else if( strcmp(morseLetter, "-.--") == 0 ){return "y";}
    else if( strcmp(morseLetter, "--..") == 0 ){return "z";}
    else if( strcmp(morseLetter, " ") == 0 ){return " ";}
    else {return "?";}
}

//Tranforms an english sentence into morse code
char* text_to_morse(char *sentence, int sentence_length){
    char convertedSentence[400] = {""};
    char *convertedSentencePtr = &convertedSentence[0];

    //Convert sentence to morse code and concatenate it with convertedSentence
    for(int i=0; i<sentence_length; i++){
        strcat(convertedSentence, letter_to_morse( &sentence[i] ));
        strcat(convertedSentence, " ");
    }

    return convertedSentencePtr;
}

//Tranforms a sentence of morse code into english
char* morse_to_text(char *sentence, int sentence_length){
    char convertedSentence[500] = "";
    char *convertedSentencePtr = &convertedSentence[0];

    char singleWord[10] = "";
    int counter = 0;

    //Converts the input sentence from morse into english
    for(int i=0; i<sentence_length; i++){
        //If the current character isn't a space, add it to the singleWord string
        if( sentence[i] != ' '){
            singleWord[counter] = sentence[i];
            counter++;
        }

        //If we encounter a triple space, then add the singleWord to the 
        //english sentence along with a space and reset the english word
        else if( (sentence[i] == ' ') && (sentence[i+1] == ' ') && (sentence[i+2] == ' ') && (i != sentence_length-3) ){
            //Add letter to translated sentence
            strcat(convertedSentence, morse_to_letter( &singleWord[0] ));
            strcat(convertedSentence, " ");

            //Reset the variable that holds the current word
            memset(singleWord, 0, strlen(singleWord));
            counter = 0;

            i += 2;
        }

        //If the current character is a space, then add singleWord to the
        //english sentence and reset the english word
        else if( sentence[i] == ' ' ){
            //Add letter to translated sentence
            strcat(convertedSentence, morse_to_letter( &singleWord[0] ));
            //Reset the variable that holds the current word
            memset(singleWord, 0, strlen(singleWord));
            counter = 0;
        }

        //If we've reached the end of the input string, add the last
        //singleWord to the english sentence
        if( i == sentence_length-1 ){
            //Add letter to translated sentence
            strcat(convertedSentence, morse_to_letter( &singleWord[0] ));
            //Reset the variable that holds the current word
            memset(singleWord, 0, strlen(singleWord));
            counter = 0;
        }
    }

    return convertedSentencePtr;
}


int main(){

    char input;
    int true = 1;

    char userInput[250] = {"0"};
    //Executes the whole program
    while(true == 1){
        char *conversion;
        int inputLength = 0;

        //Ask for user input
        printf("==========================================================\n");
        printf("What would you like to do?\n");
        printf("==========================================================\n");
        printf("(M) - Convert to morse code \n(T) - Convert to text \n(Q) - Quit\n");
        printf("------------------------------------------\n");
        printf("Enter a choice from the menu (M, T, Q): ");
        scanf(" %c", &input); //! Need the space in front of %c to avoid looping twice

        //Encode message
        if( toupper(input) == 'M' ){
            printf("Enter the message you would like to encrypt:\n");
            scanf(" %[^\n]s\n", userInput);
            inputLength = strlen(userInput);

            conversion = text_to_morse(userInput, inputLength);
            printf("%s\n", conversion);
        }

        //Decode message
        else if( toupper(input) == 'T' ){
            printf("Enter the message you would like to decrypt:\n");
            scanf(" %[^\n]s\n", userInput);
            inputLength = strlen(userInput);

            conversion = morse_to_text(userInput, inputLength);
            printf("%s\n", conversion);
        }

        //Quit program
        else if( toupper(input) == 'Q' ){
            true = 0;
        }

        //Invalid input. Ask again
        else{
            printf("Invalid input, try again\n");
        }

        memset(userInput, 0, strlen(userInput));
        printf("\n");
    }

    return 0;
}