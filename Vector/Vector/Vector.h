#pragma once
#include <stdlib.h>
#include <memory.h>

// 空字符串
#define STRING_EMPTY ""

// 获得数组或 vector 的长度
#define _vector_length(arr) sizeof(arr) / sizeof((arr)[0])

// 给指定的 vector 添加一个元素
// N 为指定的 vector 原来的长度
#define _add_vector(T,N) \
T(*Add(T(*oldarr)[N],T value))[N + 1] { \
	T(*newarr)[N + 1] = (T(*)[N + 1])malloc(sizeof(T[N + 1])); \
	if (memcpy_s(newarr,sizeof(*newarr),oldarr,sizeof(*oldarr))==0) { \
		(*newarr)[N - 1] = value; \
		(*newarr)[N] = '\0'; \
		return newarr; \
	} \
	else { \
		abort(); \
	} \
}

#define _vector_concat(T,N1,N2) \
T(*VectorConcat(T(*vec1)[N1], T(*vec2)[N2]))[N1 + N2] { \
	if (vec1 != NULL && vec2 != NULL) { \
		STUFF(*newvector)[N1 + N2] = (STUFF(*)[N1 + N2])malloc(sizeof(STUFF[N1 + N2])); \
		size_t i = 0; \
		while (i < _vector_length(*vec1)) { \
			(*newvector)[i] = (*vec1)[i]; \
			i += 1; \
		} \
		do { \
			(*newvector)[i] = (*vec2)[i]; \
			i += 1; \
		} while (i < _vector_length(*vec2)); \
		return newvector; \
	} \
	else { \
		abort(); \
	} \
}


// 把一个 vector 的内容拷贝到另一个空 vector
#define _vector_copy(T,N,L) \
 T(*VectorCopy(T(*newarr)[N] , T(*oldarr)[L]))[N] { \
	if (newarr != NULL && oldarr != NULL) { \
		size_t olen = _vector_length(*oldarr); \
		size_t nlen = _vector_length(*newarr); \
		if (nlen >= olen) { \
			size_t i = 0; \
			while (i < olen) { \
				(*newarr)[i] = (*oldarr)[i]; \
				i += 1; \
			} \
			do { \
				(*newarr)[i].a = 0; \
				(*newarr)[i].b = STRING_EMPTY; \
				i += 1; \
			} while (i < nlen); \
			return newarr; \
		} \
		else { \
			abort(); \
		} \
	} \
	else { \
		abort(); \
	} \
}

// 创建一个 vector
#define _create_vector(T,N) (T(*)[N])malloc(sizeof(T[N]))

#define _list(T) \
typedef struct LIST_##T { \
	size_t index; \
	size_t capacity; \
	T data[1]; \
}List_##T; \
\
List_##T * Create_##T(size_t sz) { \
	if (!sz) sz = 1; \
	size_t no_of_bytes = sizeof(List_##T) + sizeof(T) * (sz - 1); \
	List_##T * array = (List_##T*)malloc(no_of_bytes); \
	if (array) { \
		array->index = 0; \
		array->capacity = sz; \
	} \
	return array; \
} \
\
void PushBack_##T(List_##T** pp, T e) { \
	if (pp && *pp) { \
		if ((*pp)->index == (*pp)->capacity) { \
			size_t no_of_bytes = sizeof(List_##T) + sizeof(T) * ((*pp)->capacity * 2 - 1); \
			*pp = (T*)realloc(*pp, no_of_bytes); \
			if (*pp) { \
				(*pp)->capacity *= 2; \
			} \
		} \
		if (*pp) { \
			(*pp)->data[(*pp)->index] = e; \
			((*pp)->index) += 1; \
		} \
	} \
}

#define _print_list(T, PRINT_FORMAT) \
void PrintList_##T(List_##T * lst) { \
	printf_s("index: %d, capacity: %d, data: ", lst->index, lst->capacity); \
	for (size_t i = 0; i < lst->index; i++) { \
		printf_s(""#PRINT_FORMAT", ", lst->data[i]); \
	} \
	printf_s("\n"); \
}