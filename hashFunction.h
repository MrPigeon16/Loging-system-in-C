#pragma once
#ifndef hashFunction
#define HASH_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int hashFunction(char* username, char* password);
int* changeLettersToASCII(char* input, int* asciiNumbers, int placeToAdd);
unsigned long long int multiplyAndSum(int* asciiNumbers, int totalLen);


#endif // !hashFunction
