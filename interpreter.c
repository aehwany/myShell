/*
 * interpreter.c
 *
 *  Created on: Jan. 23, 2020
 *      Author: ahmedelehwany
 *      Id:260707540
 */

#include "shell.h"
#include "interpreter.h"
#include "shellmemory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursiveCount = 0;

int interpreter(char *words[]) {
	int errorCode = 0;
	const char *cmd_help = "help";
	const char *cmd_quit = "quit";
	const char *cmd_set = "set";
	const char *cmd_print = "print";
	const char *cmd_run = "run";

	if (strcmp(words[0], cmd_help) == 0)
		errorCode = help();
	else if(strcmp(words[0], cmd_quit) == 0)
		errorCode = quit();
	else if(strcmp(words[0], cmd_set) == 0)
		errorCode = set(words);
	else if(strcmp(words[0], cmd_print) == 0)
		errorCode = print(words[1]);
	else if(strcmp(words[0], cmd_run) == 0)
		errorCode = run(words[1]);
	else
		printf("Unknown command\n");
	return errorCode;
}

int help() {
	printf("Command:           			Description:\n");
	printf("help 			      		Displays all the commands\n");
	printf("quit 				    	Terminates the shell with \"Bye!\"\n");
	printf("set VAR STRING 			    	Assigns a value to shell memory\n");
	printf("print VAR 				Displays the STRING assigned to VAR\n");
	printf("run SCRIPT.TXT 				Executes the file SCRIPT.TXT\n");

	return 0;
}

int quit() {
	printf("Bye!\n");
	return 2;
}

int set(char **words) {
	if(words[1] == NULL || words[2] == NULL){
		printf("set command is missing arguments.\n");
		return 0;
	}
	char *key = words[1];
	char *value = words[2];
	char *extension;
	for(int i = 3; i < 100; i++){
		if(words[i] == NULL)	continue;
		extension = calloc(100, sizeof(char*));
		strcat(extension, " ");
		strcat(extension, words[i]);
		strcat(value, extension);
	}
	add(key, value);
	return 0;
}

int print(char* key) {
	printVal(key);
	return 0;
}

int run(char * fileName) {
	if(recursiveCount >= 100)	{
		printf("Program terminated..Script is run recursively!\n");
		return 0;
	}
	recursiveCount++;
	int errorCode = 0;
	char line[1000];
	FILE *file = fopen(fileName, "rt");
	while(!feof(file)) {
		fgets(line, 999, file);
		char** words = parse(line);
		errorCode = interpreter(words);
	}
	fclose(file);
	return 0;
}

