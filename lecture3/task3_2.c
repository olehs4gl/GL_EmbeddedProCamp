#include <stdlib.h>

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

int PrintStack(int *p_element,int number)
{
	if(number<1)return 0;
	os_stack *p_stack = my_stack;
	do{
		if(p_stack == NULL)return 0;
		if(--number)p_stack = p_stack -> next;
	}while(number);

	*p_element = p_stack->number;
	return 1;
}
