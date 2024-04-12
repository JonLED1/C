#include <stdio.h>
#include <string.h>

void sort_array(int size, int a[]){
    int i, j, temp;
    
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    FILE *in = fopen("1.txt", "r");
    FILE *out = fopen("2.txt", "w");
    char str_in[1000];
    char *word;
    int arr[1000];
    int index=0;

    fscanf(in, "%[^\n]", str_in);
    
    word = strtok(str_in, " ");
    while (word != NULL) {
        int result=0;
        for (int i=0; i<strlen(word); i++){
            if (word[i]=='0'){
                arr[index++]=0;
                break;
            }
            if (word[i]>(char)48 && word[i]<(char)58){
                result = result * 10 + (word[i] - '0');
            }
        }
        if (result!=0){
            arr[index++]=result;
        }
        word = strtok(NULL, " ");
    }

    sort_array(index, arr);

    for (int i=0; i<index; i++){
        fprintf(out, "%d ", arr[i]);
    }

    fclose(in);
    fclose(out);

    return 0;
}