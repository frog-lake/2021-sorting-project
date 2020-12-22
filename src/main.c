#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rand-ints.h"
#include "sorting-algorithms.h"

void print_array(int *array, int len);

int main(int argc, char *argv[])
{
	int len = 0;

	if(argc == 2)
	{
		len = atoi(argv[1]);
	}

	int array[len];
	gen_rand(array, len);

	//print_array(array, len);

	//printf("-------\n");
	time_t start = time(NULL);

	quicksort(array, 0, len - 1);
	
	//print_array(array, len);
	time_t end = time(NULL);
	
	double seconds = (double)(end-start);
	printf("%f\n", seconds);
	return 0;
}

void print_array(int *array, int len)
{
	for(int i=0;i<len;++i)
		printf("%d\n", array[i]);
}


