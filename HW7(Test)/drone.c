#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "drone.h"
#include "field.h"

drone_t init_drone(int direction, int x, int y, int pumpkins){
	drone_t drone;
	drone.direction=direction;
	drone.x = x;
	drone.y = y;
	drone.pumpkins = pumpkins;
	return drone;
}

void fill_drone(char matrix2[MAX_X][MAX_Y]){
	for (int i=0; i<MAX_X; i++){
        for (int j=0; j<MAX_Y; j++){
            matrix2[i][j]=' ';
        }
    }
}

void move_drone(char matrix2[MAX_X][MAX_Y], drone_t *drone){
	matrix2[drone->x][drone->y]=' ';
	if (drone->direction==UP){
		drone->x = drone->x - 1;	
		if (drone->x < 0){
			drone->x = MAX_X-1;
			}
	}
	if (drone->direction==DOWN){
		drone->x = drone->x + 1;	
		if (drone->x > MAX_X-1){
			drone->x = 0;
		}
	}
	if (drone->direction==LEFT){
		drone->y = drone->y - 1;	
		if (drone->y < 0){
			drone->y = MAX_Y-1;
		}
	}
	if (drone->direction==RIGHT){
		drone->y = drone->y + 1;	
		if (drone->y > MAX_Y-1){
			drone->y = 0;
		}
	}
	matrix2[drone->x][drone->y]='X';
	return;
}

void print_drone(char matrix2[MAX_X][MAX_Y]){
	for (int i=0; i<MAX_Y+7; i++){
		printf ("\033[A");
	}
    for (int i=0; i<MAX_X; i++){
        for (int j=0; j<MAX_Y; j++){
            if (matrix2[i][j]=='X'){
				printf("\x1b[31m%c\x1b[0m", matrix2[i][j]);
            }
			else{
				printf("\033[C");
			}
        }
		printf("\n");
    }
}

void check_pump(char matrix[MAX_X][MAX_Y], drone_t *drone){
	if (matrix[drone->x][drone->y]=='O'){
		matrix[drone->x][drone->y]=' ';
		drone->pumpkins=drone->pumpkins+1;
	}
	return;
}