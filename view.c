#include "view.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



void view (void){
    char *food = (char *)malloc(sizeof(char)*MAX_LENGTH);
    //check what file the user would like to view
    printf("What food would you like to have ?");
    scanf("%s",food);
    printf("food is :%s\n",food);
    bool exist = search(food);
    if (exist ==false){
        fprintf(stdout,"this recipe %s has yet to be added into the collection\n",food);

    }
    else if (exist == true){
        fprintf(stdout,"Would you like to view the file?");
    }
    free(food);
}
