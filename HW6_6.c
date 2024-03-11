#include <stdio.h>

int recurs_power(int n, int p)
{
    if (p==0)
    {
        return 1;
    }
    return n * recurs_power (n, p-1);
    
}

int main(int argc, char **argv)
{
    int n, p;
	printf("Enter two integers: ");
    scanf("%d %d", &n, &p);
    printf("%d", recurs_power(n, p));
	return 0;
}