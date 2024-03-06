#include <stdio.h>

int is_happy_number(int n)
{
    int sum=0, mult=1;
    while (n)
    {
        sum=sum + n%10;
        mult = mult*(n%10);
        n=n/10; 
    }
    n = sum==mult? 1: 0;
    return n;
}

int main(int argc, char **argv)
{
	int n;
	printf("Enter integer number: ");
	scanf("%d", &n);
    printf("%s", is_happy_number(n)? "YES": "NO");
	return 0;
}
