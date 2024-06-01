#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

#define MAX_X 15
#define MAX_Y 15

typedef struct tail_t{
	int x;
	int y;
} tail_t;
	
typedef struct snake_t{
	int x;
	int y;
	struct tail_t * tail;
	size_t tsize;
}  snake_t;
// --> x
// || Y
// \/
// @**
struct snake_t initSnake(int x, int y, size_t tsize){
	struct snake_t snake;
	snake.x = x;
	snake.y = y;
	snake.tsize = tsize;
	snake.tail = (tail_t *) malloc (sizeof(tail_t) * 100);
	for (int i =0; i < tsize; ++i){
		snake.tail[i].x = x + i +1;
		snake.tail[i].y = y;
		}
	return snake;
}

// @**
void printSnake(struct snake_t snake){
		char matrix[MAX_X][MAX_Y];
		for (int i = 0; i < MAX_X; ++i){
			for (int j = 0; j < MAX_Y; ++j)
			{
				matrix[i][j] = '.';
				}}
		
		matrix[snake.x][snake.y] = '@';
		for (int i = 0; i < snake.tsize; ++i){
			matrix[snake.tail[i].x][snake.tail[i].y] = '*';
			}
		
		for (int j = 0; j < MAX_Y; ++j){
			for (int i = 0; i < MAX_X; ++i)
			{
				printf("%c", matrix[i][j]);
				}
				printf("\n");
				}
	}
	
// <--  @** tsize = 2
//     @**

//  @**      @***
//    * <--     *
//  ***        **
snake_t moveLeft(snake_t snake){
	for (int i = snake.tsize - 1; i > 0; i--){
		snake.tail[i] = snake.tail[i-1];
		}
	snake.tail[0].x = snake.x;
	snake.tail[0].y = snake.y;
	
	snake.x = snake.x - 1;	
	if (snake.x < 0){
		snake.x = MAX_X - 1;
		}
	return snake;
	}

snake_t moveRight(snake_t snake){
	for (int i = snake.tsize - 1; i > 0; i--){
		snake.tail[i] = snake.tail[i-1];
	}
	snake.tail[0].x = snake.x;
	snake.tail[0].y = snake.y;
	
	snake.x = snake.x + 1;	
	if (snake.x > MAX_X-1){
		snake.x = 0;
		}
	return snake;
	}

snake_t moveDown(snake_t snake){
	for (int i = snake.tsize - 1; i > 0; i--){
		snake.tail[i] = snake.tail[i-1];
		}
	snake.tail[0].x = snake.x;
	snake.tail[0].y = snake.y;
	
	snake.y = snake.y + 1;	
	if (snake.y > MAX_Y-1){
		snake.y = 0;
	}
	return snake;
	}

snake_t moveUp(snake_t snake){
	for (int i = snake.tsize - 1; i > 0; i--){
		snake.tail[i] = snake.tail[i-1];
		}
	snake.tail[0].x = snake.x;
	snake.tail[0].y = snake.y;
	
	snake.y = snake.y - 1;	
	if (snake.y < 0){
		snake.y = MAX_Y - 1;
		}
	return snake;
	}

void checkDirection(int direction, char ch){
	if ((direction==1 && (ch=='d' || ch=='D')) ||
		(direction==2 && (ch=='a' || ch=='A')) || 
		(direction==3 && (ch=='s' || ch=='S')) ||
		(direction==4 && (ch=='w' || ch=='W'))){
			printf ("Game over!");
			exit(0);
		}
	
	return;
}
int main(){
	struct snake_t snake = initSnake( 10, 5, 2);
	int direction=0; //0 -stop, 1-left, 2-right, 3-up, 4-down

	while(1)//for( int i = 0; i < 8; ++i)
	{
		if (kbhit()) {
            char ch = getch();
			checkDirection (direction, ch);
			if (ch=='w' || ch=='W') direction=3;
			if (ch=='a' || ch=='A') direction=1;
			if (ch=='s' || ch=='S') direction=4;
			if (ch=='d' || ch=='D') direction=2;
			
		}

		system("cls");
		if (direction==1) snake = moveLeft(snake);
		if (direction==2) snake = moveRight(snake);
		if (direction==3) snake = moveUp(snake);
		if (direction==4) snake = moveDown(snake);
		printSnake(snake);
		sleep(1);
	}
	return 0;
}
