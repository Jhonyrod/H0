#include <GDT.h>

const GDTEntry TSSD={.Accessed=true, .Executable=true, .Present=true};

unsigned int SetGDTBA(GDTEntry *GDT, const size_t Address)
{
	if(Address>0xFFFFFFFF) return 1;
	(*GDT).BaseL=Address&0xFFFFFF;
	(*GDT).BaseH=Address>>24;
	return 0;
}

unsigned int SetGDTLS(GDTEntry *GDT, const size_t Size)
{
	if(Size>0xFFFFF) return 1;
	(*GDT).LimitL=Size&0xFFFF;
	(*GDT).LimitH=Size>>16;
	return 0;
}