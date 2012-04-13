chars = 0
size = 4
.text
	.globl create_string_asm
create_string_asm:
	pushl %ebp
	movl %esp, %ebp
	subl $(4+12), %esp
	andl $-16, %esp

size_loc=-4
str_param=8
val_param=12
	## size_t size = strlen(val);
	movl val_param(%ebp), %eax
	movl %eax, 0(%esp)
	call strlen
	movl %eax, size_loc(%ebp)

	## str->size = size;
	movl size_loc(%ebp), %eax
	movl str_param(%ebp), %ecx
	movl %eax, size(%ecx)

	## str->chars = malloc(size);
	movl size_loc(%ebp), %eax
	movl %eax, 0(%esp)
	call malloc
	movl str_param(%ebp), %ecx
	movl %eax, chars(%ecx)

	## memcpy(str->chars, val, size);
	movl str_param(%ebp), %eax
	movl chars(%eax), %eax
	movl %eax, 0(%esp)
	movl val_param(%ebp), %eax
	movl %eax, 4(%esp)
	movl size_loc(%ebp), %eax
	movl %eax, 8(%esp)
	call memcpy

	leave
	ret

	.globl delete_string_asm
delete_string_asm:
	pushl %ebp
	movl %esp, %ebp
	subl $4, %esp
	andl $-16, %esp

	## free(v.chars);
	movl 8(%ebp), %eax
	movl %eax, 0(%esp)
	call free

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
	andl $-16, %esp

	## char *cstr = c_string(v);
	movl 8(%ebp), %eax
	movl %eax, 0(%esp)
	movl 12(%ebp), %eax
	movl %eax, 4(%esp)
	call c_string_asm
	movl %eax, -4(%ebp)

	## printf("%s", cstr);
	movl $percent_s, 0(%esp)
	movl -4(%ebp), %eax
	movl %eax, 4(%esp)
	call printf

	## free(cstr);
	movl -4(%ebp), %eax
	movl %eax, 0(%esp)
	call free

	leave
	ret

	.globl string_length_asm
string_length_asm:
	pushl %ebp
	movl %esp, %ebp
	# pas necessaire ici, mais ca n'aurait pas ete
	# grave de le mettre :
	# andl $-16, %esp

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
	andl $-16, %esp

res_loc=-4
	## char *res = malloc(v.size + 1);
	movl 12(%ebp), %eax
	addl $1, %eax
	movl %eax, 0(%esp)
	call malloc
	movl %eax, res_loc(%ebp)

	## memcpy(res, v.chars, v.size);
	movl res_loc(%ebp), %eax
	movl %eax, 0(%esp)
	movl 8(%ebp), %eax
	movl %eax, 4(%esp)
	movl 12(%ebp), %eax
	movl %eax, 8(%esp)
	call memcpy

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
	andl $-16, %esp

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
	movl $percent_c, 0(%esp)
	movl 8(%ebp), %eax
	addl i_loc(%ebp), %eax
	# zeros pour les bits de poids fort de %ecx
	movl $0, %ecx
	movb (%eax), %cl
	movl %ecx, 4(%esp)
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
	andl $-16, %esp

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
	movl $percent_c, 0(%esp)
	# zeros pour les bits de poids fort de %ecx
	movl $0, %ecx
	movb (%esi, %edi), %cl
	movl %ecx, 4(%esp)
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
        movl $8, 0(%esp)
        call malloc
        movl %eax, res_loc(%ebp)

        ## res->size = v1.size + v2.size;
        movl (v1_param+size)(%ebp), %eax
        movl (v2_param+size)(%ebp), %ecx
        addl %ecx, %eax
        movl res_loc(%ebp), %ecx
        movl %eax, size(%ecx)

        ## res->chars = malloc(res->size);
        movl res_loc(%ebp), %eax
        movl size(%eax), %eax
        movl %eax, 0(%esp)
        call malloc
        movl res_loc(%ebp), %ecx
        movl %eax, chars(%ecx)

        ## memcpy(res->chars, v1.chars, v1.size);
        movl (v1_param+size)(%ebp), %eax
        movl %eax, 8(%esp)
        movl (v1_param+chars)(%ebp), %eax
        movl %eax, 4(%esp)
        movl res_loc(%ebp), %eax
        movl chars(%eax), %eax
        movl %eax, 0(%esp)
        call memcpy

        ## memcpy(res->chars + v1.size, v2.chars, v2.size);
        movl (v2_param+size)(%ebp), %eax
        movl %eax, 8(%esp)
        movl (v2_param+chars)(%ebp), %eax
        movl %eax, 4(%esp)
        movl res_loc(%ebp), %eax
        movl chars(%eax), %eax
        addl (v1_param+size)(%ebp), %eax
        movl %eax, 0(%esp)
        call memcpy

        ## return res;
	movl res_loc(%ebp), %eax
	leave
	ret


