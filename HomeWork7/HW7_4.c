#include <stdio.h>

const static int SIZE=10;

int main(int argc, char **argv)
{
    
    int array[SIZE];
    for (int n=0; n<SIZE; n++){
        scanf("%d", &array[n]);
    }
    _Bool swap;
    int tmp;
    do{
        swap=0;
        for (int n=0; n<SIZE-1; n++){
            if (array[n]%10 > array[n+1]%10){
                tmp = array[n];
                array[n] = array[n+1];
                array[n+1] = tmp;
                swap = 1;
            }
        }
    }
    while(swap);
    
    for (int n=0; n<SIZE; n++){
        printf("%d ", array[n]);
    }
	return 0;
}