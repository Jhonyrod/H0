AS=nasm
CC=clang
DB=gdb-multiarch

DBFLAGS=-ex 'target remote 192.168.1.3:1234'
ASFLAGS=-f elf64 -gdwarf
CCFLAGS=-I include -std=c2x -ffreestanding -nostdlib -nostdinc -nodefaultlibs -fno-pic -fno-builtin
LDFLAGS=

TARGETS=entry.c GDT.c memory.c

QEMU=/mnt/c/Program\ Files/QEMU/qemu-system-x86_64.exe

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