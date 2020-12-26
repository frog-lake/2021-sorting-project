#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rand-ints.h"

void gen_rand(int *array, int len);
void partial_sort(int *array, int len);
int compare_ints(const void *a, const void *b);
void reverse_sort(int *array, int len);
int rev_compare_ints(const void *a, const void *b);

void gen_rand(int *array, int len)
{
	srand(time(0));

	for(int i = 0; i<len; ++i)
		array[i] = rand();

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

