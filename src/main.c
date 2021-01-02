#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rand-ints.h"
// gen_rand, array_type
#include "sorting-algorithms.h"
// bubblesort, quicksort, mergesort, copyarray

// generates the random array and calls measure_runtime
void datasets(int *array, int len, int type);
// prints array (used for testing)
void print_array(int *array, int len);
// times the algorithms and calls array_type for different types of datasets
void measure_runtime(int *array, int len, int type, int arr_type);

int main(int argc, char *argv[])
{
	// var declarations
	int len = 0, *array;

	// if argc has 3 args, continue
	if(argc == 2)
	{
		len = atoi(argv[1]);
		array = (int *) malloc(len * sizeof(int));
		// generate an array of random integers
		gen_rand(array, len);	

		// bubblesort
		datasets(array, len, 1);
		printf("-----\n\n");

		// quicksort
		datasets(array, len, 2);
		printf("-----\n\n");

		// mergesort
		datasets(array, len, 3);
		printf("-----\n\n");

	}

	return 0;
}

void datasets(int *array, int len, int type)
{
	// random (unchanged)
	printf("random: ");
	measure_runtime(array, len, type, 0);

	// partially sorted
	printf("partial: ");
	measure_runtime(array, len, type, 1);

	// reverse sorted data
	printf("reversed: ");
	measure_runtime(array, len, type, 2);

	// sorted data
	printf("sorted: ");
	measure_runtime(array, len, type, 3);

	return;
}

void measure_runtime(int *array, int len, int type, int arr_type)
{
	clock_t start, end;
	int *workarray;
	workarray = (int *) malloc(len * sizeof(int));

	// copies array to workarray so that a new array doesn't
	// need to be set up each time
	copyarray(array, 0, len, workarray);
	// calls for either a partially sorted, reverse sorted, or sorted array
	array_type(workarray, len, arr_type);
	start = clock();
	switch(type)
	{
	case 1:
		printf("bubblesort\n");
		bubblesort(workarray, len);
		break;
	case 2:
		printf("quicksort\n");
		quicksort(workarray, 0, len - 1);
		break;
	case 3:
		printf("mergesort\n");
		mergesort(workarray, len);
		break;
	}
	end = clock();
	
	double seconds = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("%f\n\n", seconds);

}

void print_array(int *array, int len)
{
	for(int i=0;i<len;++i)
		printf("%d\n", array[i]);
}

