#include "task3.c"

int main(void)
{
	char istring[101], ostring[100];

	printf("   Exercise 1\n");
	printf(" Input string (100 characters maximum!):\n");
	gets(istring);
	printf(" Output string:\n");
	copy_string(istring,ostring);
	printf("%s\n",ostring);

	return 0;
}
