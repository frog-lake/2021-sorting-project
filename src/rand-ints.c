#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rand-ints.h"

void gen_rand(int *array, int len);

void gen_rand(int *array, int len)
{
	srand(time(0));

	for(int i = 0; i<len; ++i)
		array[i] = rand();

}


