#include <stdio.h>
#include <stdlib.h>
#include "temp_functions.h"
#define SIZE 600000 //max line in file
#define MAX_TEMP 1000
#define MIN_TEMP -270

struct sensor_temp {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int temp;
};

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

void stat_output(char *file_name, int month){
    //open file
    FILE *file_in;
    file_in=fopen(file_name, "r");

    //check file
    if (!file_in){
        printf("\nERROR! File name - <%s> not found! Programm terminated!\n", file_name);
        exit(0);
    }
    else{
        printf("\nFile name - <%s> opened.\n", file_name);
    };

    //read file and fill array struct
    struct sensor_temp *date_in = malloc(SIZE * sizeof(struct sensor_temp));
    int count_valid_str=0, count_err_read=0, count_err_data=0, count_line_file=1;
    char line[25]; //line in file
    int year, mon, day, hour, min, temp; //temp var for read
    while (fgets(line, sizeof(line), file_in) != NULL){
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", &year, &mon, &day, &hour, &min, &temp ) == 6){
            if (check_valid_date(year, mon, day, hour, min, temp) == 1){
                date_in[count_valid_str].year=year;
                date_in[count_valid_str].month=mon;
                date_in[count_valid_str].day=day;
                date_in[count_valid_str].hour=hour;
                date_in[count_valid_str].min=min;
                date_in[count_valid_str].temp=temp;
            }
            else{
                printf("Invalid data! In line-%d %s",count_line_file, line);
                count_err_data++;
            };
            count_valid_str++;
        }
        else{
            printf("Read error! In line-%d %s",count_line_file, line);
            count_err_read++;
        };
        count_line_file++;
    }
    fclose(file_in);

    printf("\nTotal read errors %d lines.\n", count_err_read);
    printf("Total invalid data %d lines.\n\n", count_err_data);

    int month_max=MIN_TEMP;
    int month_min=MAX_TEMP;
    int month_sum=0, count_month=0, i=0;
    float year_sum=0;
    printf("  Year\tMonth\tMonthAvg\tMonthMax\tMonthMin\n");

    //output stat for month
    if (month!=0){
        for (i; i<count_valid_str; i++){
            if (date_in[i].month==month){
                if (month_max<date_in[i].temp) month_max=date_in[i].temp;
                if (month_min>date_in[i].temp) month_min=date_in[i].temp;
                month_sum+=date_in[i].temp;
                count_month++;
            }
        }
        printf("  %d\t%d\t%d\t\t%d\t\t%d\n",date_in[i-1].year, month, month_sum/count_month, month_max, month_min);
        free(date_in);
        exit(0);
    }

    //output stat all month
    int year_max=MIN_TEMP;
    int year_min=MAX_TEMP;
    month=1;
    for (i; i<count_valid_str; i++){
        if (date_in[i].month==month){
            if (month_max<date_in[i].temp) month_max=date_in[i].temp;
            if (month_min>date_in[i].temp) month_min=date_in[i].temp;
            month_sum+=date_in[i].temp;
            count_month++;
        }
        else{
            printf("  %d\t%d\t%d\t\t%d\t\t%d\n",date_in[i-1].year, date_in[i-1].month, month_sum/count_month, month_max, month_min);
            month++;
            month_max=date_in[i].temp;
            month_min=date_in[i].temp;
            month_sum=date_in[i].temp;
            count_month=1;
        }
        if (year_max<date_in[i].temp) year_max=date_in[i].temp;
        if (year_min>date_in[i].temp) year_min=date_in[i].temp;
        year_sum+=date_in[i].temp;

    }
    printf("  %d\t%d\t%d\t\t%d\t\t%d\n",date_in[i-1].year, date_in[i-1].month, month_sum/count_month, month_max, month_min);//output last month
    printf("Year statistics: average is %.2f, max is %d, min is %d", year_sum/count_valid_str, year_max, year_min);

    free(date_in);
}

int check_valid_date(int year, int mon, int day, int hour, int min, int temp){
    if (year<2000 || year>2100) return 0;
    if (mon<1 || mon>12) return 0;
    if (day<1 || day>31) return 0;
    if (hour<0 || hour>24) return 0;
    if (min<0 || min>59) return 0;
    if (temp<MIN_TEMP || temp>MAX_TEMP) return 0;
    return 1;
}