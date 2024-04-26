#include <stdio.h>
#include <stdlib.h>
#include "temp_functions.h"
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

void stat_all(char *file_name, int month){
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
    int count_valid_date=0, count_err_read=0, count_err_data=0, count_line_file=1;
    char line[25]; //line in file
    int year, mon, day, hour, min, temp; //temp var for read

    //check file
    if (!file_in){
        printf("\nERROR! File name - <%s> not found! Programm terminated!\n", file_name);
        exit(0);
    }
    else{
        printf("\nFile name - <%s> opened.\n", file_name);
    };

    //read file and fill array struct
    while (fgets(line, sizeof(line), file_in) != NULL){
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", &year, &mon, &day, &hour, &min, &temp ) == 6){
            if (check_valid_date(year, mon, day, hour, min, temp) == 1){
                date_in[count_valid_date].year=year;
                date_in[count_valid_date].month=mon;
                date_in[count_valid_date].day=day;
                date_in[count_valid_date].hour=hour;
                date_in[count_valid_date].min=min;
                date_in[count_valid_date].temp=temp;
            }
            else{
                printf("Invalid data! In line-%d %s",count_line_file, line);
                count_err_data++;
            };
            count_valid_date++;
        }
        else{
            printf("Read error! In line-%d %s",count_line_file, line);
            count_err_read++;
        };
        count_line_file++;
    }
    printf("\nTotal read errors %d lines.\n", count_err_read);
    printf("Total invalid data %d lines.\n\n", count_err_data);

    get_stat(month);

    printf("  Year\tMonth\tMonthAvg\tMonthMax\tMonthMin\n");

    fclose(file_in);
    free(date_in);
}

int check_valid_date(int year, int mon, int day, int hour, int min, int temp){
    if (year<2000 || year>2100) return 0;
    if (mon<1 || mon>12) return 0;
    if (day<1 || day>31) return 0;
    if (hour<0 || hour>24) return 0;
    if (min<0 || min>59) return 0;
    if (temp<-270 || temp>1000) return 0;
    return 1;
}






    // count_valid_date=3;
    // printf("  %d\t%d\t%d\t%d\t%d\t%d\t%d\n", count_valid_date, date_in[count_valid_date].year,
    //  date_in[count_valid_date].month, date_in[count_valid_date].day, date_in[count_valid_date].hour, date_in[count_valid_date].min, date_in[count_valid_date].temp);