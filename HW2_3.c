#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b, dif;
	printf("Enter 2 integers numbers separated by spaces: ");
	scanf("%d %d", &a, &b);

	dif = a - b;

	printf("Subtraction of numbers:\n");
	printf("%d-%d=%d",a, b, dif);
	
	return 0;
}