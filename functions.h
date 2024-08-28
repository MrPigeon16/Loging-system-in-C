#ifndef functions
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define GOOD 1
#define BAD 0

#define LOGIN 1
#define SIGNIN 0

#define MIN_LEN 5
#define MAX_LEN 16

#define ADD_NULL 1


#define STR_MAX_LEN 100




/*
function will check what the user want to do
input: none
ouput: 1 - login, 0 - signIn
*/
int welcome();

void myFgets(char* str, int n);

char* signInOption(char* tempInfo);

int goodSignInput(char* input, int InfoLen);


#endif // !functions
