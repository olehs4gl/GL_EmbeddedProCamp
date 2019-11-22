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
	if(Read(&digit) == 1)
	{
		printf("  Last digit in stack is  %d\n",digit);
	}
	else
	{
		printf("  Cannot read digit from stack!\n");
	}
	if(Pop(&digit) == 1)
	{
		printf("  Last digit retrieved from stack is  %d\n",digit);
	}
	else
	{
		printf("  Cannot pop digit from stack!\n");
	}
	if(Read(&digit) == 1)
	{
		printf("  Last digit in stack is  %d\n",digit);
	}
	else
	{
		printf("  Cannot read digit from stack!\n");
	}
	if(Pop(&digit) == 1)
	{
		printf("  Last digit retrieved from stack is  %d\n",digit);
	}
	else
	{
		printf("  Cannot pop digit from stack!\n");
	}
	if(Read(&digit) == 1)
	{
		printf("  Last digit in stack is  %d\n",digit);
	}
	else
	{
		printf("  Cannot read digit from stack!\n");
	}

	printf("   Exercise 3\n");
	if(PutQueue(100) == 1){printf("  Put 100 in queue\n");}
	else{printf("  Cannot put digit in queue!\n");}

	if(PutQueue(309) == 1){printf("  Put 309 in queue\n");}
	else{printf("  Cannot put 309 in queue!\n");}

	if(PutQueue(1235) == 1){printf("  Put 1235 in queue\n");}
	else{printf("  Cannot put 1235 in queue!\n");}

	if(PutQueue(5550) == 1){printf("  Put 5550 in queue\n");}
	else{printf("  Cannot put 5550 in queue!\n");}

	if(PutQueue(10) == 1){printf("  Put 10 in queue\n");}
	else{printf("  Cannot put 10 in queue!\n");}

	if(PutQueue(-100) == 1){printf("  Put -100 in queue\n");}
	else{printf("  Cannot put -100 in queue!\n");}

	if(PutQueue(100) == 1){printf("  Put 100 in queue\n");}
	else{printf("  Cannot put 100 in queue!\n");}

	if(PutQueue(300) == 1){printf("  Put 300 in queue\n");}
	else{printf("  Cannot put 300 in queue!\n");}

	if(PutQueue(880) == 1){printf("  Put 880 in queue\n");}
	else{printf("  Cannot put 880 in queue!\n");}

	if(PutQueue(222) == 1){printf("  Put 222 in queue\n");}
	else{printf("  Cannot put 222 in queue!\n");}

	if(PutQueue(321) == 1){printf("  Put 321 in queue\n");}
	else{printf("  Cannot put 321 in queue!\n");}

	if(PutQueue(0) == 1){printf("  Put 0 in queue\n");}
	else{printf("  Cannot put 0 in queue!\n");}

	if(PutQueue(-57) == 1){printf("  Put -57 in queue\n");}
	else{printf("  Cannot put -57 in queue!\n");}

	if(PutQueue(900) == 1){printf("  Put 900 in queue\n");}
	else{printf("  Cannot put 900 in queue!\n");}

	if(PutQueue(202) == 1){printf("  Put 202 in queue\n");}
	else{printf("  Cannot put 202 in queue!\n");}

	return 0;
}
