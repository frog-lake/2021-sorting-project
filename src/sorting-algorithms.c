#include <stdio.h>
#include "sorting-algorithms.h"

void bubblesort(int *array, int len);
void swap(int *xp, int *yp);

void quicksort(int *array, int low, int high);
int partition(int *array, int low, int high);

void mergesort(int *array, int len);
void split_merge(int *brray, int start, int end, int *array);
void merge(int *array, int start, int middle, int end, int *brray);
void copyarray(int *array, int start, int end, int *brray);

// bubblesort functions
void bubblesort(int *array, int len)
{
	int i, j;
	for(i=0; i < len-1; ++i)
		for(j=0; j < len - i - 1; ++j)
			if (array[j] > array[j+1])
				swap(&array[j], &array[j+1]);
}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


// quicksort functions
void quicksort(int *array, int low, int high)
{
	if(low < high)
	{
		int pi = partition(array, low, high);
		quicksort(array, low, pi - 1);
		quicksort(array, pi + 1, high);
	}
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


// mergesort functions
void mergesort(int *array, int len)
{
	int brray[len];
	copyarray(array, 0, len, brray);
	split_merge(brray, 0, len, array);
}

void split_merge(int *brray, int start, int end, int *array)
{
	if(end - start <= 1)
		return;
	int middle = (end + start) / 2;
	split_merge(array, start, middle, brray);
	split_merge(array, middle, end, brray);
	merge(brray, start, middle, end, array);
}

void merge(int *array, int start, int middle, int end, int *brray)
{
	int i = start, j = middle;

	for(int k = start; k < end; ++k){
		if(i < middle && (j <= end || array[i] <= array[j])){
			brray[k] = array[i];
			++i;
		} else {
			brray[k] = array[j];
			++j;
		}
	}

}

void copyarray(int *array, int start, int end, int *brray)
{
	for(int i = start; i < end; ++i)
		brray[i] = array[i];
}

