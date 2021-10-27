AS=nasm
CC=clang
DB=gdb-multiarch

HOST=192.168.1.3

DBFLAGS=-ex 'target remote $(HOST):1234' -ex 'set disassembly-flavor intel' -ex 'layout split'
ASFLAGS=-f elf64 -gdwarf
CCFLAGS=-I include -std=c2x -ffreestanding -nostdlib -nostdinc -nodefaultlibs -fno-pic -fno-builtin
LDFLAGS=

TARGETS=entry.c GDT.c memory.c

QEMU=/mnt/c/Program\ Files/QEMU/qemu-system-x86-64.exe

boot:		boot.asm
	@$(AS) $(ASFLAGS) -o $@.o $<
	ld -Ttext=0x7c00 -o $@.elf $@.o
	objcopy -O binary $@.elf $@.bin

kernel.bin:	$(TARGETS)
	@$(CC) $(CCFLAGS) -Wl,--oformat=binary $^ -o $@

kernel.elf:	$(TARGETS)
	@$(CC) $(CCFLAGS) -g $^ -o $@

run:		boot
	@$(QEMU) -monitor stdio $<.bin

dbg:		boot
	@$(QEMU) -s -S $<.bin & $(DB) $(DBFLAGS) $<.elf

clean:
	@rm -rf *.i *.s *.o *.bc *.map *.dbg *.bin *.out *.elf