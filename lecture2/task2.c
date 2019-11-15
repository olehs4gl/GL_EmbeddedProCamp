#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct my_ll {
	int number;
	char name[16];
	struct my_ll *next;
} myll;

int copy_digits(char *inputs,char *outputs)
{
    uint8_t i=0,j=0;
	while(inputs[i])
	{
		if((inputs[i] >= '0')&&(inputs[i] <= '9'))
		{
			outputs[j++] = inputs[i];
		}
		i++;
	}
	outputs[j] = 0;
	return 0;
}

int biggest(int *inputa, int size)
{
    int bige = inputa[0];
    for(int i = 1;i<size;i++)
    {
		if(bige < inputa[i]) bige = inputa[i];
	}
	return bige;
}

myll *ListAdd(myll *pnext)
{
	myll *nem = (myll *)malloc(sizeof(myll));
	printf("input name (max 15 charcters):\n");
	scanf("%s",nem->name);
	printf("input number:\n");
	scanf("%d",&nem->number);
	nem->next = pnext;
	return nem;
}

int *ListLs(myll *pnext)
{
	myll *pn = pnext;
	while(pn != NULL)
	{
		printf("%s   %d\n",pn->name,pn->number);
		pn = pn->next;
	}
	return 0;
}

int main(void)
{
 /*   char istring[101], ostring[100];
    int size,i,*integer_array;

    printf("   Exercise 1\n");
    printf(" Input string (100 characters maximum!):\n");
    gets(istring);
    printf(" Output string:\n");
    copy_digits(istring,ostring);
    printf("%s\n",ostring);

    printf("   Exercise 2\n");
    printf(" Input array size:\n");
    scanf("%d",&size);
    integer_array = (int *)malloc(size);
    
    printf(" Input %d integer digits:\n",size);
    for(i=0;i<size;i++)
		scanf("%d",&integer_array[i]);

    printf("the biggest:\n%d\n", biggest(integer_array,size));
    free(integer_array);
*/
    printf("   Exercise 3\n");

	myll *pml,*pm2;
	pml = ListAdd(NULL);
	pm2 = ListAdd(pml);
	ListLs(pm2);
	free(pm2);
	free(pml);

    return 0;
}
