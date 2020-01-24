/*
 * interpreter.c
 *
 *  Created on: Jan. 23, 2020
 *      Author: ahmedelehwany
 */

int interpreter(char *words[]) {
	int errorCode = 0;
	if(words[0][0] == '.' || words[0][1] == '/')	errorCode = 2;
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
		errorCode = set();
	else if(strcmp(words[0], cmd_print) == 0)
		errorCode = print();
	else if(strcmp(words[0], cmd_run) == 0)
		errorCode = run();
	else
		printf("Unknown command");
	return errorCode;
}

int help() {
	printf("help method");
	return 0;
}

int quit() {
	printf("quit method");
	return 0;
}

int set() {
	printf("set method");
	return 0;
}

int print() {
	printf("print method");
	return 0;
}

int run() {
	printf("run method");
	return 0;
}
