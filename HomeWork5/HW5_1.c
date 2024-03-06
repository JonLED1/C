#include <stdio.h>

unsigned long long int corn_sum(int a) 
{
    unsigned long long int corn=1;
    for (int i=1; i<a; i++)
    {
        corn=corn*2;
    }
    return corn;
}

int main(int argc, char **argv)
{
	int a;
	printf("Enter integer number 1 to 64: ");
	scanf("%d", &a);
    printf("%llu",corn_sum(a));
	return 0;
}
