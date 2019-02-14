#pragma once
#define STRING_EMPTY ""

#define _array_length(arr) sizeof(arr) / sizeof((arr)[0])

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