#include <stdio.h>

#include"utils.h"
#include "admin_utils.h"

#define PASS_PATH "./data/pass.txt"

#define MAX_LOOP 10

void check_password_file(void){
    FILE *pass= fopen(PASS_PATH,"r");
    if (pass==NULL){
        printf("first time entering system pass will be created kindly enter your password\n");
        password_change();
    }

    fclose(pass);
}

bool check_pass(char const *pass){
    printf("the location of password is in %s\n",PASS_PATH);
    FILE *setPass =fopen(PASS_PATH,"r");
    if(setPass==NULL){
        fprintf(stderr,"%s does not exist exiting..\n",PASS_PATH);
        exit(EXIT_FAILURE);
    }
    char *storedPass = malloc(sizeof(char)*MAX_LENGTH);
    fscanf(setPass,"%s",storedPass);
    for (int i =0; storedPass[i]!='\0';i++){
        decrypt(storedPass+i,KEY_TEXT[i%strlen(KEY_TEXT)]);
    }
    if (strcmp(pass,storedPass)==0){
        return true;
    }

    free(storedPass);
    return false;
}


void password_change(void){
        FILE *pass =fopen(PASS_PATH,"w+");
        char *p = malloc(sizeof(char)*MAX_LENGTH);
        char *r = malloc(sizeof(char)*MAX_LENGTH);
        for (int i = 0;i<MAX_LOOP; i++){
            scanf("%s",p);
            printf("Please re-enter your password\n");
            scanf("%s",r);
            if (i ==MAX_LOOP-1){
                printf("You have reached the maximum number of times\n");
                exit(EXIT_FAILURE);
            }
            else if (strcmp(p,r)!=0){
                printf("Passwords do not match, try again\n");
                continue;
            }
            else if (strcmp(p,r)==0){
                printf("Proceeding to change password\n");
                break;
            }
        }
        
        for (int j =0; p[j]!='\0';j++){
            encrypt(p+j,KEY_TEXT[j%strlen(KEY_TEXT)]);
        }
        fprintf(pass,"%s",p);
        printf("Saving password\n");

    
        free(p);
        free(r);
        fclose(pass);
}

void file_edit(char const* food){
    char *fileName = malloc(MAX_LENGTH*sizeof(char));
    free(fileName);
}

void new_recipe(void){
    char *new = malloc(MAX_LENGTH*sizeof(char));
    scanf("%s",new);
    bool check = search(new);
    if (check){ // means if check is true
        printf("recipe for %s already exist",new);
        exit(EXIT_FAILURE);
    }
    else if (!check){
        file_edit(new);
    }

    free(new);
}

void edit_recipe(void){

}