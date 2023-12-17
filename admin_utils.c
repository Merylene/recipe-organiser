#include <stdio.h>

#include"utils.h"
#include "admin_utils.h"

#define PASS_TXT "pass.txt"

bool check_pass(char const *pass){
    char *passPath = malloc(sizeof(char)*MAX_LENGTH);
    strcpy(passPath,DATA_PATH);
    strcat(passPath,PASS_TXT);
    printf("the location of password is in %s",passPath);
    FILE *setPass =fopen(passPath,"r");
    if(setPass==NULL){
        fprintf(stderr,"%s does not exist will proceed to create a file\n",passPath);
        password_change();
    }
    char *storedPass = malloc(sizeof(char)*MAX_LENGTH);
    fscanf(setPass,"%s",storedPass);
    for (int i =0; storedPass[i]!='\0';i++){
        decrypt(storedPass+i,KEY_TEXT[i%strlen(KEY_TEXT)]);
    }
    if (strcmp(pass,storedPass)==0){
        return true;
    }

    free(passPath);
    free(storedPass);
    return false;
}


void password_change(void){

}

void new_recipe(void){

}

void edit_recipe(void){

}