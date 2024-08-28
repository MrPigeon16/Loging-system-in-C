#include "functions.h"
#include "fileHandler.h"
#include "hashFunction.h"
int main(void)
{
	char tempUsername[STR_MAX_LEN] = { 0 };
	char tempPassword[STR_MAX_LEN] = { 0 };

	char* realUsername = NULL;
	char* realPassword = NULL;
	unsigned long long int hashedPassword = 0;
	int option = welcome();
	getchar();
	if (option == LOGIN)
	{
		printf("You want to login!\n");
	}

	else if (option == SIGNIN)
	{
		
		printf("You have choose to make a new user!\n");
		myFgets(tempUsername,STR_MAX_LEN);
		realUsername = signInOption(tempUsername);
		printf("Hello! %s Now please choose a password for you user!\n", realUsername);
		myFgets(tempPassword, STR_MAX_LEN);
		realPassword = signInOption(tempPassword);
		
		
		hashedPassword = hashFunction(realUsername, realPassword);
		printf("Your info hased password - %llu", hashedPassword);
		


		
		free(realPassword);
		free(realUsername);
	}
	else
	{
		printf("Something went wrong!\n");
	}
	return 0;
}

	
