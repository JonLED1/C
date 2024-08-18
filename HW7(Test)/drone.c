#include <stdio.h>
#include <stdlib.h>

#include "config.h"
	
typedef struct {
	int direction;
	int x;
	int y;
}  drone_t;

drone_t init_drone(int direction, int x, int y){
	drone_t drone;
	drone.direction=direction;
	drone.x = x;
	drone.y = y;
	return drone;
}

void move_drone(char matrix[MAX_X][MAX_Y], drone_t *drone){
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
	matrix[drone->x][drone->y]='X';
	return;
}