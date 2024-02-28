#include <stdio.h>

int main(int argc, char **argv)
{
	int a, count=0, countEVEN=0;
	printf("Enter integer number: ");
	scanf("%d", &a);

    while (a!=0)
    {   
        if (a%10%2==0)
        {
            countEVEN++;
        }
        a=a/10;
        count++;
    }

	if (count==countEVEN)
    {
        printf("YES");
    }
	else
    {
        printf("NO");
    }
	return 0;
}
