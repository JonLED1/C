#include <stdio.h>

int main(int argc, char **argv)
{
	int a, count=0;
	printf("Enter integer number: ");
	scanf("%d", &a);

    while (a!=0)
    {
        a=a/10;
        count++;
    }

	if (count==3)
    {
        printf("YES");
    }
	else
    {
        printf("NO");
    }
	return 0;
}
