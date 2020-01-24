/*
 * shell.c
 *
 *  Created on: Jan. 23, 2020
 *      Author: ahmedelehwany
 */

#include <stdio.h>
#include <stdlib.h>
char** parse(char* input);
int main() {
	printf("Welcome to the Ahmed Elehwany shell!\n");
	printf("Version 1.0 Created January 2020\n");
	printf("$");
	char input[1000];
	fgets(input, 1000, stdin);
	input[strlen(input)-1] = '\0';
	char** words = parse(input);
	//printf("%s", words[2]);
	int errorCode = interpreter(words);
	return errorCode;
}


char** parse(char* input) {
	int lineIndex;
	int charIndex;
	int wordIndex = 0;
	char accumulator[200];
	char **words = malloc(sizeof(char**));
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

