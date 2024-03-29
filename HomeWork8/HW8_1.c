#include <stdio.h>

void sort_array(int size, int a[]){
    int i, j, temp;
    
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

/*
int main(int argc, char **argv)
{
    enum {SIZE = 20};
    int a[]={20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
    sort_array(SIZE, a);
    for (int i=0; i<SIZE; i++){
        printf("%d ", a[i]);
    }
	return 0;
}
*/
