/*
 * shell.c
 *
 *  Created on: Jan. 23, 2020
 *      Author: ahmedelehwany
 */

#include "shell.h"
#include "interpreter.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	while(1) {
		printf("Welcome to the Ahmed Elehwany shell!\n");
		printf("Version 1.0 Created January 2020\n");
		printf("$");
		char input[1000];
		fgets(input, 1000, stdin);
		input[strlen(input)-1] = '\0';
		char** words = parse(input);
		int errorCode = interpreter(words);
		if(errorCode == 2)	return 0;
	}
	return 0;
}


char** parse(char* input) {
	int lineIndex;
	int charIndex;
	int wordIndex = 0;
	char accumulator[200];
	char **words = calloc(100, sizeof(char*));
	for(lineIndex = 0; input[lineIndex] == ' '; lineIndex++);	//skip white spaces
	while(input[lineIndex] != '\0' && lineIndex < 1000) {
		for(charIndex = 0; input[lineIndex] != '\0' && input[lineIndex] != ' ' && lineIndex < 1000; lineIndex++, charIndex++){
			accumulator[charIndex] = input[lineIndex];
		}
		accumulator[charIndex] = '\0';
		words[wordIndex] = strdup(accumulator);
		wordIndex++;
		lineIndex++;
	}
//	printf("word[0] is %s\n", words[0]);
//	printf("word[1] is %s\n", words[1]);
	//printf("word[2] is %s\n", words[2]);
	return words;
}

