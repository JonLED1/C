
#include <stdio.h>
#include <string.h>

#define LEN 1000

int main() {
    FILE *in = fopen("1.txt", "r");
    FILE *out = fopen("2.txt", "w");
    char str_in[LEN];
    char file_name[LEN];
    int count=0;
    int i;

    fgets(str_in, LEN, in);

    //выделяем имя файла
    for (i=strlen(str_in)-1; i>-1; i--){
        if (str_in[i]=='/')
            break;
        file_name[count]=str_in[i];
        count++;
    }
    file_name[count]='\0';

    //отделяем расширение файла и переворачиваем его
    count=i+1;
    for (i=strlen(file_name)-1; i>-1; i--){
        if (file_name[i]!='.'){
            str_in[count]=file_name[i];
            count++;
        }
        else
            break;
    }
    str_in[count]='\0';
    strcat(str_in, ".html");

    fprintf(out, "%s", str_in);
    fclose(in);
    fclose(out);
    return 0;
}