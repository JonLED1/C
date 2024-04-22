#include <stdio.h>
#include <unistd.h>
#include "temp_functions.h"

int main(int argc, char *argv[]){
    //command parametrs
    int rez=0;
    while ( (rez = getopt(argc,argv,"hf:")) != -1){
        switch (rez){
            case 'h': print_help(); break;
            case 'f': printf("file mname  = %s\n",optarg); break;
            case '?': printf("Error found !\n");break;
        };
    };

    return 0;
}