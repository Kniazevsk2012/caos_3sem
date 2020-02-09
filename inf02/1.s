    .text      
    .global summ

summ:
	cmp r1, #0
	bxeq lr
	ldr r3, [r2]
	add r0, r0, r3
	add r2, r2, #4
	sub r1, r1, #1
	b summ
