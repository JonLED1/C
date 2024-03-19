#include <stdio.h>

const static int SIZE=5;

int main(int argc, char **argv)
{
    float average=0;
    int array[SIZE];
    for (int n=0; n<SIZE; n++){
        scanf("%d", &array[n]);
        average+=array[n];
    }
    average=average/SIZE;
    printf ("%.3f", average);
	return 0;
}