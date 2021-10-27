#pragma once
#ifndef MEMORY_H
#define MEMORY_H
#include <stdint.h>

int     memcmp(const void *a, const void *b, size_t n);
void *  memset(void *s, const uint8_t c, size_t n);
void *  memcpy(void *d, const void *s, size_t n);
void *  memmove(void *d, void *s, size_t n);
#endif