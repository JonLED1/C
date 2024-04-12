#include <stdio.h>
#include <string.h>

int main() {
    FILE *in = fopen("1.txt", "r");
    FILE *out = fopen("2.txt", "w");
    char str_in[1000];
    char str_out[26] = {0}; // массив для уникальных символов

    fgets(str_in, 1000, in);
    
    for (int i = 0; i < strlen(str_in); i++) {
        if (str_in[i] == ' ') {
            continue; // Пропускаем пробелы
        }

        int found = 0;
        for (int j = 0; j < strlen(str_out); j++) {
            if (str_in[i] == str_out[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            str_out[strlen(str_out)] = str_in[i]; // Добавляем уникальный символ в массив
        }
    }

    fprintf(out, "%s", str_out);

    fclose(in);
    fclose(out);

    return 0;
}