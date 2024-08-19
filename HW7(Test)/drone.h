#include "config.h"

typedef struct {
	int direction;
	int x;
	int y;
	int pumpkins;
}  drone_t;

void move_drone(char matrix2[MAX_X][MAX_Y], drone_t *drone);
void print_drone(char matrix2[MAX_X][MAX_Y]);
void fill_drone(char matrix2[MAX_X][MAX_Y]);
void check_pump(char matrix[MAX_X][MAX_Y], drone_t *drone);
drone_t init_drone(int direction, int x, int y, int pumpkins);


