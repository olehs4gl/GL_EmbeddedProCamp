#include <stdio.h>
#include <stdint.h>

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

int main(void)
{
    char istring[101], ostring[100];

    printf("   Exercise 1\n");
    printf(" Input string (100 characters maximum!):\n");
    gets(istring);
    printf(" Output string:\n");
    copy_digits(istring,ostring);
    printf("%s\n",ostring);

    return 0;
}
