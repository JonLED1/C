#include "config.h"

typedef struct {
	int direction;
	int x;
	int y;
	int pumpkins;
}  drone_t;

void move_drone(char matrix[MAX_X][MAX_Y], drone_t *drone);
drone_t init_drone(int direction, int x, int y);


