/*
 * interpreter.h
 *
 *  Created on: Jan. 26, 2020
 *      Author: ahmedelehwany
 *      Id:260707540
 */

#ifndef INTERPRETER_H_
#define INTERPRETER_H_


int interpreter(char **words);
int help(char **words);
int quit(char **words);
int set(char **words);
int print(char **words);
int run(char **words);


#endif /* INTERPRETER_H_ */
