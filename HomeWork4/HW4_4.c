#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b=0;
	printf("Enter integer number: ");
	scanf("%d", &a);

    while (a)
    {
        b=b*10+a%10;
        a/=10;
    }
    printf("%d",b);
	return 0;
}
