#include <stdio.h>

int main(int argc, char **argv)
{
	int month;
	printf("Enter number month (1-12): ");
	scanf("%d", &month);

    if (month == 12 || month < 3 && month > 0)
    	printf("winter");
    else if (month > 2 && month < 6)
        printf("spring");
    else if (month > 5 && month < 9)
        printf("summer");
    else if (month > 8 && month < 12)
        printf("autumn");
    else
        printf("Error!");

	return 0;
}
