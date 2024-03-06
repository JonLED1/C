#include <stdio.h>

int check()
{
	char n;
	int count1 = 0, count2 = 0;
    while ((n=getchar()) != '.')
    {
		if (n == '(') 
		{
            count1++;
        } 
		if (n == ')') 
		{
	        count2++;
		}
    }
	if (count1!=count2)
	{
		 return 0;
	}
    return 1;
}

int main(int argc, char **argv)
{
	printf("Enter: ");
    printf("%s\n", check()? "YES": "NO");
	return 0;
}

//не до конца доделал. вариант )( не отрабатывает. 
