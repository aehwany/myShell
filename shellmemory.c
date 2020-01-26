/*
 * shellmemory.c
 *
 *  Created on: Jan. 23, 2020
 *      Author: ahmedelehwany
 */

#include "shellmemory.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MEMORY *shellMemory;

int printVal(char *key) {
	struct MEMORY *iterator;
	iterator = shellMemory;
	while(iterator != NULL) {
		if(strcmp(iterator->key , key) == 0) {
			printf("Key: %s\nValue: %s\n", key, iterator->value);
			return 0;
		}
		iterator = iterator->next;
	}
	printf("Variable does not exist\n");
	return 0;
}

int add(char *key, char *value) {
	struct MEMORY *new = (struct MEMORY*)malloc(sizeof(struct MEMORY));
	new->key = key;
	new->value = value;

	if(shellMemory == NULL) {
		shellMemory = new;
	}
	else{
		new->next = shellMemory;
	}
	shellMemory = new;
	return 0;
}


