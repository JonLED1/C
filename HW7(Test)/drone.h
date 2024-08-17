#include "config.h"

typedef struct {
	int x;
	int y;
} tail_t;

typedef struct {
	int direction;
	int x;
	int y;
	struct tail_t * tail;
	size_t tsize;
}  drone_t;

drone_t init_drone(int direction, int x, int y, size_t tsize);

void print_drone(char matrix2[MAX_X][MAX_Y]);
void move_drone(char matrix2[MAX_X][MAX_Y], drone_t *drone);
