#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "task2.h"

void copy_digits(char *inputs,char *outputs)
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
}

int biggest(int *inputa, int size)
{
	int biggest_ = inputa[0];
	for(int i = 1;i<size;i++)
	{
		if(biggest_ < inputa[i]) biggest_ = inputa[i];
	}
	return biggest_;
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

void ListLs(myll *pstart)
{
	myll *pn = pstart;
	while(pn != NULL)
	{
		printf("%s   %d\n",pn->name,pn->number);
		pn = pn->next;
	}
}

//remove all records starting from 'pn' from list
void ListRemoveAll(myll *pn)
{
	if(pn->next != NULL)
	{
		ListRemoveAll(pn->next);
		free(pn);
	}
}

//remove record 'premove' from list
//return 0 when record was removed or 1 when didn't find the record
int ListRemove(myll *pn,myll *premove)
{
	if(pn->next != NULL)
	{
		if(pn->next == premove)
		{
			pn->next = premove->next;
			free(premove);
			return 0;
		}
		return ListRemove(pn->next, premove);
	}
	return 1;
}

int main(void)
{
	char istring[101], ostring[100];
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
	integer_array = (int *)malloc(size*sizeof(int));

	printf(" Input %d integer digits:\n",size);
	for(i=0;i<size;i++)
		scanf("%d",&integer_array[i]);

	printf("the biggest:\n%d\n", biggest(integer_array,size));
	free(integer_array);

	printf("   Exercise 3\n");
	printf("(test example is made for 5 records of (name, number))\n");

	myll *pml,*prtr;
	pml = ListAdd(NULL);
	pml = ListAdd(pml);
	pml = ListAdd(pml);
	prtr = pml;
	pml = ListAdd(pml);
	pml = ListAdd(pml);
	printf("all list:\n");
	ListLs(pml);
	ListRemove(pml,prtr);
	printf("list after removed third record:\n");
	ListLs(pml);
	ListRemoveAll(pml);

	return 0;
}
