/*
 * shellmemory.h
 *
 *  Created on: Jan. 26, 2020
 *      Author: ahmedelehwany
 *      Id:260707540
 */

#ifndef SHELLMEMORY_H_
#define SHELLMEMORY_H_

struct 	MEMORY {
	char *key;
	char *value;
};

int initMemory();
int printVal(char *key);
int add(char *key, char *value);

#endif /* SHELLMEMORY_H_ */
