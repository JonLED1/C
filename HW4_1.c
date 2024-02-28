#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b, sum=0;
	printf("Enter 2 integers numbers separated by spaces: ");
	scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i++)
    {
        sum = sum + i*i;
    }

	printf("sum= %d", sum);
	
	return 0;
}