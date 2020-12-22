#include <stdio.h>
#include "sorting-algorithms.h"

void swap(int *xp, int *yp);
void bubblesort(int *array, int len);

void quicksort(int *array, int low, int high);
int partition(int *array, int low, int high);

void mergesort(int *array, int *brray, len);
void merge(int *array, int *brray, len);
void copyarray(int *brray, int *array, len);

void mergesort(int *array, int *copy, len)
{

}

void copyarray(int *brray, int *array, len)
{
	for(int i = 0; i < n; ++i)
		array[i] = brray[i];
}




void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubblesort(int *array, int len)
{
	int i, j;
	for(i=0; i < len-1; ++i)
		for(j=0; j < len - i - 1; ++j)
			if (array[j] > array[j+1])
				swap(&array[j], &array[j+1]);
}


int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);

	for(int j = low; j <= high-1; ++j)
	{
		if(array[j] < pivot)
		{
			++i;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i+1], &array[high]);
	return (i+1);
}

void quicksort(int *array, int low, int high)
{
	if(low < high)
	{
		int pi = partition(array, low, high);

		quicksort(array, low, pi - 1);
		quicksort(array, pi + 1, high);
	}
}
