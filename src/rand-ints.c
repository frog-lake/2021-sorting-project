#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rand-ints.h"

void gen_rand(int *array, int len);
void partial_sort(int *array, int len);
int compare_ints(const void *a, const void *b);
void reverse_sort(int *array, int len);
int rev_compare_ints(const void *a, const void *b);
void array_type(int *array, int len, int arr_type);

void gen_rand(int *array, int len)
{
	srand(time(0));

	for(int *p = array; p<array+len; ++p)
		*p = rand();
}

void reverse_sort(int *array, int len)
{
	qsort(array, len, sizeof(int), rev_compare_ints);
}

void partial_sort(int *array, int len)
{
	int part = len/2;
	qsort(array, part, sizeof(int), compare_ints);
}

int compare_ints(const void *a, const void *b)
{
	const int *da = (const int *) a;
	const int *db = (const int *) b;

	return (*da > *db) - (*da < *db);
}


int rev_compare_ints(const void *a, const void *b)
{
	const int *da = (const int *) a;
	const int *db = (const int *) b;

	return (*da < *db) - (*da > *db);
}

void array_type(int *array, int len, int arr_type)
{
	switch(arr_type)
	{
	case 1:
		//partial sort
		partial_sort(array, len);
		break;
	case 2:
		// reverse sort
		reverse_sort(array, len);
		break;
	case 3:
		// sorted
		qsort(array, len, sizeof(int), compare_ints);
		break;
	}
}
