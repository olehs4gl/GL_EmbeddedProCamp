#include "task3_3.h"

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

int GetQueue(int *p_element)
{
	if(os_size == 0)return 0;

	if((pb_queue - os_queue) >= queue_size)
	{
		pb_queue = os_queue;
	}

	*p_element = *pb_queue;
	pb_queue++;
	os_size--;

	return 1;
}

int ReadQueue(int *p_element)
{
	if(os_size == 0)return 0;
	*p_element = *pb_queue;
	return 1;
}

int PrintQueue(int *p_element,int number)
{
	if(number > os_size)return 0;
	if(number < 1)return 0;
	int *pc = pb_queue;
	pc += (number - 1);
	if(pc > (os_queue + queue_size))pc -= queue_size;
	*p_element = *pc;
	return 1;
}
