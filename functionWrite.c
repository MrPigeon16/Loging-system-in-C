#include "functions.h"


int welcome()
{
	int todo = 0;
	printf("signIn - 0 , login - 1 ");
	scanf("%d", &todo);
	
	while (todo > 1 || todo < 0)
	{
		printf("please choose 0 or 1: ");
		scanf("%d", &todo);
	}
	
	if (todo == LOGIN)
	{
		return LOGIN;
	}
	else
	{
		return SIGNIN;
	}



}


char* signInOption(char* tempInfo)
{
	char* info = NULL;
	int infoLen = strlen(tempInfo);
	
	while (infoLen < MIN_LEN)
	{
		printf("It need to be more them 5 chars! Please choose again\n");
		myFgets(tempInfo, MAX_LEN);
		infoLen = strlen(tempInfo);
	
	}
	info = (char*)malloc(sizeof(char) * (infoLen + ADD_NULL));
	info[infoLen] = '\0';
	strncpy(info, tempInfo, infoLen);


	return info;

}




void myFgets(char* str, int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}



	
