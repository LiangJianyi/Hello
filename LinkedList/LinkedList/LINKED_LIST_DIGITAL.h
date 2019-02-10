#pragma once
#include <stdlib.h>

struct LINKED_LIST_DIGITAL {
	int content;
	struct LINKED_LIST_DIGITAL * next;
};

void Add(struct LINKED_LIST_DIGITAL * likptr, int content) {
	if (likptr != NULL) {
		struct LINKED_LIST_DIGITAL * temp = (struct LINKED_LIST_DIGITAL*)malloc(sizeof(struct LINKED_LIST_DIGITAL));
		temp->content = content;
		temp->next = NULL;
		while (likptr->next != NULL) {
			likptr = likptr->next;
		}
		likptr->next = temp;
	}
	else {
		abort();
	}
}

struct LINKED_LIST_DIGITAL * CreateFirst(int content) {
	struct LINKED_LIST_DIGITAL * node = (struct LINKED_LIST_DIGITAL*)malloc(sizeof(struct LINKED_LIST_DIGITAL));
	node->content = content;
	node->next = NULL;
	return node;
}

void ForEach(struct LINKED_LIST_DIGITAL * likptr, void(*p)(int)) {
	if (likptr != NULL) {
		p(likptr->content);
		ForEach(likptr->next, p);
	}
}