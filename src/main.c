#include <stdio.h>
#include <stdlib.h>
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

	print_array(array, len);

	printf("-------\n");
	bubblesort(array, len);
	
	print_array(array, len);

}

void print_array(int *array, int len)
{
	for(int i=0;i<len;++i)
		printf("%d\n", array[i]);
}


