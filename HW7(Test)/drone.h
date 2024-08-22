#include "config.h"

typedef struct {
	int direction;
	int x;
	int y;
	int pumpkins;
	char symbol;
}  drone_t;


drone_t init_drone(int direction, int x, int y, int pumpkins, char symbol);
void fill_drone(char matrix2[MAX_X][MAX_Y]);
void move_drone(char matrix2[MAX_X][MAX_Y], drone_t *drone);
void direction(char matrix2[MAX_X][MAX_Y], drone_t *drone);
void check_pump(char matrix[MAX_X][MAX_Y], drone_t *drone, int *taked_pumpkins);
void print_drone(char matrix2[MAX_X][MAX_Y]);




