#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rand-ints.h"

// generates an array of random integers
void gen_rand(int *array, int len);
// sorts a set for different types of datasets 
void array_type(int *array, int len, int arr_type);
int compare_ints(const void *a, const void *b);
int rev_compare_ints(const void *a, const void *b);

void gen_rand(int *array, int len)
{
	srand(time(NULL));

	for(int *p = array; p<array+len; ++p)
		*p = rand();
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
		//partially sorted array
		qsort(array, len/2, sizeof(int), compare_ints);
		break;
	case 2:
		// reverse sorted array
		qsort(array, len, sizeof(int), rev_compare_ints);
		break;
	case 3:
		// sorted array
		qsort(array, len, sizeof(int), compare_ints);
		break;
	}
}
