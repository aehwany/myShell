/*
 * shellmemory.h
 *
 *  Created on: Jan. 26, 2020
 *      Author: ahmedelehwany
 */

#ifndef SHELLMEMORY_H_
#define SHELLMEMORY_H_

struct 	MEMORY {
	char *key;
	char *value;
	struct MEMORY *next;
};

int printVal(char *key);
int add(char *key, char *value);

#endif /* SHELLMEMORY_H_ */
