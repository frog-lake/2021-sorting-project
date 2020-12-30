#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rand-ints.h"
// gen-rand, partial_sort, reverse_sort
#include "sorting-algorithms.h"
// bubblesort, quicksort, mergesort, copyarray

void print_array(int *array, int len);
void measure_runtime(int *array, int len, int type, int arr_type);
void gen_array(int len, int type);

int main(int argc, char *argv[])
{
	// var declarations
	int len = 0, type;

	// if argc has 3 args, continue
	if(argc == 3)
	{
		len = atoi(argv[1]);
		type = atoi(argv[2]);
		gen_array(len, type);
	}
	else{return 0;}
}

void gen_array(int len, int type)
{
	int *array;
	array = (int *) malloc(len * sizeof(int));

	// generate random integers
	gen_rand(array, len);

	print_array(array, len);
	printf("--\n");
	// datasets are copied and then sorted with the runtime being measured
	// random order
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
//	free(workarray);
	return;
}

void measure_runtime(int *array, int len, int type, int arr_type)
{
	clock_t start, end;
	int *workarray;
	workarray = (int *) malloc(len * sizeof(int));
	// copies array to workarray to make it easier
	copyarray(array, 0, len, workarray);
	array_type(workarray, len, arr_type);
	print_array(workarray, len);

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


