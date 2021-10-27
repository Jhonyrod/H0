#pragma once
#ifndef STDINT_H
#define STDINT_H

#ifndef __SIZE_TYPE__
#define __SIZE_TYPE__		unsigned long
#endif
typedef __SIZE_TYPE__		size_t;

#ifndef __INT8_TYPE__
#define __INT8_TYPE__		signed char
#endif
typedef __INT8_TYPE__		int8_t;

#ifndef __INT16_TYPE__
#define __INT16_TYPE__		short
#endif
typedef __INT16_TYPE__		int16_t;

#ifndef __INT32_TYPE__
#define __INT32_TYPE__		int
#endif
typedef __INT32_TYPE__		int32_t;

#ifndef __INT64_TYPE__
#define __INT64_TYPE__		long
#endif
typedef __INT64_TYPE__		int64_t;

#ifndef __INTMAX_TYPE__
#define __INTMAX_TYPE__		long
#endif
typedef __INTMAX_TYPE__		intmax_t;

#ifndef __INTPTR_TYPE__
#define __INTPTR_TYPE__		long
#endif
typedef __INTPTR_TYPE__		intptr_t;

#ifndef __UINT8_TYPE__
#define __UINT8_TYPE__		unsigned char
#endif
typedef __UINT8_TYPE__		uint8_t;

#ifndef __UINT16_TYPE__
#define __UINT16_TYPE__		unsigned short
#endif
typedef __UINT16_TYPE__		uint16_t;

#ifndef __UINT32_TYPE__
#define __UINT32_TYPE__		unsigned int
#endif
typedef __UINT32_TYPE__		uint32_t;

#ifndef __UINT64_TYPE__
#define __UINT64_TYPE__		unsigned long
#endif
typedef __UINT64_TYPE__		uint64_t;

#ifndef __UINTMAX_TYPE__
#define __UINTMAX_TYPE__	unsigned long
#endif
typedef __UINTMAX_TYPE__	uintmax_t;

#ifndef __UINTPTR_TYPE__
#define __UINTPTR_TYPE__	unsigned long
#endif
typedef __UINTPTR_TYPE__	uintptr_t;

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

typedef _Bool bool;

#endif