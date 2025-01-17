// Задание 2. Инверсия старших

// На вход программе подается беззнаковое 32-битное целое число N. Требуется изменить значения всех битов старшего байта числа на противоположные и вывести полученное таким образом число.

// Данные на входе: Беззнаковое 32-битное целое число N
// Данные на выходе: Одно целое число.

// Пример №1
// Данные на входе: 1
// Данные на выходе: 4278190081

// Пример №2
// Данные на входе: 4278190081
// Данные на выходе: 1

#include <stdio.h>

int main() {
    unsigned int N;
    unsigned int mask = 0xFF000000; // маска для старшего байта

    scanf("%u", &N);

    N = N ^ mask;

    printf("%u\n", N);

    return 0;
}