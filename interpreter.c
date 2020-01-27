/*
 * interpreter.c
 *
 *  Created on: Jan. 23, 2020
 *      Author: ahmedelehwany
 */

#include "shell.h"
#include "interpreter.h"
#include "shellmemory.h"

#include <stdio.h>
#include <string.h>


int interpreter(char *words[]) {
	int errorCode = 0;
	if(words[0][0] == '.' || words[0][1] == '/')	errorCode = 2;
	const char *cmd_help = "help";
	const char *cmd_quit = "quit";
	const char *cmd_set = "set";
	const char *cmd_print = "print";
	const char *cmd_run = "run";

//	printf("cmd length is:%d", strlen(words[0]));

	if (strcmp(words[0], cmd_help) == 0)
		errorCode = help();
	else if(strcmp(words[0], cmd_quit) == 0)
		errorCode = quit();
	else if(strcmp(words[0], cmd_set) == 0)
		errorCode = set(words[1], words[2]);
	else if(strcmp(words[0], cmd_print) == 0)
		errorCode = print(words[1]);
	else if(strcmp(words[0], cmd_run) == 0)
		errorCode = run(words[1]);
	else
		printf("Unknown command\n");
	return errorCode;
}

int help() {
	printf("Command (case sensative)           Description\n");
	printf("help 			      		Displays all the commands\n");
	printf("quit 				    	Exits / terminates the shell with \"Bye!\"\n");
	printf("set VAR STRING 			    	Assigns a value to shell memory\n");
	printf("print VAR 				Displays the STRING assigned to VAR\n");
	printf("run SCRIPT.TXT 				Executes the file SCRIPT.TXT\n");

	return 0;
}

int quit() {
	printf("Bye!\n");
	return 2;
}

int set(char* key, char* value) {
//	printf("set method\n");
	add(key, value);
	return 0;
}

int print(char* key) {
	printVal(key);
	return 0;
}

int run(char * fileName) {
//	printf("run method\n");
//	printf("%s\n", fileName);
	int errorCode = 0;
	char line[1000];
	FILE *file = fopen(fileName, "rt");
//	printf("file is success");
	fgets(line, 999, file);
	while(!feof(file)) {
		while(line[strlen(line)-1] == '\r' || line[strlen(line)-1] == '\n'){
			line[strlen(line)-1] = '\0';
		}
//		printf("%d\n", line[strlen(line)-1]);
//		printf("%s.\n", line);
		char** words = parse(line);
		errorCode = interpreter(words);
		fgets(line, 999, file);
	}
	fclose(file);
	return 0;
}

