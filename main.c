#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"


int main (int argc, char *argv[]){
    if (argc <2){
        fprintf(stderr,"Usage : ./recipe.exe mode(edit/view)\n");
        return 0;
    }

    //used to check if the correct usage is used
    int mode = select_mode(argv[1]);
    if (mode == 0){
        return 0;
    }
    if (mode == VIEW){
        printf("view\n");
        //move on to the site where it prompts for the file that they would like to check
        
    }
    if (mode == EDIT){
        check_pass(); //check password
    }

    return 0;
}