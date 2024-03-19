#include <stdio.h>

const static int SIZE=5;

int main(int argc, char **argv)
{
    
    int array[SIZE];
    for (int n=0; n<SIZE; n++){
        scanf("%d", &array[n]);
    }
    int min=array[0];
    for (int n=1; n<SIZE; n++){
        if (min>array[n]){
            min = array[n];
        }
    }
    printf ("%d", min);
	return 0;
}