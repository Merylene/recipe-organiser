#include <stdio.h>
#include <stdbool.h>

#include "utils.h"
#include "view.h"
#include "admin_utils.h"

enum { PASS_CHANGE =1 ,ADD_NEW,EDIT_RECIPE, VIEW};

void edit (void){
    char *pass = malloc(sizeof(char)*MAX_LENGTH);
    bool correctPass;
    check_password_file();
    do{
        fprintf(stdout,"Please enter Password :");
        fgets(pass, MAX_LENGTH, stdin);
        pass[strcspn(pass, "\n")] = '\0';  // Remove the newline character
        // scanf("%s",pass);
        correctPass = check_pass(pass);
        if (correctPass){ //if correctPass == true 
            fprintf(stdout,"Correct Password! Now entering into the system!\n");
            int selection =0;
            do {
                fprintf(stdout,"(1 = Change Password, 2 = Add New Recipes, 3 = Edit Stored Recipe, 4 = View Recipes)\n");
                scanf("%d",&selection);
                if (selection == PASS_CHANGE){
                    printf("What password would you like to change to? \n");
                    password_change();
                }
                else if (selection == ADD_NEW){
                    printf("Entering to Adding new Recipe \n");
                    new_recipe();
                }
                else if (selection == EDIT_RECIPE){
                    edit_recipe();
                }
                else if (selection == VIEW){
                    view();
                }
                else{
                    printf("option %d is not available kindly reselect",selection);
                }
            } while (selection<1 || selection>VIEW);

        }
    } while (!correctPass); //ensures that the program runs at least once.


    free(pass);
}