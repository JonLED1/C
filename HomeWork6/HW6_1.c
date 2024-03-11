#include <stdio.h>

void print_num(int num) 
{
    
    if (num>=10)
    {
        print_num(num/10);
    }
    printf("%2d",num%10);
}

int main(int argc, char **argv)
{
	int num;
	printf("Enter number: ");
	scanf("%d", &num);
    print_num(num);
	return 0;
}
