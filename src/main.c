#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rand-ints.h"
// gen-rand, partial_sort, reverse_sort
#include "sorting-algorithms.h"
// bubblesort, quicksort, mergesort, copyarray

void print_array(int *array, int len);
void measure_runtime(int *array, int len, int type);
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
	return 0;
}

void gen_array(int len, int type)
{
	int *array, *workarray;
	array = (int *) malloc(len * sizeof(int));
	workarray = (int *) malloc(len * sizeof(int));

	// generate random integers
	gen_rand(array, len);

	print_array(array, len);
	printf("--\n");
	// datasets are copied and then sorted with the runtime being measured
	// random order
	printf("random: ");
	copyarray(array, 0, len, workarray);
	measure_runtime(array, len, type);
//	print_array(workarray, len);

	// partially sorted
	printf("partial: ");
	copyarray(array, 0, len, workarray);
	partial_sort(workarray, len);
	measure_runtime(workarray, len, type);

	// reverse sorted data
	printf("reversed: ");
	copyarray(array, 0, len, workarray);
	reverse_sort(workarray, len);
	measure_runtime(workarray, len, type);

	// sorted data
	printf("sorted: ");
	measure_runtime(workarray, len, type);
	//print_array(workarray, len);
	free(workarray);

	return;
}

void measure_runtime(int *array, int len, int type)
{
	clock_t start, end;
	start = clock();

	switch(type)
	{
	case 1:
		printf("bubblesort\n");
		bubblesort(array, len);
		break;
	case 2:
		printf("quicksort\n");
		quicksort(array, 0, len - 1);
		break;
	case 3:
		printf("mergesort\n");
		mergesort(array, len);
		print_array(array, len);
		break;
	}
	end = clock();
	
	double seconds = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("%f\n\n", seconds);

}



void print_array(int *array, int len)
{
	for(int *p = array; p < array+len;++p)
		printf("%d\n", *p);
}


