#include "AdptArray.h"
#include <stdlib.h>
#include <stdio.h>

struct AdptArray_
{
	PElement *arr;
	int size;
	COPY_FUNC copy_func;
	DEL_FUNC delete_func;
	PRINT_FUNC print_func;
};

PAdptArray CreateAdptArray(COPY_FUNC copy, DEL_FUNC delete, PRINT_FUNC print)
{
	PAdptArray p = (PAdptArray)malloc(sizeof(struct AdptArray_));
	if (p == NULL)
		return NULL;
	p->arr = NULL;
	p->size = 0;
	p->copy_func = copy;
	p->delete_func = delete;
	p->print_func = print;
	return p;
}

void DeleteAdptArray(PAdptArray p)
{
	if (p == NULL)
		return;
	for (int i = 0; i < p->size; i++)
	{
		if (p->arr[i])
			p->delete_func(p->arr[i]);
	}
	free(p->arr);
	free(p);
}

Result SetAdptArrayAt(PAdptArray p, int index, PElement element)
{
	if (p == NULL || index < 0)
		return FAIL;
	if (index >= p->size)
	{
		p->arr = (PElement *)realloc(p->arr, (index + 1) * sizeof(PElement));
		if (p->arr == NULL)
			return FAIL;
		for (int i = p->size; i < index + 1; i++)
		{
			p->arr[i] = NULL;
		}
		p->size = index + 1;
	}
	if (p->arr[index])
		p->delete_func(p->arr[index]);
	p->arr[index] = p->copy_func(element);
	return SUCCESS;
}

PElement GetAdptArrayAt(PAdptArray p, int index)
{
	if (p == NULL || index >= p->size || index < 0 || p->arr[index] == NULL)
		return NULL;
	return p->copy_func(p->arr[index]);
}

int GetAdptArraySize(PAdptArray p)
{
	if (p == NULL)
		return -1;
	return p->size;
}

void PrintDB(PAdptArray p)
{
	if (p == NULL)
		return;
	for (int i = 0; i < p->size; i++)
	{
		if (p->arr[i])
			p->print_func(p->arr[i]);
	}
}
