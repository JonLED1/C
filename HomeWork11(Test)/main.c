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
    char file_name[256];
    int rez=0;
    opterr=0;
    while ( (rez = getopt(argc,argv,"hf:m:")) != -1){
        switch (rez){
            case 'h': print_help(); break;
            case '?': print_help_small(); break;
            case 'f': strncpy(file_name, optarg, sizeof(file_name)); break;
            case 'm': printf("Month = %s\n", optarg); break;
        };

    };

    file_in=fopen(file_name, "r");
    if (!file_in){
        printf("File name - %s not found!\n", file_name);
        return 0;
    }
    else{
        printf("File name - %s opened.\n", file_in);
    };

    printf("Run program\n");
    fclose(file_in);

    return 0;
}