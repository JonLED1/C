#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "temp_functions.h"

int main(int argc, char *argv[]){

    //no command
     if(argc == 1){
        print_help_small();
        return 0;
     }

    //command parametrs
    FILE *file_in;
    char *file_name;
    int month=0;
    int rez=0;
    opterr=0;
    struct sensor_temp {
        short int day;
        short int month;
        short int year;
        short int hour;
        short int min;
        short int t;
    };

    while ( (rez = getopt(argc,argv,"hf:m:")) != -1){
        switch (rez){
            case 'h': print_help(); return 0;
            case '?': print_help_small(); return 0;
            case 'f': file_name=optarg; break;
            case 'm': month=atoi(optarg); break;
        };

    };

    file_in=fopen(file_name, "r");
    //check file
    if (!file_in){
        printf("File name - <%s> not found!\n", file_name);
        fclose(file_in);
        return 0;
    }
    else{
        printf("File name - <%s> opened.\n", file_name);
    };

    //check month
    if (month<0 || month>12){
        printf("Invalid month!");
        fclose(file_in);
        return 0;
    }

    struct sensor_temp *date_in;
    
    if (month==0){
        stat_all();
    }
    else{
        stat_month();
    }
    fclose(file_in);

    return 0;
}