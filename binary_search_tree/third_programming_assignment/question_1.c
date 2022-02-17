#include<stdio.h> 
#include<stdlib.h>
int main(){
    printf("Hi welcome to my program :)\n");//greeting
    char yourEnvVar[50];  //array for storing the environment variable entered by user
    printf("Enter the variable you want to create : ");
    scanf("%s",yourEnvVar);  //taking environment variable as input from user
    char *checkenvVar = getenv(yourEnvVar);  //checkimg whether this variable already exist. if it exists already then this function will returns the value of that variable else it will return null pointer.
    char value[50];  //for storing new variable 
    if(checkenvVar==NULL){ //checking for pre existance of variable
        printf("Enter the value you want to assign to your environment variable : ");
        scanf("%s",value);   //taking value of the environment variable variable to assign to it as it doesn't already exists.
        int success = setenv(yourEnvVar,value,0);   //setting the environment's variable value. If succesfully assigned then it will returns 0 otherwise -1 as failure sign.
        if(success==0){  //assignment of variable is completed 
            printf("congrats, vartable created Successfully !\n");
        }
        else{//assignment of variable could not be completed 
            printf("sorry variable could not be created please try later\n");
        }
    }
    else{ // when environment variable exists already
        printf(" Environment variable you entered already exists. Would you ike to replace that with any other variable (y/n) OR (Y/N): ");
        char choice;
        scanf(" %c",&choice);
        if(choice=='y' || choice=='Y'){  //when user want to replece the variable.
            printf("Environment variable you entered is (%s), Are you sure you want to replace its value (y/n) OR (Y/N) : ",getenv(yourEnvVar));
            scanf(" %c",&choice);  // again taking choice as to make sure that user doesn't make a mistake.
            if(choice=='y' || choice=='Y'){//after confirmation
                printf("Enter the value you want to replace with your current environment variable value : ");
                scanf("%s",value);  //taking new variable for replacing
                int success = setenv(yourEnvVar,value,1);  // if succesfully updated then it returns 0 otherwise -1
                if(success==0){// variable created successfully
                    printf("congrats, vartable created Successfully !\n");
                }
                else{// could not update variable
                    printf("sorry variable could not be created please try later\n");
                }
            }
            else{// if choice is N or n
                printf("Thank you for using this program\n");
            }   
        }
        else{//if choice is N or n
            printf("So, Bye then :(\n");
        }
    }
    return 0;
}
