#include <stdio.h>

#define SIZE 5

int aver_diag(int a[][SIZE]) {
    int sum=0;
    for (int i=0; i<SIZE; i++){
        sum+=a[i][i];
    }
    return sum/SIZE;
}

int count_num(int sum, int a[][SIZE]){
    int count=0;
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            if (a[i][j]>sum){
                count++;
            }
        }
    }
    return count;
}

int main() {
    int matrix[SIZE][SIZE]={
        {1,1,1,1,1},
        {2,2,2,2,2},
        {3,3,3,3,3},
        {4,4,4,4,4},
        {5,5,5,5,5}};
    printf ("%d", count_num(aver_diag(matrix), matrix));
    return 0;
}