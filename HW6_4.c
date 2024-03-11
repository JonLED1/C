#include <stdio.h>

void print_odd(void) 
{
    int a;
    scanf ("%d", &a);
    if (a == 0) 
    {
        return;
    }
    if (a % 2 != 0)
    {
        printf("%d ", a);
    }
    print_odd();
}

int main(int argc, char **argv)
{
	printf("Enter integer numbers separated by space, 0-end: ");
    print_odd();
	return 0;
}
