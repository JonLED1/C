#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b, c;
	printf("Enter 3 integers numbers separated by spaces: ");
	scanf("%d %d %d", &a, &b, &c);

    if (a < b && b < c)
    	printf("YES");
    else
        printf("NO");

	return 0;
}
