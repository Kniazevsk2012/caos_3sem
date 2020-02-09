.intel_syntax noprefix
.text
.global _start

_start:
 mov eax, 3
 mov ebx, 0
 sub esp, 8
 lea ecx, [esp]
 mov edx, 8
 int 0x80

write_loop:
 mov esi, eax
 cmp esi, 0
 je final 
 mov eax, 4
 mov ebx, 1
 lea ecx, [esp]
 mov edx, esi
 int 0x80
 add esp, 8
 jmp _start

final:
 mov eax, 1
 mov ebx, 0
 int 0x80
