chars = 0
size = 4
.text
	.globl create_string_asm
create_string_asm:
	pushl %ebp
	movl %esp, %ebp
	subl $4, %esp

size_loc=-4
str_param=8
val_param=12
	## size_t size = strlen(val);
	pushl val_param(%ebp)
	call strlen
	addl $4, %esp
	movl %eax, size_loc(%ebp)

	## str->size = size;
	movl size_loc(%ebp), %eax
	movl str_param(%ebp), %ecx
	movl %eax, size(%ecx)

	## str->chars = malloc(size);
	pushl size_loc(%ebp)
	call malloc
	addl $4, %esp
	movl str_param(%ebp), %ecx
	movl %eax, chars(%ecx)

	## memcpy(str->chars, val, size);
	pushl size_loc(%ebp)
	pushl val_param(%ebp)
	movl str_param(%ebp), %eax
	pushl chars(%eax)
	call memcpy
	addl $12, %esp

	leave
	ret

	.globl delete_string_asm
delete_string_asm:
	pushl %ebp
	movl %esp, %ebp
	subl $4, %esp

	## free(v.chars);
	pushl 8(%ebp)
	call free
	addl $4, %esp

	leave
	ret

.data
percent_s:	.asciz "%s"
.text
	.globl print_string_ext_asm
print_string_ext_asm:
	pushl %ebp
	movl %esp, %ebp
	subl $(4+4), %esp

	## char *cstr = c_string(v);
	pushl 12(%ebp)
	pushl 8(%ebp)
	call c_string_asm
	addl $8, %esp
	movl %eax, -4(%ebp)

	## printf("%s", cstr);
	pushl -4(%ebp)
	pushl $percent_s
	call printf
	addl $8, %esp

	## free(cstr);
	pushl -4(%ebp)
	call free
	addl $4, %esp

	leave
	ret

	.globl string_length_asm
string_length_asm:
	pushl %ebp
	movl %esp, %ebp

v_param=8
	## return v.size
	movl (v_param + size)(%ebp), %eax
	# on aurait aussi pu ecrire
	# movl 12(%ebp), %eax

	leave
	ret

	.globl c_string_asm
c_string_asm:
	pushl %ebp
	movl %esp, %ebp
	subl $(4+12), %esp

res_loc=-4
	## char *res = malloc(v.size + 1);
	movl 12(%ebp), %eax
	addl $1, %eax
	pushl %eax
	call malloc
	addl $4, %esp
	movl %eax, res_loc(%ebp)

	## memcpy(res, v.chars, v.size);
	pushl 12(%ebp)
	pushl 8(%ebp)
	pushl res_loc(%ebp)
	call memcpy
	addl $12, %esp

	## res[v.size] = '\0';
	movl res_loc(%ebp), %eax
	addl 12(%ebp), %eax
	movb $0, (%eax)

	## return res;
	movl res_loc(%ebp), %eax

	leave
	ret


.data
percent_c:	.asciz "%c"
.text
	.globl print_string_asm
print_string_asm:
	pushl %ebp
	movl %esp, %ebp
	subl $(8+4), %esp

	## int i;
i_loc = -4
	## i = 0
	movl $0, i_loc(%ebp)
	## while (i < v.size) {
start:
	movl i_loc(%ebp), %eax
	cmpl 12(%ebp), %eax
	jge end

	## 	printf("%c", v.chars[i]);
	movl 8(%ebp), %eax
	addl i_loc(%ebp), %eax
	# zeros pour les bits de poids fort de %ecx
	movl $0, %ecx
	movb (%eax), %cl
	pushl %ecx
	pushl $percent_c
	call printf
	##      i++;
	addl $1, i_loc(%ebp)
	## }
	jmp start
end:

	leave
	ret

	.globl print_string_asm_opt
print_string_asm_opt:
	pushl %ebp
	movl %esp, %ebp
	subl $8, %esp
	pushl %esi
	pushl %edi
	pushl %ebx

	movl 8(%ebp), %edi // v.chars
	movl 12(%ebp), %ebx // v.size
	## int i;
	## i = 0
	xorl %esi, %esi // i
	## while (i < v.size) {
start_opt:
	cmpl %ebx, %esi
	jge end_opt

	## 	printf("%c", v.chars[i]);
	# zeros pour les bits de poids fort de %ecx
	movl $0, %ecx
	movb (%esi, %edi), %cl
	pushl %ecx
	pushl $percent_c
	call printf
	##      i++;
	addl $1, %esi
	## }
	jmp start_opt
end_opt:

	movl -12(%ebp), %esi
	movl -16(%ebp), %edi
	movl -20(%ebp), %ebx
	leave
	ret

	.globl string_concat_asm
string_concat_asm:
	pushl %ebp
	movl %esp, %ebp
	subl $16, %esp
res_loc = -4
v1_param = 8
v2_param = 16
        ## struct string *res = malloc(sizeof(struct string));
        pushl $8
        call malloc
	addl $4, %esp
        movl %eax, res_loc(%ebp)

        ## res->size = v1.size + v2.size;
        movl (v1_param+size)(%ebp), %eax
        movl (v2_param+size)(%ebp), %ecx
        addl %ecx, %eax
        movl res_loc(%ebp), %ecx
        movl %eax, size(%ecx)

        ## res->chars = malloc(res->size);
        movl res_loc(%ebp), %eax
        pushl size(%eax)
        call malloc
	addl $4, %esp
        movl res_loc(%ebp), %ecx
        movl %eax, chars(%ecx)

        ## memcpy(res->chars, v1.chars, v1.size);
        pushl (v1_param+size)(%ebp)
        pushl (v1_param+chars)(%ebp)
        movl res_loc(%ebp), %eax
        pushl chars(%eax)
        call memcpy
	addl $12, %esp

        ## memcpy(res->chars + v1.size, v2.chars, v2.size);
        pushl (v2_param+size)(%ebp)
	pushl (v2_param+chars)(%ebp)
        movl res_loc(%ebp), %eax
        movl chars(%eax), %eax
        addl (v1_param+size)(%ebp), %eax
	pushl %eax
        call memcpy
	addl $12, %esp

        ## return res;
	movl res_loc(%ebp), %eax
	leave
	ret


