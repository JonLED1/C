#include <stdio.h>

int count=0;
void print_one(int n) 
{
    if (n>1)
    {
        print_one(n/2);
    }
    if (n%2==1)
    {
        count++;
    }   
}

int main(int argc, char **argv)
{
	int n;
	printf("Enter natural number: ");
	scanf("%d", &n);
    print_one(n);
    printf("%d",count);
	return 0;
}
