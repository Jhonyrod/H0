AS=nasm
CC=clang
LD=ld

ASFLAGS=
CCFLAGS=-I include -std=c2x -ffreestanding -nostdlib -nostdinc -nodefaultlibs -fno-builtin -fno-pic 
LDFLAGS=

TARGETS=entry.c GDT.c TSS.c memory.c

QEMU=/mnt/c/Program\ Files/QEMU/qemu-system-x86_64.exe -s -S -monitor stdio

boot.bin:	boot.asm
	@$(AS) $(ASFLAGS) -o $@ $<

kernel.bin:	$(TARGETS)
	@$(CC) $(CCFLAGS) -Wl,--oformat=binary $^ -o $@

kernel.elf:	$(TARGETS)
	@$(CC) $(CCFLAGS) -g $^ -o $@

run:		boot.bin
	@$(QEMU) $<

clean:
	@rm -rf *.i *.s *.o *.bc *.bin *.dbg *.out *.elf