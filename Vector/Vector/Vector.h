#pragma once
#include <memory.h>
#define STRING_EMPTY ""

#define _array_length(arr) sizeof(arr) / sizeof((arr)[0])

#define _add_vector(T,N) \
T(*Add(T(*oldarr)[N],T value))[N + 1] { \
	T(*newarr)[N + 1] = (T(*)[N + 1])malloc(sizeof(T[N + 1])); \
	if (memcpy_s(newarr,sizeof(newarr),oldarr,sizeof(oldarr))==0) { \
		return newarr; \
	} \
	else { \
		abort(); \
	} \
}

#define _concat_arr(T,N,L) \
 T (*ConcatArr(T(*newarr)[N] , T(*oldarr)[L]))[N] { \
	if (newarr != NULL && oldarr != NULL) { \
		size_t olen = _array_length(*oldarr); \
		size_t nlen = _array_length(*newarr); \
		if (nlen > olen) { \
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


#define _create_vector(T,N) \
T(*CreateVector())[N]{ \
	return (T(*)[N])malloc(sizeof(T[N])); \
}
