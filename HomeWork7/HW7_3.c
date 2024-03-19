#include <stdio.h>

const static int SIZE=12;
const static int SHIFT=4;

int main(int argc, char **argv)
{
    //заполняем массив
    int array[SIZE]; 
    for (int n=0; n<SIZE; n++){
        scanf("%d", &array[n]);
    }
    //отрезаем хвост массива из SHIFT элементов
    int array2[SHIFT]; 
    int count=0;
    for (int n=SIZE-SHIFT; n<SIZE; n++){
        array2[count]=array[n];
        count++;
    }
    //сдвигаем массив вправо на SHIFT элементов
    count=1; 
    for (int n=SIZE-SHIFT-1; n>-1; n--){
        array[SIZE-count]=array[n];
        count++;
    }
    //присоединяем отрезанный хвост в начало массива
    for (int n=0; n<SHIFT; n++){
        array[n]=array2[n];
    }
    //выводим результат
    for (int n=0; n<SIZE; n++){
        printf("%d ", array[n]);
    }

	return 0;
}