#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen-rand(int *array, int len);

int main(int argc, char *argv)
{

	//add thing to take in cmd line args

	
}

void gen-rand(int *array, int len)
{
	srand(time(0));

	for(int i = 0; i<len; ++i)
		array[i] = rand();

	for(int i = 0; i<len; ++i)
		printf("%d\n", rand());

}


