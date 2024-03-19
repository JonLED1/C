#include <stdio.h>

const static int SIZE=10;

int main(int argc, char **argv)
{
    
    int array[SIZE];
    for (int n=0; n<SIZE; n++){
        scanf("%d", &array[n]);
    }

    int count=0;
    for (int n=0; n<SIZE; n++){
        if (array[n]/10%10==0 && array[n]!=1){
            count++;
        }
    }

    int array2[count];
    count=0;
    for (int n=0; n<SIZE; n++){
        if (array[n]/10%10==0 && array[n]!=1){
            array2[count]=array[n];
            count++;
        }
    }
    
    for (int n=0; n<count; n++){
        printf("%d ", array2[n]);
    }
	return 0;
}

// в задании ответ - 105 203 1 1000, но мне кажется, что 1 не должно быть.