// Задание 1. Биномиальный коэффициент
// Реализовать программу 1-го практического задания с помощью биномиального коэффициента.
// Данные на вход: Два целых числа N и M
// Данные на выход: Одно целое число – количество вариантов



#include <stdio.h>

int binomial(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return binomial(n-1, k-1) + binomial(n-1, k);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("C(%d, %d) = %d\n", n, k, binomial(n, k));
    return 0;
}