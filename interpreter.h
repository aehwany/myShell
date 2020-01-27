/*
 * interpreter.h
 *
 *  Created on: Jan. 26, 2020
 *      Author: ahmedelehwany
 */

#ifndef INTERPRETER_H_
#define INTERPRETER_H_


int interpreter(char *words[]);
int help();
int quit();
int set(char *key, char *value);
int print(char *key);
int run(char *fileName);


#endif /* INTERPRETER_H_ */
