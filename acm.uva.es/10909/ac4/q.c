int main()
{
__asm__ __volatile__(
"	jmp	_main2\n"
"	.p2align 4,,15\n"
"_sol:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%ebx\n"
"	movl	8(%ebp), %ebx\n"
"	cmpl	$1, %ebx\n"
"	jle	L17\n"
"	testb	$1, %bl\n"
"	jne	L17\n"
"	movl	%ebx, %edx\n"
"	sarl	%edx\n"
"	testl	%edx, %edx\n"
"	jle	L17\n"
"	movl	%ebx, %eax\n"
"	sarl	$6, %eax\n"
"	movl	%edx, %ecx\n"
"	andl	$31, %ecx\n"
"	movl	_map(,%eax,4), %eax\n"
"	shrl	%cl, %eax\n"
"	testb	$1, %al\n"
"	jne	L5\n"
"	.p2align 4,,15\n"
"L8:\n"
"	decl	%edx\n"
"	testl	%edx, %edx\n"
"	jle	L17\n"
"	movl	%edx, %eax\n"
"	sarl	$5, %eax\n"
"	movl	%edx, %ecx\n"
"	andl	$31, %ecx\n"
"	movl	_map(,%eax,4), %eax\n"
"	shrl	%cl, %eax\n"
"	testb	$1, %al\n"
"	je	L8\n"
"L5:\n"
"	testl	%edx, %edx\n"
"	jle	L17\n"
"	.p2align 4,,15\n"
"L14:\n"
"	movl	%edx, %eax\n"
"	sarl	$5, %eax\n"
"	movl	%edx, %ecx\n"
"	andl	$31, %ecx\n"
"	movl	_map(,%eax,4), %eax\n"
"	shrl	%cl, %eax\n"
"	testb	$1, %al\n"
"	je	L11\n"
"	movl	%ebx, %ecx\n"
"	subl	%edx, %ecx\n"
"	movl	%ecx, %eax\n"
"	sarl	$5, %eax\n"
"	andl	$31, %ecx\n"
"	movl	_map(,%eax,4), %eax\n"
"	shrl	%cl, %eax\n"
"	movl	%edx, %ecx\n"
"	testb	$1, %al\n"
"	jne	L1\n"
"L11:\n"
"	subl	$2, %edx\n"
"	testl	%edx, %edx\n"
"	jg	L14\n"
"	.p2align 4,,15\n"
"L17:\n"
"	movl	$-1, %ecx\n"
"L1:\n"
"	movl	%ecx, %eax\n"
"	popl	%ebx\n"
"	popl	%ebp\n"
"	ret\n"
"	.p2align 4,,15\n"
"_find:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%ebx\n"
"	movl	8(%ebp), %ebx\n"
"	movl	_root, %ecx\n"
"	.p2align 4,,15\n"
"L28:\n"
"	movl	_left(,%ecx,4), %edx\n"
"	movl	_count(,%edx,4), %eax\n"
"	cmpl	%eax, %ebx\n"
"	jge	L23\n"
"	movl	%edx, %ecx\n"
"	jmp	L28\n"
"	.p2align 4,,7\n"
"L23:\n"
"	je	L27\n"
"	subl	%eax, %ebx\n"
"	leal	-1(%ebx), %ebx\n"
"	movl	_right(,%ecx,4), %ecx\n"
"	jmp	L28\n"
"L27:\n"
"	movl	_key(,%ecx,4), %eax\n"
"	popl	%ebx\n"
"	popl	%ebp\n"
"	ret\n"
"	.p2align 4,,15\n"
"_rem:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%ebx\n"
"	movl	8(%ebp), %ebx\n"
"	movl	_root, %ecx\n"
"	.p2align 4,,15\n"
"L60:\n"
"	decl	_count(,%ecx,4)\n"
"	movl	_left(,%ecx,4), %edx\n"
"	movl	_count(,%edx,4), %eax\n"
"	cmpl	%eax, %ebx\n"
"	jge	L33\n"
"	movl	%edx, %ecx\n"
"	jmp	L60\n"
"	.p2align 4,,7\n"
"L33:\n"
"	je	L31\n"
"	subl	%eax, %ebx\n"
"	leal	-1(%ebx), %ebx\n"
"	movl	_right(,%ecx,4), %ecx\n"
"	jmp	L60\n"
"L31:\n"
"	testl	%edx, %edx\n"
"	je	L61\n"
"	movl	_right(,%ecx,4), %ebx\n"
"	testl	%ebx, %ebx\n"
"	je	L37\n"
"	cmpl	%eax, _count(,%ebx,4)\n"
"	jl	L38\n"
"	movl	%ebx, %edx\n"
"	movl	_left(,%ebx,4), %eax\n"
"	testl	%eax, %eax\n"
"	je	L44\n"
"L43:\n"
"	decl	_count(,%edx,4)\n"
"	movl	%eax, %edx\n"
"	movl	_left(,%eax,4), %eax\n"
"	testl	%eax, %eax\n"
"	jne	L43\n"
"L44:\n"
"	movl	_key(,%edx,4), %eax\n"
"	movl	%eax, _key(,%ecx,4)\n"
"	movl	%edx, %ecx\n"
"	movl	_left(,%edx,4), %edx\n"
"L37:\n"
"	testl	%edx, %edx\n"
"	je	L61\n"
"L50:\n"
"	testl	%edx, %edx\n"
"	jne	L53\n"
"	movl	_right(,%ecx,4), %edx\n"
"L53:\n"
"	movl	_parent(,%ecx,4), %eax\n"
"	testl	%eax, %eax\n"
"	jne	L54\n"
"	movl	%edx, _root\n"
"	xorl	%eax, %eax\n"
"L56:\n"
"	movl	%eax, _parent(,%edx,4)\n"
"L29:\n"
"	popl	%ebx\n"
"	popl	%ebp\n"
"	ret\n"
"L54:\n"
"	cmpl	%ecx, _left(,%eax,4)\n"
"	je	L62\n"
"	movl	%edx, _right(,%eax,4)\n"
"	jmp	L56\n"
"L62:\n"
"	movl	%edx, _left(,%eax,4)\n"
"	jmp	L56\n"
"L61:\n"
"	movl	_right(,%ecx,4), %ebx\n"
"	testl	%ebx, %ebx\n"
"	jne	L50\n"
"	movl	_parent(,%ecx,4), %eax\n"
"	cmpl	%ecx, _left(,%eax,4)\n"
"	je	L63\n"
"	xorl	%edx, %edx\n"
"	movl	%edx, _right(,%eax,4)\n"
"	jmp	L29\n"
"L63:\n"
"	xorl	%ecx, %ecx\n"
"	movl	%ecx, _left(,%eax,4)\n"
"	jmp	L29\n"
"L38:\n"
"	movl	_right(,%edx,4), %eax\n"
"	testl	%eax, %eax\n"
"	je	L44\n"
"L49:\n"
"	decl	_count(,%edx,4)\n"
"	movl	%eax, %edx\n"
"	movl	_right(,%eax,4), %eax\n"
"	testl	%eax, %eax\n"
"	jne	L49\n"
"	jmp	L44\n"
"	.p2align 4,,15\n"
"_build:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	subl	$20, %esp\n"
"	movl	%ebx, -12(%ebp)\n"
"	movl	%esi, -8(%ebp)\n"
"	movl	%edi, -4(%ebp)\n"
"	movl	8(%ebp), %edx\n"
"	movl	12(%ebp), %edi\n"
"	cmpl	%edi, %edx\n"
"	je	L71\n"
"	leal	(%edi,%edx), %esi\n"
"	sarl	%esi\n"
"	xorl	%eax, %eax\n"
"	cmpl	%esi, %edx\n"
"	jl	L72\n"
"L68:\n"
"	movl	_last, %ebx\n"
"	incl	%ebx\n"
"	movl	%ebx, _last\n"
"	movl	%eax, _left(,%ebx,4)\n"
"	incl	%esi\n"
"	cmpl	%edi, %esi\n"
"	jle	L73\n"
"L69:\n"
"	movl	_left(,%ebx,4), %ecx\n"
"	movl	_right(,%ebx,4), %edx\n"
"	movl	_count(,%edx,4), %eax\n"
"	movl	_count(,%ecx,4), %esi\n"
"	addl	%esi, %eax\n"
"	incl	%eax\n"
"	movl	%eax, _count(,%ebx,4)\n"
"	movl	%ebx, _parent(,%edx,4)\n"
"	movl	%ebx, _parent(,%ecx,4)\n"
"	movl	%ebx, %eax\n"
"L64:\n"
"	movl	-12(%ebp), %ebx\n"
"	movl	-8(%ebp), %esi\n"
"	movl	-4(%ebp), %edi\n"
"	movl	%ebp, %esp\n"
"	popl	%ebp\n"
"	ret\n"
"	.p2align 4,,7\n"
"L73:\n"
"	movl	%edi, 4(%esp)\n"
"	movl	%esi, (%esp)\n"
"	call	_build\n"
"	movl	%eax, _right(,%ebx,4)\n"
"	jmp	L69\n"
"	.p2align 4,,7\n"
"L72:\n"
"	leal	-1(%esi), %eax\n"
"	movl	%eax, 4(%esp)\n"
"	movl	%edx, (%esp)\n"
"	call	_build\n"
"	jmp	L68\n"
"	.p2align 4,,7\n"
"L71:\n"
"	movl	_last, %eax\n"
"	incl	%eax\n"
"	movl	%eax, _last\n"
"	movl	$1, %edi\n"
"	movl	%edi, _count(,%eax,4)\n"
"	jmp	L64\n"
"	.p2align 4,,15\n"
"_rec:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%esi\n"
"	pushl	%ebx\n"
"	subl	$4, %esp\n"
"	movl	8(%ebp), %ebx\n"
"	testl	%ebx, %ebx\n"
"	je	L82\n"
"	movl	$1, %esi\n"
"	.p2align 4,,15\n"
"L80:\n"
"	movl	_key(,%ebx,4), %ecx\n"
"	movl	%ecx, %eax\n"
"	sarl	$5, %eax\n"
"	andl	$31, %ecx\n"
"	movl	%esi, %edx\n"
"	sall	%cl, %edx\n"
"	orl	%edx, _map(,%eax,4)\n"
"	movl	_left(,%ebx,4), %eax\n"
"	movl	%eax, (%esp)\n"
"	call	_rec\n"
"	movl	_right(,%ebx,4), %ebx\n"
"	testl	%ebx, %ebx\n"
"	jne	L80\n"
"L82:\n"
"	popl	%eax\n"
"	popl	%ebx\n"
"	popl	%esi\n"
"	popl	%ebp\n"
"	ret\n"
"	.p2align 4,,15\n"
"_make:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%edi\n"
"	pushl	%esi\n"
"	pushl	%ebx\n"
"	subl	$12, %esp\n"
"	xorl	%esi, %esi\n"
"	movl	%esi, _last\n"
"	xorl	%ebx, %ebx\n"
"	movl	%ebx, _count\n"
"	movl	$333680, %ecx\n"
"	movl	%ecx, 4(%esp)\n"
"	movl	$0, (%esp)\n"
"	call	_build\n"
"	movl	%eax, _root\n"
"	xorl	%edx, %edx\n"
"	movl	%edx, _parent(,%eax,4)\n"
"	movl	$1, %ebx\n"
"	movl	$1, %esi\n"
"	.p2align 4,,15\n"
"L88:\n"
"	movl	%esi, _key(,%ebx,4)\n"
"	incl	%ebx\n"
"	leal	2(%esi), %eax\n"
"	movl	%eax, _key(,%ebx,4)\n"
"	incl	%ebx\n"
"	addl	$6, %esi\n"
"	cmpl	$333690, %ebx\n"
"	jle	L88\n"
"	movl	$2, %edi\n"
"L89:\n"
"	movl	%edi, (%esp)\n"
"	call	_find\n"
"	leal	-1(%eax), %esi\n"
"	movl	_root, %eax\n"
"	cmpl	_count(,%eax,4), %esi\n"
"	jge	L90\n"
"	movl	%esi, %ebx\n"
"L97:\n"
"	movl	%ebx, (%esp)\n"
"	call	_rem\n"
"	addl	%esi, %ebx\n"
"	movl	_root, %eax\n"
"	cmpl	_count(,%eax,4), %ebx\n"
"	jl	L97\n"
"	incl	%edi\n"
"	jmp	L89\n"
"L90:\n"
"	movl	%eax, (%esp)\n"
"	call	_rec\n"
"	addl	$12, %esp\n"
"	popl	%ebx\n"
"	popl	%esi\n"
"	popl	%edi\n"
"	popl	%ebp\n"
"	ret\n"
"LC1:\n"
"	.ascii \" is the sum of \\0\"\n"
"	.align 32\n"
"LC0:\n"
"	.ascii \" is not the sum of two luckies!\\12\\0\"\n"
"	.p2align 4,,15\n"
"_main2:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%edi\n"
"	pushl	%esi\n"
"	pushl	%ebx\n"
"	subl	$44, %esp\n"
"	movl	$48, -24(%ebp)\n"
"	.p2align 4,,15\n"
"L107:\n"
"	movl	-24(%ebp), %eax\n"
"	movl	$1, %ecx\n"
"	movl	%ecx, _isdigx.4(,%eax,4)\n"
"	movl	$1, %edx\n"
"	movl	%edx, _isdig.3(,%eax,4)\n"
"	incl	%eax\n"
"	movl	%eax, -24(%ebp)\n"
"	cmpl	$57, %eax\n"
"	jle	L107\n"
"	movl	$1, %eax\n"
"	movl	%eax, _isdigx.4\n"
"	movl	$1048576, %edi\n"
"	movl	%edi, 8(%esp)\n"
"	movl	$_inbuf.0, -20(%ebp)\n"
"	movl	$_inbuf.0, %esi\n"
"	movl	%esi, 4(%esp)\n"
"	movl	$0, (%esp)\n"
"	call	read\n"
"	movb	$0, _inbuf.0(%eax)\n"
"	movl	$_outbuf.1, %esi\n"
"	call	_make\n"
"	.p2align 4,,15\n"
"L182:\n"
"	movl	-20(%ebp), %eax\n"
"	movzbl	(%eax), %edx\n"
"	movsbl	%dl,%eax\n"
"	movl	_isdigx.4(,%eax,4), %ebx\n"
"	testl	%ebx, %ebx\n"
"	jne	L163\n"
"	.p2align 4,,15\n"
"L114:\n"
"	incl	-20(%ebp)\n"
"	movl	-20(%ebp), %eax\n"
"	movzbl	(%eax), %edx\n"
"	movsbl	%dl,%eax\n"
"	movl	_isdigx.4(,%eax,4), %ecx\n"
"	testl	%ecx, %ecx\n"
"	je	L114\n"
"L163:\n"
"	testb	%dl, %dl\n"
"	je	L109\n"
"	movsbl	%dl,%eax\n"
"	leal	-48(%eax), %edi\n"
"	incl	-20(%ebp)\n"
"	movl	-20(%ebp), %edx\n"
"	movsbl	(%edx),%eax\n"
"	movl	_isdig.3(,%eax,4), %edx\n"
"	testl	%edx, %edx\n"
"	je	L165\n"
"	movl	%eax, %edx\n"
"	.p2align 4,,15\n"
"L120:\n"
"	leal	(%edi,%edi,4), %eax\n"
"	leal	-48(%edx,%eax,2), %edi\n"
"	incl	-20(%ebp)\n"
"	movl	-20(%ebp), %edx\n"
"	movsbl	(%edx),%eax\n"
"	movl	%eax, %edx\n"
"	movl	_isdig.3(,%eax,4), %eax\n"
"	testl	%eax, %eax\n"
"	jne	L120\n"
"L165:\n"
"	movl	%edi, (%esp)\n"
"	call	_sol\n"
"	movl	%eax, -24(%ebp)\n"
"	movl	%edi, %ecx\n"
"	movl	$_tmp.2, %ebx\n"
"	testl	%edi, %edi\n"
"	jle	L167\n"
"	.p2align 4,,15\n"
"L125:\n"
"	movl	$1717986919, %eax\n"
"	imull	%ecx\n"
"	movl	%eax, -32(%ebp)\n"
"	movl	%edx, -28(%ebp)\n"
"	movl	-28(%ebp), %edx\n"
"	sarl	$2, %edx\n"
"	movl	%ecx, %eax\n"
"	sarl	$31, %eax\n"
"	subl	%eax, %edx\n"
"	leal	(%edx,%edx,4), %eax\n"
"	addl	%eax, %eax\n"
"	subl	%eax, %ecx\n"
"	movb	%cl, %al\n"
"	addb	$48, %al\n"
"	movb	%al, (%ebx)\n"
"	incl	%ebx\n"
"	movl	%edx, %ecx\n"
"	testl	%edx, %edx\n"
"	jg	L125\n"
"L167:\n"
"	decl	%ebx\n"
"	cmpl	$_tmp.2-1, %ebx\n"
"	jbe	L169\n"
"	.p2align 4,,15\n"
"L129:\n"
"	movzbl	(%ebx), %eax\n"
"	movb	%al, (%esi)\n"
"	incl	%esi\n"
"	decl	%ebx\n"
"	cmpl	$_tmp.2-1, %ebx\n"
"	ja	L129\n"
"L169:\n"
"	movl	-24(%ebp), %eax\n"
"	testl	%eax, %eax\n"
"	js	L183\n"
"	movl	$LC1, %ebx\n"
"	movzbl	LC1, %eax\n"
"	testb	%al, %al\n"
"	je	L173\n"
"	.p2align 4,,15\n"
"L141:\n"
"	incl	%ebx\n"
"	movb	%al, (%esi)\n"
"	incl	%esi\n"
"	movzbl	(%ebx), %eax\n"
"	testb	%al, %al\n"
"	jne	L141\n"
"L173:\n"
"	movl	-24(%ebp), %ecx\n"
"	movl	$_tmp.2, %ebx\n"
"	testl	%ecx, %ecx\n"
"	jle	L175\n"
"	.p2align 4,,15\n"
"L146:\n"
"	movl	$1717986919, %eax\n"
"	imull	%ecx\n"
"	sarl	$2, %edx\n"
"	movl	%ecx, %eax\n"
"	sarl	$31, %eax\n"
"	subl	%eax, %edx\n"
"	leal	(%edx,%edx,4), %eax\n"
"	addl	%eax, %eax\n"
"	subl	%eax, %ecx\n"
"	movb	%cl, %al\n"
"	addb	$48, %al\n"
"	movb	%al, (%ebx)\n"
"	incl	%ebx\n"
"	movl	%edx, %ecx\n"
"	testl	%edx, %edx\n"
"	jg	L146\n"
"L175:\n"
"	decl	%ebx\n"
"	cmpl	$_tmp.2-1, %ebx\n"
"	jbe	L177\n"
"	.p2align 4,,15\n"
"L150:\n"
"	movzbl	(%ebx), %eax\n"
"	movb	%al, (%esi)\n"
"	incl	%esi\n"
"	decl	%ebx\n"
"	cmpl	$_tmp.2-1, %ebx\n"
"	ja	L150\n"
"L177:\n"
"	movb	$32, (%esi)\n"
"	incl	%esi\n"
"	movb	$97, (%esi)\n"
"	incl	%esi\n"
"	movb	$110, (%esi)\n"
"	incl	%esi\n"
"	movb	$100, (%esi)\n"
"	incl	%esi\n"
"	movb	$32, (%esi)\n"
"	incl	%esi\n"
"	movl	%edi, %ecx\n"
"	movl	-24(%ebp), %eax\n"
"	subl	%eax, %ecx\n"
"	movl	$_tmp.2, %ebx\n"
"	testl	%ecx, %ecx\n"
"	jle	L179\n"
"	movl	$1717986919, %edi\n"
"	.p2align 4,,15\n"
"L155:\n"
"	movl	%ecx, %eax\n"
"	imull	%edi\n"
"	sarl	$2, %edx\n"
"	movl	%ecx, %eax\n"
"	sarl	$31, %eax\n"
"	subl	%eax, %edx\n"
"	leal	(%edx,%edx,4), %eax\n"
"	addl	%eax, %eax\n"
"	subl	%eax, %ecx\n"
"	movb	%cl, %al\n"
"	addb	$48, %al\n"
"	movb	%al, (%ebx)\n"
"	incl	%ebx\n"
"	movl	%edx, %ecx\n"
"	testl	%edx, %edx\n"
"	jg	L155\n"
"L179:\n"
"	decl	%ebx\n"
"	cmpl	$_tmp.2-1, %ebx\n"
"	jbe	L181\n"
"	.p2align 4,,15\n"
"L159:\n"
"	movzbl	(%ebx), %eax\n"
"	movb	%al, (%esi)\n"
"	incl	%esi\n"
"	decl	%ebx\n"
"	cmpl	$_tmp.2-1, %ebx\n"
"	ja	L159\n"
"L181:\n"
"	movb	$46, (%esi)\n"
"	incl	%esi\n"
"	movb	$10, (%esi)\n"
"	incl	%esi\n"
"	jmp	L182\n"
"L183:\n"
"	movl	$LC0, %ebx\n"
"	movzbl	LC0, %eax\n"
"	testb	%al, %al\n"
"	je	L182\n"
"	.p2align 4,,15\n"
"L135:\n"
"	incl	%ebx\n"
"	movb	%al, (%esi)\n"
"	incl	%esi\n"
"	movzbl	(%ebx), %eax\n"
"	testb	%al, %al\n"
"	jne	L135\n"
"	jmp	L182\n"
"L109:\n"
"	subl	$_outbuf.1, %esi\n"
"	movl	%esi, 8(%esp)\n"
"	movl	$_outbuf.1, %edi\n"
"	movl	%edi, 4(%esp)\n"
"	movl	$1, (%esp)\n"
"	call	write\n"
"	movl	$0, (%esp)\n"
"	call	exit\n"
".p2align 4,,15\n"
".align 1024\n"
".lcomm _last,16\n"
".lcomm _root,16\n"
".lcomm _tmp.2,256\n"
".lcomm _isdig.3,1024\n"
".lcomm _isdigx.4,1024\n"
".lcomm _map,262144\n"
".lcomm _left,1334800\n"
".lcomm _right,1334800\n"
".lcomm _parent,1334800\n"
".lcomm _key,1334800\n"
".lcomm _count,1334800\n"
".lcomm _inbuf.0,1048576\n"
".lcomm _outbuf.1,8388608\n"
);
}
