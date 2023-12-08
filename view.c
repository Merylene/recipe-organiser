#include "view.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>



void view (void){
    char *food = (char *)malloc(sizeof(char)*MAX_LENGTH);
    //check what file the user would like to view
    scanf("%s",food);
    bool exist = search(food);
    if (exist ==false){
        fprintf(stdout,"this recipe %s has yet to be added into the collection\n",food);

    }

    free(food);
}
