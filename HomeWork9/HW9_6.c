#include <stdio.h>
#include <string.h>

int main() {
    FILE *in = fopen("1.txt", "r");
    FILE *out = fopen("2.txt", "w");
    char str_in[1000];
    int count=0;
    char *word;

    fscanf(in, "%[^\n]", str_in);
    
    word = strtok(str_in, " ");

    while (word != NULL) {
        if (word[(strlen(word)-1)] == 'a') {
            count++;
        }
        word = strtok(NULL, " ");
    }

    fprintf(out, "%d", count);

    fclose(in);
    fclose(out);

    return 0;
}