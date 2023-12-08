#include "utils.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void _tolower(char *str){
    while (*str!='\0'){
        if (*str>'A'&&*str<'Z'){
            *str+='a'-'A';
        }
        str++;
    }
}

char *change_case(char const *str){

    char *new = (char*)malloc((strlen(str)+1)*sizeof(char));
    if (new==NULL){
        fprintf(stderr,"Memory allocation for line,%d and file,%s failed...",__LINE__,__FILE__);
        exit(1);
    }
    strcpy(new,str);
    _tolower(new);
    printf("%s\n",new);
    return new;
}