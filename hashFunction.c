#include "hashFunction.h"



unsigned long long int hashFunction(char* username,char* password)
{
	unsigned long long int sumOfallNumbers = 0;
	int totalLength = strlen(username) + strlen(password);

	int* asciiNumbers = (int*)malloc(sizeof(int) * totalLength);

	if (asciiNumbers == NULL)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}

	int currentIndex = 0;

	asciiNumbers = changeLettersToASCII(username, asciiNumbers, currentIndex);
	currentIndex += strlen(username);

	asciiNumbers = changeLettersToASCII(password, asciiNumbers, currentIndex);

	sumOfallNumbers = multiplyAndSum(asciiNumbers, totalLength);

	// Free allocated memory
	free(asciiNumbers);

	return sumOfallNumbers;
	

	
}



int* changeLettersToASCII(char* input, int* asciiNumbers, int placeToAdd)
{
	int i = 0;
	while (input[i] != '\0')
	{
		asciiNumbers[placeToAdd + i] = (int)input[i];
		i++;
	}
	return asciiNumbers;
}




unsigned long long int multiplyAndSum(int* asciiNumbers, int totalLen)
{
	int key = 1;
	unsigned long long int total = 0;

	for (int i = 0; i < totalLen; i++) {
		key = key + asciiNumbers[i];
	}

	for (int i = 0; i < totalLen; i++) {
		total += (key * asciiNumbers[i] * totalLen);
	}

	return total;
}
