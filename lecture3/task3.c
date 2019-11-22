#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "task3.h"

void copy_string(char *inputs,char *outputs)
{
	uint8_t i=0;
	while(outputs[i] = inputs[i])i++;
}

typedef struct os_stack {
	int number;
	struct os_stack *next;
} os_stack;

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

//retrieve last element from my STACK
//if successful returns nonzero, otherwise return zero
int Pop(int *last_element)
{
	if(my_stack == NULL)return 0;
	*last_element = my_stack->number;
	os_stack *p = my_stack->next;
	free(my_stack);
	my_stack = p;
	return 1;
}

//read last element from my STACK
//if successful returns nonzero, otherwise return zero
int Read(int *last_element)
{
	if(my_stack == NULL)return 0;
	*last_element = my_stack->number;
	return 1;
}

int os_queue[queue_size];
int os_size = 0;
//pb_queue - pointer to the begin of my queue
//pe_queue - pointer to the end of my queue
int *pb_queue=os_queue, *pe_queue=os_queue;

int PutQueue(int element)
{
	if(os_size >= queue_size){return 0;}

	if((pe_queue - os_queue) >= queue_size)
	{
		pe_queue = os_queue;
	}

	*pe_queue = element;
	pe_queue++;
	os_size++;

	return 1;
}
