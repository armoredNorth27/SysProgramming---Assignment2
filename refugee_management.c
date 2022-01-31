#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//* Adds a new user to the database
void add_user(char **users, int num_users, char* userid, char *name, char *profession, char *age){

    //Allocate memory for the user that we're going to store
    users[num_users] = (char*) malloc(50 * sizeof(char));
    
    //Exit the program is memory couldn't be allocated correctly
    if(users[num_users] == NULL){
        printf("Memory allocation error\n");
        exit(0);
    }
    
    //Populate the newest place in the users array with the new user
    strcat(users[num_users], &userid[0]);
    strcat(users[num_users], "&");
    strcat(users[num_users], &age[0]);
    strcat(users[num_users], "&");
    strcat(users[num_users], &name[0]);
    strcat(users[num_users], "&");
    strcat(users[num_users], &profession[0]);

}

//* Used to display all users inside of the database
void display_users(char **users, int num_users){

    //Cycles through all users
    for(int i=0; i<num_users; i++){

        //Cycles through all characters of user info string
        for(int j=0; j<strlen( *(users+i) ); j++){
            if((*(users+i))[j] != '&'){
                printf("%c", (*(users+i))[j]);
            }
            else{
                printf(" | ");
            }
        }

        //Separates users
        printf("\n");

    }

}

//* Returns the user with the specified id
char* display_user(char **users, int num_users, char *userid){

    //Cycles through all users
    for(int i=0; i<num_users; i++){

        //Cycles through all numbers in the requested id and compare
        //them to the numbers in the user's id stored in the database
        for(int j=0; j<strlen(userid); j++){

            //Current numbers don't match -> id's don't match. Move onto next user
            if((*(users+i))[j] != userid[j]){
                break;
            }

            //If all numbers match, then id is correct. Return user
            else if( ( j == strlen(userid)-1 ) && ( (*(users+i))[j+1] == '&' ) ){
                return *(users+i);
            }

        }

    }

    //We haven't found the user, so return not found
    return "User not found.";

}

//* Returns the youngest user in the database
char* youngest_user(char **users, int num_users){

    //If there are no users, return nothing
    if(num_users == 0){
        return "Database is empty.";
    }

    //If there's only 1 user, return that user
    else if(num_users == 1){
        return *users;
    }

    //If there's more than 1 user, find the youngest
    else{
        int ampAmount = 0;
        //Keeps track of which index in the database has the
        //youngest user
        int youngestUserIndex = 0;

        //Used to keep track of the current user's age
        char currentCharAge[50] = "";
        int currentNumAge = -1;

        //Keeps track of the youngest user's age
        char youngestCharAge[50] = "";
        int youngestNumAge = -1;

        //Set the youngest user to be the first user in the database
        for(int i=0; i<strlen(*users); i++){

            //Keeps track of how many & we've hit in order to know
            //when we're accessing id, or age, or name, etc
            if( (*users)[i] == '&' ){
                ampAmount++;
            }

            //If we've hit the first &, then the next set of chars
            //represent the age of the user, so record these chars
            if(ampAmount == 1){
                if((*users)[i] != '&'){
                    strcat(youngestCharAge, &(*users)[i]);
                }
            }

            //We're done looking at the age of the user, so stop looking
            if(ampAmount == 2){
                break;
            }
        }
        //Record the youngest age in the database. Start with the age of
        //the first user in the database and update from there
        youngestNumAge = atoi(youngestCharAge);

        //Cycles through all users
        for(int i=1; i<num_users; i++){
            ampAmount = 0;

            //Cycles through all characters of user info string
            for(int j=0; j<strlen( *(users+i) ); j++){
                //Keeps track of how many & we've hit in order to know
                //when we're accessing id, or age, or name, etc
                if( (*(users+i))[j] == '&' ){
                    ampAmount++;
                }

                //If we've hit the first &, then the next set of chars
                //represent the age of the user, so record these chars
                if(ampAmount == 1){
                    if((*(users+i))[j] != '&'){
                        strcat(currentCharAge, &(*(users+i))[j]);
                    }
                }

                //Once we've hit the 2nd &, then we're done recording
                //the age. Convert current age to an integer and compare
                //to the youngest user's age.
                if(ampAmount == 2){
                    currentNumAge = atoi(currentCharAge);

                    //If the current user is younger than the recorded youngest,
                    //then set the recorded youngest to be equal to the current user
                    if(currentNumAge < youngestNumAge){
                        youngestNumAge = currentNumAge;
                        youngestUserIndex = i;
                    }
                    break;
                }
            }
            //Reset currentCharAge so we don't remember the previous user's current age
            memset(currentCharAge, 0, strlen(currentCharAge));
        }

        //Clear both strings for the next time this function gets called
        memset(youngestCharAge, 0, strlen(youngestCharAge));

        return *(users+youngestUserIndex);
    }

}


int main(){

    int true = 1;
    char input;

    //Holds all the users
    char* users[100] = {NULL};

    int num_users = 0;
    //Temporary variables for the user's information
    char userid[100] = "";
    char name[50] = "";
    char occupation[50] = "";
    char age[100] = "";

    while(true == 1){

        printf("\n");
        printf("==========================================================\n");
        printf("What would you like to do?\n");
        printf("==========================================================\n");
        printf("Enter information (E)\nDisplay information (A)\nDisplay information for an individual (I)\nShow youngest person (Y)\nQuit (Q)\n");
        printf("------------------------------------------\n");
        printf("Enter a choice from the menu (E, A, I, Y, Q): ");
        scanf(" %c", &input);

        //Enter a new user
        if(toupper(input) == 'E'){
            printf("\n");

            //Get the new user's information
            //=========================================//
            printf("Enter the userid: ");
            scanf(" %[^\n]s", userid);

            printf("Enter the age: ");
            scanf(" %[^\n]s", age);

            printf("Enter the name: ");
            scanf(" %[^\n]s", name);
            
            printf("Enter the occupation: ");
            scanf(" %[^\n]s", occupation);
            //=========================================//

            //Add the user to the database
            add_user(users, num_users, &userid[0], &name[0], &occupation[0], &age[0]);

            num_users++;
        }

        //Display userid, age, name, and profession for all users
        else if(toupper(input) == 'A'){

            printf("\n");
            display_users(users, num_users);

        }

        //Display userid, name, profession, and age for a specific user
        else if(toupper(input) == 'I'){

            //Stores result of display_user
            char *result = NULL;

            //Grabs the ID that the user wants to search for
            char searchingId[50] = "";
            printf("\n");
            printf("Enter the userid: ");
            scanf("%s", searchingId);

            //Searches for id
            printf("\n");

            result = display_user(users, num_users, searchingId);
            
            //If id isn't found, then inform the user
            if(strcmp(result, "User not found.") == 0){
                printf("%s", result);
            }

            //If id is found, print out the user's information
            else{
                display_users(&result, 1);
            }

            printf("\n");

        }

        //Display userid, name, profession, age for youngest user
        else if(toupper(input) == 'Y'){

            //Store result of youngest_user
            char *youngResult = NULL;

            youngResult = youngest_user(users, num_users);

            printf("\n");
            if( strcmp(youngResult, "Database is empty.") == 0 ){
                printf("%s", youngResult);
            }
            else{
                display_users(&youngResult, 1);
            }

        }

        //Quit the program
        else if(toupper(input) == 'Q'){
            true = 0;
        }
        
        //Invalid input, ask for another
        else{
            printf("Invalid input, try again.\n");
        }

        //Reset all temporary variable arrays
        memset(userid, 0, strlen(userid));
        memset(age, 0, strlen(age));
        memset(name, 0, strlen(name));
        memset(occupation, 0, strlen(occupation));

    }

    //Free manually allocated memory of each pointer inside the
    //array of pointers
    for(int i=0; i<num_users; i++){
        free( (users[i]) );
    }

    return 0;
}