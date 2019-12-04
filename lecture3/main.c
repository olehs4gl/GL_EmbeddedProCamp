#include <stdio.h>

#include "task3_1.h"
#include "task3_2.h"
#include "task3_3.h"
#include "task3_4.h"

int main(void)
{
	char istring[101], ostring[100];
	int digit;
	char my_char;

	printf("   Exercise 1\n");
	printf(" Input string (100 characters maximum!):\n");
	gets(istring);
	printf(" Output string:\n");
	copy_string(istring,ostring);
	printf("%s\n",ostring);

	printf("   Exercise 2\n");
	printf("   to push element into stack press 'p'\n");
	printf("   to pop element from stack press 'g'\n");
	printf("   to read element from stack press 'r'\n");
	printf("   to list full stack press 'l'\n");
	printf("   to quit from Exercise 2 press 'q'\n");
	do{
		my_char = getchar();
		if(my_char == 'p')
		{
			printf("input digit to push into stack: ");scanf("%d",&digit);
			if(Push(digit) == 1)
			{
				printf("  Digit %d is pushed into stack!\n",digit);
			}
			else
			{
				printf("  Cannot push digit in stack!\n");
			}
		}
		else if(my_char == 'g')
		{
			if(Pop(&digit) == 1)
			{
				printf("  Pop %d from stack\n",digit);
			}
			else
			{
				printf("  Cannot pop digit from stack!\n");
			}
		}
		else if(my_char == 'r')
		{
			if(Read(&digit) == 1)
			{
				printf("  Read %d from stack\n",digit);
			}
			else
			{
				printf("  Cannot read digit from stack!\n");
			}
		}
		else if(my_char == 'l')
		{
			int i=1;
			while(PrintStack(&digit,i++) != 0)
			{
				printf("%d\n",digit);
			}
		}
	}while(my_char != 'q');


	printf("   Exercise 3\n");
	printf("   to put element into queue press 'p'\n");
	printf("   to get element from queue press 'g'\n");
	printf("   to read element from queue press 'r'\n");
	printf("   to list full queue press 'l'\n");
	printf("   to quit from Exercise 3 press 'q'\n");
	do{
		my_char = getchar();
		if(my_char == 'p')
		{
			printf("input digit to put into queue: ");scanf("%d",&digit);
			if(PutQueue(digit) == 1)
			{
				printf("  Digit %d puts into queue\n",digit);
			}
			else
			{
				printf("  Cannot put digit into queue!\n");
			}
		}
		else if(my_char == 'g')
		{
			if(GetQueue(&digit) == 1)
			{
				printf("  Get %d from queue\n",digit);
			}
			else
			{
				printf("  Cannot get digit from queue!\n");
			}
		}
		else if(my_char == 'r')
		{
			if(ReadQueue(&digit) == 1)
			{
				printf("  Read %d from queue\n",digit);
			}
			else
			{
				printf("  Cannot read digit from queue!\n");
			}
		}
		else if(my_char == 'l')
		{
			int i=1;
			while(PrintQueue(&digit,i++) != 0)
			{
				printf("%d\n",digit);
			}
		}
	}while(my_char != 'q');


	printf("   Exercise 4\n");
	if(CopyRead(ReadQueue,&digit) == 1)
	{
		printf("  Read %d from queue\n",digit);
	}
	else
	{
		printf("  Cannot read digit from queue!\n");
	}

	return 0;
}
