#include <stdio.h>
int count=0;
int acounter(void) 
{
    char a;
    scanf ("%c", &a);
    if (a != '.') 
    {
        if (a=='a')
        {
            count++;
        }
        acounter();
    }
    return count;
}

int main(int argc, char **argv)
{
	printf("Enter string: ");
    printf ("%d", acounter());
	return 0;
}
