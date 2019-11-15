#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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
    integer_array = (int *)malloc(size);
    
    printf(" Input %d integer digits:\n",size);
    for(i=0;i<size;i++)
		scanf("%d",&integer_array[i]);

    printf("the biggest:\n%d\n", biggest(integer_array,size));

    return 0;
}
