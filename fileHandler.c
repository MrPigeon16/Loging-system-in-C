#include "fileHandler.h"


userNode* createNewUser(char* username, char* password, int hashIndex)
{
	userNode* newUser = (userNode*)malloc(sizeof(userNode));
	if (!newUser)
	{
		printf("%s", FAILED_ALLOC);
		return NULL;
	}
	newUser->userData = (userInfo*)malloc(sizeof(userInfo));
	if (!newUser->userData)
	{
		printf("%s", FAILED_ALLOC);
		free(newUser);
		return NULL;
	}
	
	newUser->userData->username = (char*)malloc(sizeof(char) * (strlen(username) + ADD_NULL));
	if (!newUser->userData->username)
	{
		printf("%s", FAILED_ALLOC);
		free(newUser->userData);
		free(newUser);
	}
	newUser->userData->passwordHashed = (char*)malloc(sizeof(char) * (strlen(password) + ADD_NULL));
	if (!newUser->userData->passwordHashed)
	{
		printf("%s", FAILED_ALLOC);
		free(newUser->userData->username);
		free(newUser->userData);
		free(newUser);
	}

	newUser->userData->hashIndex = hashIndex;
	strncpy(newUser->userData->username, username, (strlen(username) + ADD_NULL));
	strncpy(newUser->userData->passwordHashed, password, (strlen(password) + ADD_NULL));
	newUser->next_user = NULL;

	return newUser;

}



void insertAtEnd(userNode** head, userNode* newNode)
{
	if (!*head)
	{
		*head = newNode;
	}
	else
	{
		userNode* p = *head;
		while (p->next_user)
		{
			p = p->next_user;
		}
		p->next_user = newNode;
	}
}

int saveProjectFunction(char* username, unsigned long long int savePath)
{
	printf("%s", savePath);
	FrameNode* curr = head;
	FILE* theFile = NULL;

	theFile = fopen(savePath, "w");
	if (theFile == NULL)
	{
		return UNSUCCESS;
	}
	while (curr)
	{
		fprintf(theFile, "%s%c%d%c%s%c", curr->frame->path, SPLIT_SIGN, curr->frame->duration, SPLIT_SIGN, curr->frame->name, END_OF_NODE);
		curr = curr->next;
	}
	fclose(theFile);
	return SUCCESS;

}
