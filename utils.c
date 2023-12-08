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
    return new;
}

/*!
@brief this function is used to encrypt text using a method referenced from Vingere Cipher
        where a single character will be taken in added with the responding input keyText
        eg. letter = 'a' keyText = 'D' 
        the values will be indicated as an int to be calculated as char has a limit of 128 which will affect
        if letter+keyText is more than ASCII_COUNT in the example above the values will be over 128 hence 
        wraping around with letter+keyText%ASCII_COUNT
@param  char *letter = takes in the exact address of the character and edit it directly 
        char keyText = takes in the encoding key to add with the letter
@return NULL
*//*______________________________________________________________*/
void encrypt (char *letter , char keyText)
{
    char temp = *letter;
    int expected = temp +keyText;
    if (expected > ASCII_COUNT)
    {
        *letter = (char)(expected%ASCII_COUNT);
    }
    else 
    {
        *letter = (char)expected;
    }
}


/*!
@brief this function is used to decrypt text using a method referenced from Vingere Cipher
        where a single character will be taken in subt with the responding input keyText
        eg. letter = 'a' keyText = 'D' 
        the values will be indicated as an int to be calculated as char has a limit of 128 and positive which will affect
        if letter-keyText is less than 0 ASCII_COUNT will add the sum of it to ensure that it goes out of 
@param  char *letter = takes in the exact address of the character and edit it directly 
        char keyText = takes in the encoding key to add with the letter
@return NULL
*//*______________________________________________________________*/
void decrypt (char* letter , char keyText)
{
    char temp = *letter;
    int expected = temp - keyText;
    if (expected<0)
    {
        *letter = (char)(ASCII_COUNT + expected);
    }
    else
    {
        *letter = (char)expected;
    }
        
}