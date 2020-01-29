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

int interpreter(char **words) {
	int errorCode = 0;
	const char *cmd_help = "help";
	const char *cmd_quit = "quit";
	const char *cmd_set = "set";
	const char *cmd_print = "print";
	const char *cmd_run = "run";

	if (strcmp(words[0], cmd_help) == 0)
		errorCode = help(words);
	else if (strcmp(words[0], cmd_quit) == 0)
		errorCode = quit(words);
	else if (strcmp(words[0], cmd_set) == 0)
		errorCode = set(words);
	else if (strcmp(words[0], cmd_print) == 0)
		errorCode = print(words);
	else if (strcmp(words[0], cmd_run) == 0)
		errorCode = run(words);
	else
		printf("Unknown command\n");
	return errorCode;
}

int help(char **words) {
	printf("COMMAND(case sensitive)     		DESCRIPTION\n");
	printf("help 			      		Displays all the commands\n");
	printf("quit 				    	Exits / terminates the shell with \"Bye!\"\n");
	printf("set VAR STRING 			    	Assigns a value to shell memory\n");
	printf("print VAR 				Displays the STRING assigned to VAR\n");
	printf("run SCRIPT.TXT 				Executes the file SCRIPT.TXT\n");

	return 0;
}

int quit(char **words) {
	printf("Bye!\n");
	return 2;
}

int set(char **words) {
	if (words[1] == NULL || words[2] == NULL) {
		printf("set command is missing arguments.\n");
		return -1;
	}
	char *key = words[1];
	char *value = words[2];
	add(key, value);
	return 0;
}

int print(char **words) {
	if (words[1] == NULL) {
		printf("print command is missing arguments.\n");
		return -1;
	}
	printVal(words[1]);
	return 0;
}

int run(char **words) {
	if (words[1] == NULL) {
		printf("run command is missing script name.\n");
		return -1;
	}
	int errorCode = 0;
	FILE *file = fopen(words[1], "rt");
	if (!file) {
		printf("Cannot open script %s.\n", words[1]);
		return -1;
	}
	while (!feof(file)) {
		char *line = calloc(1000, sizeof(char*));
		if(fgets(line, 1000, file) == NULL){
			printf("Unable to read file input, please try again\n");
			break;
		}
		char **words = parse(line);
		errorCode = interpreter(words);
		for(int i = 0 ; i < 100; i++) {
			free(words[i]);
		}
		free(line);
		if (errorCode == -1)
			break;
		if (errorCode == 2)
			break;
	}
	fclose(file);
	return 0;
}

