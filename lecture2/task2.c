#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "task2.h"

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
