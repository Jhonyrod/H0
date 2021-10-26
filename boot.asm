org 0x7C00
bits 16
	xor		ax,	ax
	mov		ds,	ax
	cli
	mov		ss,	ax
	mov		sp,	0x4000
	sti
reset:
	int		0x13
	xor		ax,	ax
	jc		reset
	mov		es,	ax
	mov		ax,	0x0240
	mov		bx,	0x7E00
	mov		cx,	2
	xor		dh,	dh
	int		0x13
	jc		reset
	jmp		0x7E00
stack:
	times	$$+510-$	db 0
dw		0xAA55