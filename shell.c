/*
 * shell.c
 *
 *  Created on: Jan. 23, 2020
 *      Author: ahmedelehwany
 *      Id: 260707540
 */

#include "shell.h"
#include "interpreter.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	printf("Welcome to the Ahmed Elehwany shell!\n");
	printf("Version 1.0 Created January 2020\n");
	while(1) {
		printf("$");
		char input[1000];
		fgets(input, 1000, stdin);
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
	while(input[strlen(input)-1] == '\r' || input[strlen(input)-1] == '\n'){
		input[strlen(input)-1] = '\0';
	}
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
	return words;
}

