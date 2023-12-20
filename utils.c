#include "utils.h"
#include <sys/stat.h>
//#include <io.h>


void __tolower(char *str){
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
    __tolower(new);
    return new;
}


bool search (char const *name){
    // FILE *menu =fopen(MENU,"a+");// used a+ for reading and appending of data
    // if (menu ==NULL){
    //     fprintf(stderr,"%s not found\n",MENU);
    //     exit(EXIT_FAILURE); //EXIT FAILURE = 1
    // }
    // printf("%s\n",name);
    // char *check = malloc(MAX_LENGTH*sizeof(char));
    // while (fscanf(menu,"%s",check)==1){
    //     if (strcmp(check,name)==0){
    //         return true;
    //     }
    // }
    // free(check);
    // fclose(menu);
    char *file_name = malloc(MAX_LENGTH*sizeof(char));
    strcpy(file_name,DATA_PATH);
    printf("file_path is %s\n",file_name);
    strcat(file_name,name);
    printf("file_name is %s\n",file_name);
    strcat(file_name,FILE_TYPE);
    printf("file_name is now %s\n",file_name);
    FILE *f =fopen(file_name, "r");
    if (f !=NULL){
        fprintf(stdout,"%s does exist!!\n",name);
        fclose(f);
        return true;
    }
    return false;
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
void decrypt (char *letter , char keyText)
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

//used to create a directory/file
void create_dir(char const* directory_name){
        struct stat st = {0};

    if (stat(directory_name, &st) == -1) { //stat is used to get the status of the directory
        if (mkdir(directory_name,0700) == -1) {
            fprintf(stderr,"Unable to create directory %s\n",directory_name);//perror = fprintf(stderr, blah blah)
            exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stdout,"Directory %s already exists\n",directory_name);
    }
}

void read_data(char const *food){
    char *foodFile = malloc(MAX_LENGTH*sizeof(char));
    strcpy(foodFile,DATA_PATH);
    strcat(foodFile,food);
    FILE *f =fopen(foodFile,"r");
    if (f==NULL){
        fprintf(stderr,"%s's DATA PATH :%s cannot be opened.\n",food,foodFile);
        exit(EXIT_FAILURE);
    }
    char *str = malloc(sizeof(char)*MAX_LENGTH);
    while (fscanf(f,"%s",str)==1){
        //printf("decryption\n");
        for (int i=0;str[i]!='\0';i++){
            //fprintf(stdout,"before : %c\n",str[i]);
            decrypt(str+i,KEY_TEXT[i%strlen(KEY_TEXT)]);
            //fprintf(stdout,"after : %c\n",str[i]);
        }
        fprintf(stdout,"%s\n",str);
        // printf("encryption\n");
        // for (int i=0;str[i]!='\0';i++){
        //     //fprintf(stdout,"before : %c\n",str[i]);
        //     encrypt(str+i,KEY_TEXT[i%strlen(KEY_TEXT)]);
        //     //fprintf(stdout,"after : %c\n",str[i]);
        // }
        // fprintf(stdout,"%s\n",str);
    }

    free(str);
    free(foodFile);
}