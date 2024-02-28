#include <stdio.h>

int main(int argc, char **argv)
{
	int a;
	printf("Enter integer number > 10: ");
	scanf("%d", &a);

    for (int n=10; n<=a;n++)
    {
        int sum=0, mult=1, b=n;
        while (b)
        {
            sum=sum + b%10;
            mult = mult*(b%10);
            b=b/10; 
        }
        
        if (sum==mult)
        {
            printf("%d ",n);
        }
    }
    
	return 0;
}
