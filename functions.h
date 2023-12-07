
//startup choices
enum {
EDIT =1,
VIEW
};

//admin choices
enum {
    CHANGE =1,
    ADD
};

int select_mode(char const *mode);
void check_pass(void);