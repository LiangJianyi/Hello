#include <stdio.h>
#include "LINKED_LIST_DIGITAL.h"

void main() {
	void PrintDigital(int d);

	struct LINKED_LIST_DIGITAL * first = CreateNode(1);
	Add(first, 2);
	Add(first, 3);
	Add(first, 4);
	Add(first, 5);
	ForEach(first, PrintDigital);
	RemoveAll(&first);
	ForEach(first, NULL);
	if (first==NULL) {
		printf_s("Remove all.");
	}
}

void PrintDigital(int d) {
	printf_s("%d\n", d);
}