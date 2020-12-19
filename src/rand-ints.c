#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

	srand(time(0));

	for(int i = 0; i<4; ++i)
		printf(" %d ", rand());

	return 0;
}
