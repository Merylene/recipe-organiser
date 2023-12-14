#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILE_TYPE ".txt"
#define MAX_LENGTH 254 //maximum length of the string name for a file be 254 
#define ASCII_COUNT 128 //basic set of ASCII count is 0-127
#define DATA_PATH "./data/" //used for easy reference in the future
#define MENU "./data/menu.txt" // used to make this a constant

//used to check if it is agreeable
enum { NO = 1,YES };

//this function is used to change every single character in a string to lower case and return
char *change_case(char const *str);

// used to search if the string is available in the program
bool search (char const *name);

//used to encrypt and decrypt text
void encrypt (char *letter , char keyText);
void decrypt (char *letter , char keyText);

//used to create data foller directory
void create_dir(char const* directory_name);

//used to lower the case of a char
void __tolower(char *str);