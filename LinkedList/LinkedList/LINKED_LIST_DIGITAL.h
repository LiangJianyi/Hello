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

struct LINKED_LIST_DIGITAL * CreateNode(int content) {
	struct LINKED_LIST_DIGITAL * node = (struct LINKED_LIST_DIGITAL*)malloc(sizeof(struct LINKED_LIST_DIGITAL));
	node->content = content;
	node->next = NULL;
	return node;
}

size_t Count(struct LINKED_LIST_DIGITAL * likptr) {
	size_t incre = 0;
	while (likptr != NULL) {
		incre += 1;
		likptr = likptr->next;
	}
	return incre;
}

void ForEach(struct LINKED_LIST_DIGITAL * likptr, void(*p)(int)) {
	if (likptr != NULL) {
		p(likptr->content);
		ForEach(likptr->next, p);
	}
}

struct LINKED_LIST_DIGITAL * Find(struct LINKED_LIST_DIGITAL * likptr, int content) {
	// 根据传入的 content 查找对应的节点并返回一个新的链表
	// 比如链表：(1)->(20)->(20)->(4)->(5)->(5)->(6)->(5)->(5)
	// 执行 struct LINKED_LILST_dIGITAL * newlik = Find(likptr,5)
	// newlik 的值为 (5)->(5)->(5)->(5)
	// 执行 struct LINKED_LILST_dIGITAL * newlik = Find(likptr,20)
	// newlik 的值为 (20)->(20)
	// 执行 struct LINKED_LILST_dIGITAL * newlik = Find(likptr,6)
	// newlik 的值为 (6)
	return NULL;
}

struct LINKED_LIST_DIGITAL * Remove(struct LINKED_LIST_DIGITAL * likptr, size_t index) {
	// 移除第 index 个节点并返回新的链表
	// 比如链表：(1)->(20)->(20)->(4)->(5)->(6)->(5)->(5)
	// 执行 struct LINKED_LILST_dIGITAL * newlik = Remove(likptr,5)
	// newlik 的值为 (1)->(20)->(20)->(4)->(5)->(5)->(5)
	// 再次执行 struct LINKED_LILST_dIGITAL * newlik = Remove(likptr,5)
	// newlik 的值为 (1)->(20)->(20)->(4)->(5)->(5)
	// 再次执行 struct LINKED_LILST_dIGITAL * newlik = Remove(likptr,5)
	// newlik 的值为 (1)->(20)->(20)->(4)->(5)
	// 再次执行 struct LINKED_LILST_dIGITAL * newlik = Remove(likptr,2)
	// newlik 的值为 (1)->(20)->(4)->(5)
	// 再次执行 struct LINKED_LILST_dIGITAL * newlik = Remove(likptr,2)
	// newlik 的值为 (1)->(20)->(5)
	// 以此类推......
	if (likptr != NULL) {
		if (index < Count(likptr)) {
			struct LINKED_LIST_DIGITAL * previous = NULL;
			struct LINKED_LIST_DIGITAL * firstNode = likptr;
			for (size_t i = 0; i <= index; i++) {
				if (i == index) {
					previous->next = likptr->next;
					free(likptr);
				}
				else {
					previous = likptr;
					likptr = likptr->next;
				}
			}
			return firstNode;
		}
		else {
			abort();
		}
	}
}

void RemoveAll(struct LINKED_LIST_DIGITAL ** likptr) {
	if (*likptr != NULL) {
		struct LINKED_LIST_DIGITAL * temp = NULL;
		while (*likptr != NULL) {
			temp = *likptr;
			*likptr = (*likptr)->next;
			free(temp);
		}
		likptr = NULL;
	}
}