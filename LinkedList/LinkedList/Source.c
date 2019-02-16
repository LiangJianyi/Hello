#include <stdio.h>
#include "LINKED_LIST_DIGITAL.h"

void main() {
	void PrintDigital(int d);

	struct LINKED_LIST_DIGITAL * first = CreateNode(1);
	Add(first, 20);
	Add(first, 20);
	Add(first, 4);
	Add(first, 5);
	Add(first, 6);
	Add(first, 5);
	Add(first, 5);
	ForEach(first, PrintDigital);
	printf_s("Count: %d\n", Count(first));

	printf_s("Remove(likptr,5):\n");
	first = Remove(first, 5);
	ForEach(first, PrintDigital);
	printf_s("Count: %d\n", Count(first));

	printf_s("Remove(likptr,5):\n");
	first = Remove(first, 5);
	ForEach(first, PrintDigital);
	printf_s("Count: %d\n", Count(first));

	printf_s("Remove(likptr,5):\n");
	first = Remove(first, 5);
	ForEach(first, PrintDigital);
	printf_s("Count: %d\n", Count(first));

	printf_s("Remove(likptr,2):\n");
	first = Remove(first, 2);
	ForEach(first, PrintDigital);
	printf_s("Count: %d\n", Count(first));

	printf_s("Remove(likptr,2):\n");
	first = Remove(first, 2);
	ForEach(first, PrintDigital);
	printf_s("Count: %d\n", Count(first));

	RemoveAll(&first);
	if (first == NULL) {
		printf_s("Remove all node.");
	}
}

void PrintDigital(int d) {
	printf_s("%d\n", d);
}