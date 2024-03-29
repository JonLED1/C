#include <stdio.h>

void change_max_min(int size, int a[]) {
    int max=a[0], max_index=0, min=a[0], min_index=0, i;
    for (i=1; i<size; i++){
        if (a[i]>max){
            max=a[i];
            max_index=i;
        }
        if (a[i]<min){
            min=a[i];
            min_index=i;
        }
    }
    a[min_index]=max;
    a[max_index]=min;
}


// int main() {
//     int a[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int size = sizeof(a) / sizeof(a[0]);
//     change_max_min(size, a);
    
//     for (int i=0; i<size; i++){
//         printf("%d ",a[i]);
//     }

//     return 0;
// }
