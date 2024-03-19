#include <stdio.h>

#define SIZE 10

int main(int argc, char **argv)
{
    // ввод массива
    int array[SIZE];
    for (int n=0; n<SIZE; n++){
        scanf("%d", &array[n]);
    }
    // создаем массив с числом повоторений
    int count[SIZE]={0};
    for (int i = 0; i < SIZE; i++) {
        for (int n=0; n<SIZE; n++){
            if (array[i]==array[n]){
                count[i]++;
            }
        }
    }
    
    // находим максимальное число поторений и запоминаем индекс
    int max_num=0, index=0;
    for (int i=0; i<SIZE; i++){
        if (count[i] > max_num){
            max_num = count[i];
            index = i;
        }
    }
    
    //выводим число из основного массива по индексу
    printf("%d\n", array[index]);
	return 0;
}

