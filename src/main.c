#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rand-ints.h"
#include "sorting-algorithms.h"

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
	}
	else{return 0;}
	gen_array(len, type);
	return 0;
}

void gen_array(int len, int type)
{
	int array[len], workarray[len];
	gen_rand(array, len);

	printf("random: ");
	copyarray(array, 0, len, workarray);
	measure_runtime(array, len, type);
//	printf("-------\n");

	printf("partial: ");
	copyarray(array, 0, len, workarray);
	partial_sort(workarray, len);
	measure_runtime(workarray, len, type);
//	printf("-------\n");

	// reversed dataset
	printf("reversed: ");
	copyarray(array, 0, len, workarray);
	reverse_sort(workarray, len);
	measure_runtime(workarray, len, type);
//	printf("-------\n");

	printf("sorted: ");
	measure_runtime(workarray, len, type);
//	print_array(workarray, len);
//	printf("-------\n");

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


