int main()
{
__asm__ __volatile__(
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%edi\n"
"	pushl	%esi\n"
"	pushl	%ebx\n"
"	subl	$28, %esp\n"
"	xorl	%ecx, %ecx\n"
"	.p2align 4,,15\n"
"	movl	$48, %ecx\n"
"L11:\n"
"	movl	$1, %eax\n"
"	movl	%eax, isdig(,%ecx,4)\n"
"	incl	%ecx\n"
"	cmpl	$57, %ecx\n"
"	jbe	L11\n"
"	movl	$1048576, %ecx\n"
"	movl	%ecx, 8(%esp)\n"
"	movl	$_inbuf, %esi\n"
"	movl	%esi, 4(%esp)\n"
"	movl	$0, (%esp)\n"
"	call	_read\n"
"	movl	$_outbuf, %edi\n"
"	movzbl	_inbuf, %edx\n"
"	movb	%dl, -13(%ebp)\n"
"L55:\n"
"	movsbl	-13(%ebp),%ebx\n"
"	movl	isdig(,%ebx,4), %edx\n"
"	testl	%edx, %edx\n"
"	jne	L46\n"
"	.p2align 4,,15\n"
"L18:\n"
"	incl	%esi\n"
"	movzbl	(%esi), %ebx\n"
"	movb	%bl, -13(%ebp)\n"
"	movsbl	%bl,%ecx\n"
"	movl	isdig(,%ecx,4), %edx\n"
"	testl	%edx, %edx\n"
"	je	L18\n"
"L46:\n"
"	movsbl	-13(%ebp),%ecx\n"
"	leal	-48(%ecx), %ebx\n"
"	incl	%esi\n"
"	movzbl	(%esi), %edx\n"
"	movb	%dl, -13(%ebp)\n"
"	movsbl	%dl,%eax\n"
"	movl	isdig(,%eax,4), %ecx\n"
"	testl	%ecx, %ecx\n"
"	je	L48\n"
"	movl	%eax, %edx\n"
"	.p2align 4,,15\n"
"L23:\n"
"	leal	(%ebx,%ebx,4), %ecx\n"
"	leal	-48(%edx,%ecx,2), %ebx\n"
"	incl	%esi\n"
"	movzbl	(%esi), %edx\n"
"	movb	%dl, -13(%ebp)\n"
"	movsbl	%dl,%ecx\n"
"	movl	%ecx, %edx\n"
"	movl	isdig(,%ecx,4), %eax\n"
"	testl	%eax, %eax\n"
"	jne	L23\n"
"L48:\n"
"	testl	%ebx, %ebx\n"
"	je	L13\n"
"	cmpl	$2, %ebx\n"
"	ja	L25\n"
"	xorl	%ecx, %ecx\n"
"	.p2align 4,,15\n"
"L30:\n"
"	movzbl	LC0(%ecx), %ebx\n"
"	movb	%bl, (%edi)\n"
"	incl	%edi\n"
"	incl	%ecx\n"
"	cmpl	$10, %ecx\n"
"	jbe	L30\n"
"	jmp	L55\n"
"L25:\n"

"	pushl	%edi\n"
"	pushl	%eax\n"
"	movl	%ebx, %ecx\n"
"	shrl	%ecx\n"
"	shrl	%ecx\n"
"	incl	%ecx\n"
"	movl	$825307441, %eax\n"
"	repnz	stosl\n"
"	popl	%eax\n"
"	popl	%edi\n"

"	pushl	%esi\n"
"	movl	%ebx, %esi\n"
"	shrl	%esi\n"
"	movl	$1, %ecx\n"
"	movl	$0, %edx\n"
".p2align 4,,15\n"


/*
ebx = n
edi = outp

ecx = x
edx = x^2-1 % n
esi = (n - 1)/2

((x+1)^2 - 1) % n = [x^2 - 1] + 2x + 1 % n

edx' = edx + ecx + ecx + 1
*/

"L40:\n"
"	movb	$48, (%edi,%edx)\n"
"	addl	%ecx, %edx\n"
"	addl	%ecx, %edx\n"
"	incl	%edx\n"
"	incl	%ecx\n"
"	cmp	%esi, %ecx\n"
"	ja	L41\n"
"	cmp	%ebx, %edx\n"
"	jb	L40\n"
"	movl	%edx, %eax\n"
"	xorl	%edx, %edx\n"
"	divl	%ebx\n"
"	jmp	L40\n"
"L41:\n"

#if 0
"L40:\n"
"	movl	%ecx, %eax\n"
"	mull	%eax\n"
"	addl	$-1, %eax\n"
"	adcl	$-1, %edx\n"
"	divl	%ebx\n"
"	movb	$48, (%edi,%edx)\n"
"	incl	%ecx\n"
"	cmpl	%esi, %ecx\n"
"	jbe	L40\n"
#endif

"	popl	%esi\n"
"	movb	$10, -1(%ebx,%edi)\n"
"	addl	%ebx, %edi\n"
"	jmp	L55\n"
"L13:\n"
"	subl	$_outbuf, %edi\n"
"	movl	%edi, 8(%esp)\n"
"	movl	$_outbuf, %esi\n"
"	movl	%esi, 4(%esp)\n"
"	movl	$1, (%esp)\n"
"	call	_write\n"
"	movl	$0, (%esp)\n"
"	call	_exit\n"
".p2align 4,,15\n"
".lcomm isdig,1024\n"
".p2align 4,,15\n"
"LC0:\n"
".ascii \"Impossible\\12\\0\"\n"
".p2align 4,,15\n"
".lcomm _inbuf, 1048576\n"
".lcomm _outbuf, 31457280\n"
);
}