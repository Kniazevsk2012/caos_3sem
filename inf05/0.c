.global calc
.intel_syntax noprefix
.text

calc:
	push ebp
	mov ebp, esp

	fld qword ptr [ebp + 16]
	fadd qword ptr [ebp + 8]

	fild dword ptr [ebp + 32]
	fadd qword ptr [ebp + 24]
	fdivp st(1), st(0)

	mov esp, ebp
	pop ebp
	ret

.global vector_sum

vector_sum:
	push ebp
	mov ebp, esp
	push edi
	push ebx
	push edx

	mov ecx, [ebp + 8]
	mov edx, [ebp + 12]
	mov edi, [ebp + 16]
	mov ebx, [ebp + 20]
	mov eax, 0

loop:
	movaps xmm0, [edx + eax * 4]
	movaps xmm1, [edi + eax * 4]
	addps xmm0, xmm1
	movaps [ebx + eax * 4], xmm0
	add eax, 4
	cmp eax, ecx
	jl loop

	pop ebx
	pop edx
	pop edi
	mov esp, ebp
	pop ebp
	ret
