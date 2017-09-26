	.file	"AdjutantAutumn.c"
	.intel_syntax noprefix
	.section	.rodata
	.align 8
.LC0:
	.string	"\033[37m[.]\033[0m SYSTEM MAINTENANCE"
	.align 8
.LC1:
	.string	"\033[32m[.]\033[0m SYSTEMS MAINTENANCE COMPLETE"
	.text
	.globl	system_maintenance
	.type	system_maintenance, @function
system_maintenance:
.LFB5:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	lea	rdi, .LC0[rip]
	call	puts@PLT
	call	update
	call	antivirus
	lea	rdi, .LC1[rip]
	call	puts@PLT
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	system_maintenance, .-system_maintenance
	.section	.rodata
.LC2:
	.string	"\033[37m[.]\033[0m Updating..."
.LC3:
	.string	"\033[32m[.]\033[0m Update complete!"
.LC4:
	.string	"\033[31m[.]\033[0m Update failed..."
	.text
	.globl	update
	.type	update, @function
update:
.LFB6:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	edi, 64
	call	malloc@PLT
	mov	QWORD PTR -8[rbp], rax
	mov	rax, QWORD PTR -8[rbp]
	movabs	rdx, 7161128167105918323
	movabs	rcx, 8464888427902296429
	mov	QWORD PTR [rax], rdx
	mov	QWORD PTR 8[rax], rcx
	mov	BYTE PTR 16[rax], 0
	lea	rdi, .LC2[rip]
	call	puts@PLT
	mov	rax, QWORD PTR -8[rbp]
	mov	rdi, rax
	call	system@PLT
	test	eax, eax
	jne	.L3
	lea	rdi, .LC3[rip]
	call	puts@PLT
	jmp	.L5
.L3:
	lea	rdi, .LC4[rip]
	call	puts@PLT
	mov	edi, 1
	call	exit@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	update, .-update
	.section	.rodata
.LC5:
	.string	"sudo freshclam"
.LC6:
	.string	"sudo clamscan -r -i "
.LC7:
	.string	"/"
	.align 8
.LC8:
	.string	"\033[37m[.]\033[0m Updating virus..."
.LC9:
	.string	"\033[32m[.]\033[0m Update complete"
	.align 8
.LC10:
	.string	"\033[31m[.]\033[0m Something went wrong..."
.LC11:
	.string	"Executing command: %s\n"
	.align 8
.LC12:
	.string	"\033[37m[.]\033[0m Scanning for virus..."
	.align 8
.LC13:
	.string	"\033[32m[.]\033[0m Scanning complete!"
.LC14:
	.string	"\033[31m[.]\033[0m Scanning failed!"
	.text
	.globl	antivirus
	.type	antivirus, @function
antivirus:
.LFB7:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 48
	lea	rax, .LC5[rip]
	mov	QWORD PTR -48[rbp], rax
	lea	rax, .LC6[rip]
	mov	QWORD PTR -40[rbp], rax
	lea	rax, .LC7[rip]
	mov	QWORD PTR -32[rbp], rax
	mov	QWORD PTR -24[rbp], 16
	mov	edi, 8
	call	malloc@PLT
	mov	QWORD PTR -16[rbp], rax
	mov	edi, 8
	call	malloc@PLT
	mov	QWORD PTR -8[rbp], rax
	mov	rdx, QWORD PTR -40[rbp]
	mov	rax, QWORD PTR -8[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	strcat@PLT
	mov	rdx, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR -8[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	strcat@PLT
	mov	rdx, QWORD PTR -48[rbp]
	mov	rax, QWORD PTR -16[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	strcpy@PLT
	lea	rdi, .LC8[rip]
	call	puts@PLT
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	system@PLT
	test	eax, eax
	jne	.L7
	lea	rdi, .LC9[rip]
	call	puts@PLT
	jmp	.L8
.L7:
	lea	rdi, .LC10[rip]
	call	puts@PLT
.L8:
	mov	rax, QWORD PTR -8[rbp]
	mov	rsi, rax
	lea	rdi, .LC11[rip]
	mov	eax, 0
	call	printf@PLT
	lea	rdi, .LC12[rip]
	call	puts@PLT
	mov	rax, QWORD PTR -8[rbp]
	mov	rdi, rax
	call	system@PLT
	test	eax, eax
	jne	.L9
	lea	rdi, .LC13[rip]
	call	puts@PLT
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	free@PLT
	jmp	.L11
.L9:
	lea	rdi, .LC14[rip]
	call	puts@PLT
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	free@PLT
	mov	edi, 1
	call	exit@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	antivirus, .-antivirus
	.section	.rodata
.LC15:
	.string	"savefileAA.dat"
.LC16:
	.string	"Add new note"
.LC17:
	.string	"Read single note"
.LC18:
	.string	"Read all notes"
.LC19:
	.string	"Update a note"
.LC20:
	.string	"Delete a note"
.LC21:
	.string	"%s"
.LC22:
	.string	"add"
.LC23:
	.string	"read"
.LC24:
	.string	"r"
.LC25:
	.string	"update"
.LC26:
	.string	"delete"
	.align 8
.LC27:
	.string	"Command not reconized.. you wrote %s\n"
	.text
	.globl	noteHandler
	.type	noteHandler, @function
noteHandler:
.LFB8:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	lea	rax, .LC15[rip]
	mov	QWORD PTR -16[rbp], rax
	mov	edi, 4
	call	malloc@PLT
	mov	QWORD PTR -8[rbp], rax
	lea	rdi, .LC16[rip]
	call	puts@PLT
	lea	rdi, .LC17[rip]
	call	puts@PLT
	lea	rdi, .LC18[rip]
	call	puts@PLT
	lea	rdi, .LC19[rip]
	call	puts@PLT
	lea	rdi, .LC20[rip]
	call	puts@PLT
	mov	rax, QWORD PTR -8[rbp]
	mov	rsi, rax
	lea	rdi, .LC21[rip]
	mov	eax, 0
	call	__isoc99_scanf@PLT
	mov	rax, QWORD PTR -8[rbp]
	lea	rsi, .LC22[rip]
	mov	rdi, rax
	call	strcmp@PLT
	test	eax, eax
	jne	.L13
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	createNote
	jmp	.L19
.L13:
	mov	rax, QWORD PTR -8[rbp]
	lea	rsi, .LC23[rip]
	mov	rdi, rax
	call	strcmp@PLT
	test	eax, eax
	jne	.L15
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	readNote
	jmp	.L19
.L15:
	mov	rax, QWORD PTR -8[rbp]
	lea	rsi, .LC24[rip]
	mov	rdi, rax
	call	strcmp@PLT
	test	eax, eax
	jne	.L16
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	readNoteList
	jmp	.L19
.L16:
	mov	rax, QWORD PTR -8[rbp]
	lea	rsi, .LC25[rip]
	mov	rdi, rax
	call	strcmp@PLT
	test	eax, eax
	jne	.L17
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	updateNote
	jmp	.L19
.L17:
	mov	rax, QWORD PTR -8[rbp]
	lea	rsi, .LC26[rip]
	mov	rdi, rax
	call	strcmp@PLT
	test	eax, eax
	jne	.L18
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	deleteNote
	jmp	.L19
.L18:
	mov	rax, QWORD PTR -8[rbp]
	mov	rsi, rax
	lea	rdi, .LC27[rip]
	mov	eax, 0
	call	printf@PLT
.L19:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	noteHandler, .-noteHandler
	.section	.rodata
.LC28:
	.string	"y"
.LC29:
	.string	"a"
.LC30:
	.string	"Error opening file"
.LC31:
	.string	"%s\n"
.LC32:
	.string	"Eat shit"
	.text
	.globl	createNote
	.type	createNote, @function
createNote:
.LFB9:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 48
	mov	QWORD PTR -40[rbp], rdi
	mov	edi, 4096
	call	malloc@PLT
	mov	QWORD PTR -32[rbp], rax
	mov	edi, 4
	call	malloc@PLT
	mov	QWORD PTR -24[rbp], rax
	mov	edi, 4
	call	malloc@PLT
	mov	QWORD PTR -16[rbp], rax
	lea	rax, .LC28[rip]
	mov	QWORD PTR -16[rbp], rax
	mov	rax, QWORD PTR -32[rbp]
	movabs	rsi, 7647223713504783440
	movabs	rdi, 7738157666244260725
	mov	QWORD PTR [rax], rsi
	mov	QWORD PTR 8[rax], rdi
	movabs	rcx, 7742373266838744681
	mov	QWORD PTR 16[rax], rcx
	mov	BYTE PTR 24[rax], 0
	mov	rax, QWORD PTR -40[rbp]
	lea	rsi, .LC29[rip]
	mov	rdi, rax
	call	fopen@PLT
	mov	QWORD PTR -8[rbp], rax
	cmp	QWORD PTR -40[rbp], 0
	jne	.L21
	lea	rdi, .LC30[rip]
	call	puts@PLT
	mov	edi, 1
	call	exit@PLT
.L21:
	cmp	QWORD PTR -32[rbp], 0
	je	.L22
	mov	rdx, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR -8[rbp]
	lea	rsi, .LC31[rip]
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	jmp	.L23
.L22:
	lea	rdi, .LC32[rip]
	call	puts@PLT
.L23:
	mov	rax, QWORD PTR -8[rbp]
	mov	rdi, rax
	call	fclose@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	createNote, .-createNote
	.globl	readNote
	.type	readNote, @function
readNote:
.LFB10:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR -8[rbp], rdi
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	readNote, .-readNote
	.globl	readNoteList
	.type	readNoteList, @function
readNoteList:
.LFB11:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 4144
	mov	QWORD PTR -4136[rbp], rdi
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -8[rbp], rax
	xor	eax, eax
	mov	rax, QWORD PTR -4136[rbp]
	lea	rsi, .LC24[rip]
	mov	rdi, rax
	call	fopen@PLT
	mov	QWORD PTR -4120[rbp], rax
	mov	rax, QWORD PTR -4136[rbp]
	test	rax, rax
	jne	.L27
	lea	rdi, .LC30[rip]
	call	puts@PLT
	mov	edi, 1
	call	exit@PLT
.L28:
	mov	rdx, QWORD PTR -4120[rbp]
	lea	rax, -4112[rbp]
	mov	esi, 255
	mov	rdi, rax
	call	fgets@PLT
	lea	rax, -4112[rbp]
	mov	rdi, rax
	call	puts@PLT
.L27:
	lea	rdx, -4136[rbp]
	mov	rax, QWORD PTR -4120[rbp]
	lea	rsi, .LC21[rip]
	mov	rdi, rax
	mov	eax, 0
	call	__isoc99_fscanf@PLT
	cmp	eax, -1
	jne	.L28
	mov	rax, QWORD PTR -4120[rbp]
	mov	rdi, rax
	call	fclose@PLT
	nop
	mov	rax, QWORD PTR -8[rbp]
	xor	rax, QWORD PTR fs:40
	je	.L29
	call	__stack_chk_fail@PLT
.L29:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	readNoteList, .-readNoteList
	.globl	updateNote
	.type	updateNote, @function
updateNote:
.LFB12:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR -8[rbp], rdi
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	updateNote, .-updateNote
	.globl	deleteNote
	.type	deleteNote, @function
deleteNote:
.LFB13:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR -8[rbp], rdi
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	deleteNote, .-deleteNote
	.section	.rodata
	.align 8
.LC33:
	.string	"Option -%c requires an argument.\n"
.LC34:
	.string	"Unknown option `-%c'.\n"
	.align 8
.LC35:
	.string	"Unknown option character `\\x%x'.\n"
.LC36:
	.string	"abmnc:"
.LC37:
	.string	"Non-option argument %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB14:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 48
	mov	DWORD PTR -36[rbp], edi
	mov	QWORD PTR -48[rbp], rsi
	mov	DWORD PTR -20[rbp], 0
	mov	DWORD PTR -16[rbp], 0
	mov	QWORD PTR -8[rbp], 0
	jmp	.L33
.L42:
	mov	eax, DWORD PTR -12[rbp]
	cmp	eax, 109
	je	.L35
	cmp	eax, 110
	je	.L36
	cmp	eax, 63
	je	.L37
	jmp	.L45
.L35:
	mov	eax, 0
	call	system_maintenance
	jmp	.L33
.L36:
	call	noteHandler
	jmp	.L33
.L37:
	mov	eax, DWORD PTR optopt[rip]
	cmp	eax, 99
	jne	.L38
	mov	edx, DWORD PTR optopt[rip]
	mov	rax, QWORD PTR stderr[rip]
	lea	rsi, .LC33[rip]
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	jmp	.L39
.L38:
	call	__ctype_b_loc@PLT
	mov	rax, QWORD PTR [rax]
	mov	edx, DWORD PTR optopt[rip]
	movsx	rdx, edx
	add	rdx, rdx
	add	rax, rdx
	movzx	eax, WORD PTR [rax]
	movzx	eax, ax
	and	eax, 16384
	test	eax, eax
	je	.L40
	mov	edx, DWORD PTR optopt[rip]
	mov	rax, QWORD PTR stderr[rip]
	lea	rsi, .LC34[rip]
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	jmp	.L39
.L40:
	mov	edx, DWORD PTR optopt[rip]
	mov	rax, QWORD PTR stderr[rip]
	lea	rsi, .LC35[rip]
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
.L39:
	mov	eax, 1
	jmp	.L41
.L45:
	call	abort@PLT
.L33:
	mov	rcx, QWORD PTR -48[rbp]
	mov	eax, DWORD PTR -36[rbp]
	lea	rdx, .LC36[rip]
	mov	rsi, rcx
	mov	edi, eax
	call	getopt@PLT
	mov	DWORD PTR -12[rbp], eax
	cmp	DWORD PTR -12[rbp], -1
	jne	.L42
	mov	eax, DWORD PTR optind[rip]
	mov	DWORD PTR -24[rbp], eax
	jmp	.L43
.L44:
	mov	eax, DWORD PTR -24[rbp]
	cdqe
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -48[rbp]
	add	rax, rdx
	mov	rax, QWORD PTR [rax]
	mov	rsi, rax
	lea	rdi, .LC37[rip]
	mov	eax, 0
	call	printf@PLT
	add	DWORD PTR -24[rbp], 1
.L43:
	mov	eax, DWORD PTR -24[rbp]
	cmp	eax, DWORD PTR -36[rbp]
	jl	.L44
	mov	eax, 0
.L41:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	main, .-main
	.ident	"GCC: (GNU) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
