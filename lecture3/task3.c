#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "task3.h"

void copy_string(char *inputs,char *outputs)
{
	uint8_t i=0;
	while(outputs[i] = inputs[i])i++;
}

os_stack *my_stack = NULL;

//allocates new element in memory (STACK)
//if successful returns nonzero, otherwise return zero
int Push(int new_element)
{
	os_stack *p_new_element = (os_stack *)malloc(sizeof(os_stack));
	if(p_new_element == NULL)return 0;
	p_new_element->number = new_element;
	p_new_element->next = my_stack;
	my_stack = p_new_element;
	return 1;
}
