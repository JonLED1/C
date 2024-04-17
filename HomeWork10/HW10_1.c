#include <stdio.h>
#include <string.h>

#define LEN 1000

void change_symbols(int size, char *line){ //подсмотрел в разборе
    int i = 0, j;
    char b;
    printf ("%s", line);
    while (i < size){
        while (line[i] == ' ')//пропускаем пробелы
            i++; 
        j = i + 1;//позиция без пробела
        while (line[j] == ' ')
            j++;
        if (j >= size) //проверка выхода за границу
            break;
        // меняем местами
        b = line[i];
        line[i] = line[j];
        line[j] = b;
        // следующий символ
        i = j + 1;
    }
}

int main() {
    FILE *in = fopen("1.txt", "r");
    FILE *out = fopen("2.txt", "w");
    char str_in[LEN];

    fgets(str_in, LEN, in);

    change_symbols(strlen(str_in), str_in);
    
    fprintf(out, "%s", str_in);
    fclose(in);
    fclose(out);
    return 0;
}
