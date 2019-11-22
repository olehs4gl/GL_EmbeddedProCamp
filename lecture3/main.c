#include "task3.c"

int main(void)
{
	char istring[101], ostring[100];
	int digit;

	printf("   Exercise 1\n");
	printf(" Input string (100 characters maximum!):\n");
	gets(istring);
	printf(" Output string:\n");
	copy_string(istring,ostring);
	printf("%s\n",ostring);

	printf("   Exercise 2\n");
	printf(" Input 3 digits to push in stack:\n");
	printf("input first digit: ");scanf("%d",&digit);
	if(Push(digit) == 1)
	{
		printf("  First digit is in stack!\n");
	}
	else
	{
		printf("  Cannot push first digit in stack!\n");
	}
	printf("input second digit: ");scanf("%d",&digit);
	if(Push(digit) == 1)
	{
		printf("  Second digit is in stack!\n");
	}
	else
	{
		printf("  Cannot push second digit in stack!\n");
	}
	printf("input third digit: ");scanf("%d",&digit);
	if(Push(digit) == 1)
	{
		printf("  Third digit is in stack!\n");
	}
	else
	{
		printf("  Cannot push third digit in stack!\n");
	}
	digit = 0;

	if(Pop(&digit) == 1)
	{
		printf("  Last digit retrieved from stack is  %d\n",digit);
	}
	else
	{
		printf("  Cannot pop digit from stack!\n");
	}
	if(Pop(&digit) == 1)
	{
		printf("  Last digit retrieved from stack is  %d\n",digit);
	}
	else
	{
		printf("  Cannot pop digit from stack!\n");
	}
	if(Pop(&digit) == 1)
	{
		printf("  Last digit retrieved from stack is  %d\n",digit);
	}
	else
	{
		printf("  Cannot pop digit from stack!\n");
	}
	if(Pop(&digit) == 1)
	{
		printf("  Last digit retrieved from stack is  %d\n",digit);
	}
	else
	{
		printf("  Cannot pop digit from stack!\n");
	}

	return 0;
}
