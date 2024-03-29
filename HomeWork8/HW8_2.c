#include <stdio.h>

void sort_even_odd(int n, int a[]){
    int count_even=0, count_odd=0, i=0;
    int odd[n];
    int even[n];
    for (i=0; i<n; i++){
        if (a[i]%2==0){
            even[count_even]=a[i];
            count_even++;
        }
        else{
            odd[count_odd]=a[i];
            count_odd++;
        }
    }
    for (i=0; i<count_even; i++){
        a[i]=even[i];
    }
    for (i=0; i<count_odd; i++){
        a[i+count_even]=odd[i];
    }
}

/*
int main(int argc, char **argv)
{
    // enum {SIZE = 20};
    // int a[]={20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    enum {SIZE = 5};
    int a[]={1, 0, 1, 0, 1};
    sort_even_odd(SIZE, a);
    
    for (int i=0; i<SIZE; i++){
        printf("%d ",a[i]);
    }
	return 0;
}
*/