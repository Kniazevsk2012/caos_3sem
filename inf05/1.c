.global my_sin
.intel_syntax noprefix
.text

my_sin:
	push ebp
	mov	ebp, esp
	sub	esp, 8
	movsd xmm0, [ebp + 8]
	movsd xmm1, [ebp + 8]
	mov eax, 1
	cvtsi2sd xmm2, eax

	movsd xmm5, [ebp + 8]
	mulsd xmm5, xmm5
	mov edx, -1
	cvtsi2sd xmm2, edx
	mulsd xmm5, xmm2

loop:
	mulsd xmm1, xmm5
	add eax, 1
	cvtsi2sd xmm2, eax
	divsd xmm1, xmm2
	add eax, 1
	cvtsi2sd xmm2, eax
	divsd xmm1, xmm2
	movsd xmm3, xmm0
	addsd xmm0, xmm1
	comisd xmm0, xmm3	
	jne	loop
	movsd [ebp - 8], xmm0
	fld	qword ptr [ebp - 8]
	mov esp, ebp
	pop	ebp
	ret
