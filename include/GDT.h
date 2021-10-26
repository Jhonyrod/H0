#pragma once
#ifndef GDT_H
#define GDT_H
#include <stdint.h>

typedef struct __attribute__((packed))
{
	uint16_t	LimitL;
	uint32_t	BaseL:		24;
	bool		Accessed:	1,
				RWTBusy:	1,
				ConfDir:	1,
				Executable:	1,
				CodeOrData:	1;
	uint8_t		Ring:		2;
	bool		Present:	1;
	uint8_t		LimitH:		4;
	bool		Available:	1,
				LongMode:	1,
				Big:		1,
				Granularity:1;
	uint8_t		BaseH;
} GDTEntry;

unsigned int SetGDTBA(GDTEntry *GDT, const size_t Address);
unsigned int SetGDTLS(GDTEntry *GDT, const size_t Size);
#endif