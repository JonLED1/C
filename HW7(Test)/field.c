#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "field.h"

typedef struct drone_t{
	int direction;
	int x;
	int y;
	struct tail_t * tail;
	size_t tsize;
}  drone_t;

void fill_field(char matrix[MAX_X][MAX_Y]){
    for (int i=1; i<MAX_Y; i++){
        for (int j=1; j<MAX_X; j++){
            matrix[i][j]='.';
        }
    }
}

void print_field(char matrix[MAX_X][MAX_Y]){
	for (int i=0; i<MAX_Y+7; i++){
		printf ("\033[A");
	}
    for (int i=1; i<MAX_Y; i++){
        for (int j=1; j<MAX_X; j++){
            if (matrix[i][j]=='o'){
					printf("\x1b[32m%c\x1b[0m", matrix[i][j]);
            }
            else if (matrix[i][j]=='O'){
					printf("\x1b[33m%c\x1b[0m", matrix[i][j]);
            }
            else{
                printf("%c", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void ripening_pumpkis(char matrix[MAX_X][MAX_Y]){
    //if (rand()%2!=1) return;
    while(1){
        int x = rand() % MAX_X;
        int y = rand() % MAX_Y;
        if (matrix[x][y]=='.'){
            matrix[x][y]='o';
            break;
        }
        if (matrix[x][y]=='o'){
            matrix[x][y]='O';
            break;
        }
    }
}