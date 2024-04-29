#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "temp_functions.h"


int main(int argc, char *argv[]){

    //no command
     if(argc == 1){
        print_help_small();
        return 0;
     }

    //command parametrs
    char *file_name;
    int month=0;
    int rez=0;
    opterr=0;

    while ( (rez = getopt(argc,argv,"hf:m:")) != -1){
        switch (rez){
            case 'h': print_help(); return 0;
            case '?': print_help_small(); return 0;
            case 'f': file_name=optarg; break;
            case 'm': month=atoi(optarg); break;
        };

    };

    //check month
    if (month<0 || month>12){
        printf("Invalid month!");
        return 0;
    }

    stat_output(file_name, month);

    return 0;
}
