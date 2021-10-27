#include <GDT.h>

void _start(void)
{
	extern GDTEntry TSSD;
	GDTEntry GDT[4]={};
	for(char i=1;i<4;++i)
		GDT[i].Present=true;
	GDT[3]=TSSD;
	SetGDTBA(&GDT[1], 0x7FFFFFFF);
	SetGDTLS(&GDT[1], 0x7FFFF);
}