#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//* Converts a binary number into decimal and returns it
int binary_to_decimal(int binary){

    int decimalNum = 0;
    int numDigits = 0;
    int tempBinary = binary;
    int currentDigit;
    
    //Numbers used to get the ith digit of our binary number
    int num;
    int num2;

    //Find the number of digits in our binary number
    while(tempBinary != 0){
        numDigits++;
        tempBinary /= 10;
    }

    //Calculate the decimal number from the binary number
    for(int i=0; i<numDigits; i++){
        num = pow(10, i+1);
        num2 = pow(10, i);
        
        currentDigit = ( binary % num )/num2;
        decimalNum += currentDigit * pow(2, i);
    }

    return decimalNum;
}

//* Converts a binary number to hexadecimal and returns it
char* binary_to_hex(int binary){
    //Records the hexadecimal number
    char *realHex = (char*) malloc(50 * sizeof(char));
    char reverseHex[50];

    //Keeps track of how many characters our hexadecimal number has
    int counter = 0;

    //Used to find the digits of the hexadecimal number
    int remainder = 0;
    int decimal = binary_to_decimal(binary);

    //Convert decimal number to hexadecimal(however, chars will be stored in reverse order)
    while(decimal != 0){

        //Find remainder and add it to the reverseHex string
        remainder = decimal%16;
        if(remainder == 10){
            reverseHex[counter] = 'A';
        }
        else if(remainder == 11){
            reverseHex[counter] = 'B';
        }
        else if(remainder == 12){
            reverseHex[counter] = 'C';
        }
        else if(remainder == 13){
            reverseHex[counter] = 'D';
        }
        else if(remainder == 14){
            reverseHex[counter] = 'E';
        }
        else if(remainder == 15){
            reverseHex[counter] = 'F';
        }
        else{
            reverseHex[counter] = (remainder + '0');
        }

        decimal /= 16;
        counter++;
    }

    //Record the real hexadecimal value
    for(int i=0; i<strlen(reverseHex); i++){
        realHex[i] = reverseHex[strlen(reverseHex)-i-1];
    }

    return realHex;
}

//* Converts a binary number to octal and returns it
int binary_to_octal(int binary){

    int octal = 0;

    //Used to find the octal number
    int decimal = binary_to_decimal(binary);
    int remainder = 0;
    
    //Keeps track of the number of digits the octal number has
    int numDigits = 0;

    //Calculate the octal number
    while(decimal != 0){
        remainder = decimal%8;

        octal += (pow(10, numDigits) * remainder);
        numDigits++;
        decimal /= 8;
    }

    return octal;
}

int main(){

    int stayInLoop = 1;
    char choice[25] = "";

    int result;

    char binaryStrChoice[100] = "";
    int binaryNumChoice;
    int notBinaryNumber;

    while(stayInLoop == 1){
        char *resultChar;
        result = 0;

        printf("\n");
        printf("==========================================================\n");
        printf("What would you like to do?\n");
        printf("==========================================================\n");
        printf("Convert binary to decimal (D)\nConvert binary to hexadecimal (H)\nConvert binary to octal (O)\nQuit (Q)\n");
        printf("------------------------------------------\n");
        printf("Enter a choice from the menu (D, H, O, Q): ");
        scanf(" %[^\n]s", choice);
        printf("%s\n", choice);
        
        //Check if user asks to quit or enters invalid input
        if(toupper(choice[0]) == 'Q' && strlen(choice) == 1){
            break;
        }
        else if((toupper(choice[0]) != 'D' && toupper(choice[0]) != 'H' && toupper(choice[0]) != 'O') || strlen(choice) > 1){
            printf("Invalid input, try again.\n");
            continue;
        }

        //Ask for the binary number and calculate the requested format
        printf("Enter a binary number: ");
        scanf(" %s", binaryStrChoice);

        //Check if userinput is a binary number
        notBinaryNumber = 1;
        while(notBinaryNumber == 1){
            for(int i=0; i<strlen(binaryStrChoice); i++){

                //If the current char that we're looking at is not a 
                //1 or 0, then input isn't a binary number
                if( binaryStrChoice[i] != '1' && binaryStrChoice[i] != '0' ){
                    break;
                }
                //If we reach the end of the string, then input is a binary number
                else if(i == strlen(binaryStrChoice)-1){
                    notBinaryNumber = 0;
                }
            }

            //If input isn't a binary number, ask for another input
            if(notBinaryNumber == 1){
                memset(binaryStrChoice, 0, strlen(binaryStrChoice));
                printf("Invalid binary number. Try again: ");
                scanf(" %s", binaryStrChoice);
            }
        }
        binaryNumChoice = atoi(binaryStrChoice);

        //Convert binary input to decimal
        if(toupper(choice[0]) == 'D' && strlen(choice) == 1){
            result = binary_to_decimal(binaryNumChoice);
            printf("Your decimal number from binary is: %d\n", result);
        }
        //Convert binary input to hexadecimal
        else if(toupper(choice[0]) == 'H' && strlen(choice) == 1){
            resultChar = binary_to_hex(binaryNumChoice);
            printf("The Hexadecimal of your binary number is: %s\n", resultChar);
            free(resultChar);
        }
        //Convert binary input to octal
        else if(toupper(choice[0]) == 'O' && strlen(choice) == 1){
            result = binary_to_octal(binaryNumChoice);
            printf("Your octal number from binary is: %d\n", result);
        }
    }

    return 0;
}