#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICT "dict.txt"
#define FILE_TYPE ".txt"

// bool _check_file(char const *file){
//     // FILE *dictionary = fopen(DICT,"+r");
//     // if (!dictionary){
//     //     printf("dict.txt was not read sucessfully\n");
//     //     exit(1);
//     // }
//     // while (fgets())
//     return true;
// }

void edit(void){

}

void add(void){
    char *fileName =NULL;
    scanf("%s",fileName);
    //need to check if file name is available
    strcat(fileName,FILE_TYPE);
    printf("%s",fileName);
    //bool isFile = _check_file(fileName);
}