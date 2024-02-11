#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b, c, sum, mult;
	printf("Enter 3 integers numbers separated by spaces: ");
	scanf("%d %d %d", &a, &b, &c);

	sum = a + b + c;
	mult = a * b * c;

	printf("Sum of numbers:\n");
	printf("%d+%d+%d=%d\n",a, b, c, sum);
	printf("Multiplay of numbers:\n");
	printf("%d*%d*%d=%d\n",a, b, c, mult);
	
	return 0;
}
