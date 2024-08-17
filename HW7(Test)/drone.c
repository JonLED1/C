#include <stdio.h>
#include <stdlib.h>

#include "config.h"

typedef struct {
	int x;
	int y;
} tail_t;
	
typedef struct {
	int direction;
	int x;
	int y;
	tail_t * tail;
	size_t tsize;
}  drone_t;

drone_t init_drone(int direction, int x, int y, size_t tsize){
	drone_t drone;
	drone.direction=direction;
	drone.x = x;
	drone.y = y;
	drone.tsize = tsize;
	drone.tail = (tail_t *) malloc (sizeof(tail_t) * 100);
	for (int i =0; i < tsize; ++i){
		drone.tail[i].x = x + i +1;
		drone.tail[i].y = y;
	}
	return drone;
}

void move_drone(char matrix2[MAX_X][MAX_Y], drone_t *drone){
	
	//if (drone->direction==STOP) return;
	
	// for (int i = drone->tsize - 1; i > 0; i--){
	// 	drone->tail[i] = drone->tail[i-1];
	// 	}
	// drone->tail[0].x = drone->x;
	// drone->tail[0].y = drone->y;
	matrix2[drone->x][drone->y]=' ';
	if (drone->direction==UP){
		drone->y = (drone->y - 1);	
		if (drone->y < 0){
			drone->y = MAX_Y;
			}
	}
	if (drone->direction==DOWN){
		drone->y = (drone->y + 1);	
		if (drone->y > MAX_Y){
			drone->y = 0;
		}
	}
	if (drone->direction==LEFT){
		drone->x = (drone->x - 1);	
		if (drone->x < 0){
			drone->x = MAX_X;
		}
	}
	if (drone->direction==RIGHT){
		drone->x = (drone->x + 1);	
		if (drone->x > MAX_X){
			drone->x = 0;
		}
	}
	matrix2[drone->x][drone->y]='X';
	return;
}

void print_drone(char matrix2[MAX_X][MAX_Y]){
	for (int i=0; i<MAX_Y+7; i++){
		printf ("\033[A");
	}
    for (int i=1; i<MAX_Y; i++){
        for (int j=1; j<MAX_X; j++){
            if (matrix2[i][j]=='X'){
				printf("\x1b[31m%c\x1b[0m", 'Q');
            }
        }
		printf("\n");
    }
}

    // matrix[drone0.x][drone0.y]='X';

    //             if (matrix[i][j]=='X'){
	// 				printf("\x1b[32m%c\x1b[0m", matrix[i][j]);
    //         }