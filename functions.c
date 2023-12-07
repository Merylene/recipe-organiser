#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functions.h"
#include "admin.h"

#define PASS "I AM THE BEST" //have to make sure if it is the same hehe 

int select_mode(char const *mode){
    int choice =0;
    
    if (strcmp(mode,"edit")==0){
        choice = EDIT;
    }
    else if (strcmp(mode,"view")==0){
        choice = VIEW;
    }
    else {
        fprintf(stderr,"Usage : ./recipe.exe mode(edit/view)\n");
    }
    return choice;
}

void _choices (void){
    int choice;
    printf("Welcome! What would you like to do ?\n");
    printf("1. Edit recipe\n");
    printf("2. Add new recipe\n");
    scanf("%d",&choice);
    switch (choice){
        case CHANGE:
            edit();
            break;
        case ADD:
            add();
            break;
        default:
            printf("Kindly renter choice\n");
            break;
    }
}

void check_pass(void){
    char *pass =NULL;
    printf("Password :");
    scanf("%s",pass);
    if (strcmp(pass,PASS)== 0){
        _choices();
    }
}