#pragma once
#ifndef fileHandler
#define FILE_HANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FAILED_ALLOC "Faild to allocate memory :("

#define ADD_NULL 1


typedef struct userInfo
{
	char* username;
	char* passwordHashed;
	unsigned int hashIndex;

}userInfo;


typedef struct userNode
{
	userInfo* userData;
	struct userNode* next_user;
	 
}userNode;


userNode* createNewUser(char* username, char* password, int hashIndex);

void insertAtEnd(userNode** head, userNode* newNode);



#endif // !fileHandler
