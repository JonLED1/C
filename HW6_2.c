#include <stdio.h>

void print_num(int a, int b) 
{
    if (a == b)
    {
        printf("%d ", a);
        return;
    }
    if (a<b)
    {
        printf("%d ",a);
        print_num(a+1, b);
    }
    else
    {
        printf("%d ",a);
        print_num(a-1, b);
    }
    
}

int main(int argc, char **argv)
{
	int a, b;
	printf("Enter number A and B: ");
	scanf("%d %d", &a, &b);
    print_num(a, b);
	return 0;
}
