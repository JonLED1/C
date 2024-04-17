#include <stdio.h>
#include <string.h>



int main() {
    FILE *in = fopen("1.txt", "r");
    FILE *out = fopen("2.txt", "w");
    char symb;
    int spaces=0, start=0;

    while ((symb=fgetc(in)) != EOF){
        if (symb==' ' && start==0){     //убираем пробелы в начале строки
            continue;
        }
        else if (symb==' ' && spaces==0){   //один пробел оставляем
            spaces++;
            fputc(symb, out);
        }
        else if (symb==' ' && spaces!=0){  //если пробелов больше 1 пропускаем
            continue;
        }
        else{
            start=1;
            spaces=0;
            fputc(symb, out);
        }  
    }
    
    fclose(in);
    fclose(out);
    return 0;
}