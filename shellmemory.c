/*
 * shellmemory.c
 *
 *  Created on: Jan. 23, 2020
 *      Author: ahmedelehwany
 *      Id:260707540
 */

#include "shellmemory.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int NUM_VARS = 0;
int MEM_SIZE = 100;
struct MEMORY *shellMemory;

int initMemory(){
	shellMemory = calloc(MEM_SIZE, sizeof(struct MEMORY));
	return 0;
}
int printVal(char *key) {
	for(int i = 0 ; i < MEM_SIZE; i++){
        if ((shellMemory[i].key != NULL) && (strcmp(shellMemory[i].key, key) == 0)){
        	printf("%s\n", shellMemory[i].value);
        	return 0;
        }
	}
	printf("Variable does not exist\n");
	return -1;
}

int add(char *key, char *value) {
	int index;
	for(index = 0 ; index < MEM_SIZE; index++){
		if(shellMemory[index].key == NULL)	break;
        if(strcmp(shellMemory[index].key, key) == 0){
        	strcpy(shellMemory[index].value, value);
        	return 0;
        }
	}
	if(NUM_VARS >= MEM_SIZE) {
		MEM_SIZE += 100;
		shellMemory = realloc(shellMemory, MEM_SIZE * sizeof(struct MEMORY));
	}
	shellMemory[index].key = calloc(1000, sizeof(char));
	shellMemory[index].value = calloc(1000, sizeof(char));
	strcpy(shellMemory[index].key, key);
	strcpy(shellMemory[index].value, value);
	NUM_VARS++;
	return 0;
}


