#include <stdio.h>
#include <string.h>

int main() {
    FILE *in = fopen("1.txt", "r");
    FILE *out = fopen("2.txt", "w");
    char str_in[1000];
    char long_word[1000]="";
    int max_len=0;
    char *word;

    fscanf(in, "%[^\n]", str_in);
    
    word = strtok(str_in, " ");

    while (word != NULL) {
        if (strlen(word) > max_len) {
            max_len = strlen(word);
            strcpy(long_word, word);
        }
        word = strtok(NULL, " ");
    }

    fprintf(out, "%s", long_word);

    fclose(in);
    fclose(out);

    return 0;
}