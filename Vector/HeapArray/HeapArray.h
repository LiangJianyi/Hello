#pragma once
#include <stdlib.h>

int * CreateArray(size_t len) {
	return (int*)malloc(sizeof(int)*len);
}

int * Indexer(int * arr, int index) {
	for (size_t i = 0; i < index; i++) {
		arr++;
	}
	return arr;
}