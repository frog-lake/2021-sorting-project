#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rand-ints.h"
#include "sorting-algorithms.h"

void print_array(int *array, int len);
void measure_runtime(int *array, int len, int type);

int main(int argc, char *argv[])
{
	int len = 0;
	int type;
	if(argc == 3)
	{
		len = atoi(argv[1]);
		type = atoi(argv[2]);
	}

	int array[len];
	gen_rand(array, len);
	int partial[len];
	copyarray(array, 0, len, partial);
	partial_sort(partial, len);
	int reverse[len];
	copyarray(array, 0, len, reverse);
	reverse_sort(reverse, len);

	printf("random\n");
	measure_runtime(array, len, type);
	printf("-------\n");

	printf("partial\n");
	measure_runtime(partial, len, type);
	printf("-------\n");

	printf("reversed\n");
	measure_runtime(partial, len, type);
	printf("-------\n");
	return 0;
}


void measure_runtime(int *array, int len, int type)
{
	clock_t start = clock();

	if(type == 1){
		printf("bubblesort\n");
		bubblesort(array, len);
	}
	else if(type == 2){
		printf("quicksort\n");
		quicksort(array, 0, len - 1);
	}
	else if(type == 3){
		printf("mergesort\n");
		mergesort(array, len);
	}
	//print_array(array, len);
	clock_t end = clock();
	
	double seconds = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("%f\n", seconds);

}



void print_array(int *array, int len)
{
	for(int i=0;i<len;++i)
		printf("%d\n", array[i]);
}


