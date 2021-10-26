#include <memory.h>

int		memcmp(const void *a, const void *b, size_t n)
{
	return __builtin_memcmp(a,b,n);
}

void*	memset(void *s, const uint8_t c, size_t n)
{
	return __builtin_memset(s,c,n);
}

void*	memcpy(void *d, const void *s, size_t n)
{
	return __builtin_memcpy(d,s,n);
}

void*	memmove(void *d, void *s, size_t n)
{
	return __builtin_memmove(s,d,n);
}