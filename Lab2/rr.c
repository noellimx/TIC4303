/*
 * CS4239
 * Lab 22 (c) Roland Yap
 */

#include <stdlib.h>
#include <stdio.h>

int glob = 42;

void setvalue(char *p, char v)
{

	printf("assign value %c to pointer %s", v, p);
	*p = v;
}

int main(int argc, char *argv[], char *envp[])
{
	char *p, *hello = "world", string[] = "1234";
	int *q;
	int choice = 1;

	printf("no of args %d \n", argc);
	if (argc > 1)
	{

		printf("first arg value is %s\n", argv[1]);
		choice = atoi(argv[1]);
	}
	else
	{
		printf("no choice specified\n");
		return 0;
	}
	printf("choice %d\n", choice);

	switch (choice)
	{
	case 1:
		p = 0;
		printf("in case 1, p reassigned\n");

		printf("WHAT IS NULL %d\n", NULL);
		setvalue(p, 0);
		break;
	case 2:
		p = hello;
		setvalue(p, 'W');
		break;
	case 3:
		p = string;
		setvalue(p, '0');
		break;
	case 4:
		p = 0;
		choice = *p;
		break;
	case 5:
		p = (char *)&choice;
		setvalue(p, 5);
		break;
		/**
			case 6:
				q = (int *) 0x400000;
				printf("@%p = %x\n", q, *q);
				break;
			case 7:
				p = (char *) 0x404040;
				setvalue(p, 7);
				break;
		**/
	case 8:
		p = (char *)0x400000000000;
		setvalue(p, 8);
		break;
	}
	return 0;
}
