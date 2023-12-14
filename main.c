 #include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "view.h"
#include "admin.h"


int main (int argc, char *argv[]){
    if (argc<2){
        fprintf(stderr,"Usage: ./recipe.exe mode(edit/view)\n");
        return 0;
    }

    char *mode = change_case(argv[1]); //changes the mode selection to a lower case

    create_dir("data");

    if (strcmp(mode,"view")==0){
        fprintf(stdout,"Currently in Viewing mode!\n");
        view();
    }
    else if (strcmp(mode,"edit")==0){
        fprintf(stdout,"Currently in Editing mode\n");
        edit();
    }
    else {
        fprintf(stderr,"Usage: ./recipe.exe mode(edit/view)\n");
        return 0;
    }
    free(mode);
    return 0;
}