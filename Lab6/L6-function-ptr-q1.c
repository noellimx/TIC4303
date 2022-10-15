/*
 * TIC4303
 * Lab 6 (c) Roland Yap
 */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>

#define L (32)

int addnum(int a)
{
	return a + 255;
}

int main(int argc, char *argv[], char *envp[])
{
	int a, (*f)(int), *code_buf;

	char *p, data[] = {0x0f, 0x0b};

	f = NULL;


	char buf[256];

	printf("\n\nMemory Map from /proc/%d/maps\n", getpid());
	sprintf(buf, "cat /proc/%d/maps", getpid());
	system(buf);


	a = f(10);
	printf("0: f(10)=%d f=%p\n\n", a, f);



	/* Try uncommenting out */
	/*

	*/

	f = addnum;
	a = f(10); // LINE1
	printf("1: f(10)=%d f=%p\n\n", a, f);

	code_buf = (int *)mmap(0, 4096, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	/* Try swapping the two mmap lines */
	// code_buf = (int *) mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	printf("code_buf %p\n", code_buf);
	memcpy(code_buf, addnum, L);
	f = (int (*)(int))code_buf;
	a = f(10); // LINE2
	printf("2: f(10)=%d f=%p\n\n", a, f);

	p = index((char *)code_buf, 0xff);
	printf("before *p=%hhx\n", *p);
	*p = 100;
	printf("after *p=%hhx\n", *p);
	a = f(10); // LINE3
	printf("3: f(10)=%d\n\n", a);

	*((char *)code_buf) = 0xc3;
	a = f(10); // LINE4
	printf("4: f(10)=%d\n\n", a);

	memcpy(code_buf, data, 2);
	printf("before last call\n");
	a = f(10); // LINE5

	return 0;
}