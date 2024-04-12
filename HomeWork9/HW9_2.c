#include <stdio.h>

int main() {
    FILE *in = fopen("1.txt", "r");
    FILE *out = fopen("2.txt", "w");
    char symb;

    //читаем и зписываем файл посимвольно с заменой 
    while ((symb=fgetc(in)) != EOF){
        if (symb==(char)97){
            fputc((char)98, out);
        }
        else if (symb==(char)65){
            fputc((char)66, out);
        }
        else if (symb==(char)98){
            fputc((char)97, out);
        }
        else if (symb==(char)66){
            fputc((char)65, out);
        }
        else{
            fputc(symb, out);
        }
        
    }

    fclose(in);
    fclose(out);

    return 0;
}