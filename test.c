#include <stdio.h>
#include <unistd.h>


int main()
{
	int x;
	void *p;

	x = 7;
	p = (int *)&x;
	unsigned long answer = (unsigned long) p; 
	printf("answer is %lu", answer);
}