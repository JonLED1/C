#include <stdio.h>
#include <stdlib.h>
#define SIZE 600000

void print_help(void){
    printf ("\n\nProgramm for calculate average temperature.\n");
    printf ("Please, use this keys for command line:\n");
    printf ("\t-h Help\n");
    printf ("\t-f <file_name.csv>\n");
    printf ("\t-m Month (1-12)\n\n");
}

void print_help_small(void){
    printf ("\n\nProgramm for calculate average temperature.\n");
    printf("ERROR! Invalid command! Please, run with key -h for help.\n\n");
}

void stat_all(char *file_name){
    struct sensor_temp {
        int year;
        int month;
        int day;
        int hour;
        int min;
        int temp;
    };
    struct sensor_temp *date_in = malloc(SIZE * sizeof(struct sensor_temp));
    FILE *file_in;
    file_in=fopen(file_name, "r");
    int i=0; //index struct
    char line[25]; //line in file

    //check file
    if (!file_in){
        printf("ERROR! File name - <%s> not found! Programm terminated!\n", file_name);
        exit(0);
    }
    else{
        printf("File name - <%s> opened.\n", file_name);
    };

    //read file and fill array struct
    while (fgets(line, sizeof(line), file_in) != NULL){
        if (sscanf(line, "%d;%d;%d;%d;%d;%d",
                    &(date_in[i].year),
                    &(date_in[i].month),
                    &(date_in[i].day),
                    &(date_in[i].hour),
                    &(date_in[i].min),
                    &(date_in[i].temp)) == 6){
            i++;
        }
        else{
            printf("Read error! In line-%d %s",i, line);
        }
    }

    i=3;
    printf("%d %d %d %d %d %d %d\n", i, date_in[i].year, date_in[i].month, date_in[i].day, date_in[i].hour, date_in[i].min, date_in[i].temp);

    fclose(file_in);
    free(date_in);
}