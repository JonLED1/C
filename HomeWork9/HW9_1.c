#include <stdio.h>
#include <string.h>

int main() {
    FILE *in = fopen("1.txt", "r");
    FILE *out = fopen("2.txt", "w");

    char word1[100], word2[100];
    fscanf(in, "%s %s", word1, word2);

    //массивы счетчиков символов для каждого слова
    int count1[256] = {0};
    int count2[256] = {0};

    //перебор символов в словах с подсчетом их количества по соответсвию ASCII
    for (int i = 0; i < strlen(word1); i++) {
        count1[word1[i]]++;
    }
    for (int i = 0; i < strlen(word2); i++) {
        count2[word2[i]]++;
    }

    //выводим в файл символы с количеством 1 в обоих словах
    for (int i = 0; i < 256; i++) {
        if (count1[i] == 1 && count2[i] == 1) {
            fprintf(out, "%c ", (char)i);
        }
    }

    fclose(in);
    fclose(out);

    return 0;
}
