// см. readme
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_X 15
#define MAX_Y 15
#define STOP 0
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

typedef struct tail_t{
	int x;
	int y;
} tail_t;
	
typedef struct snake_t{
	int direction;
	int x;
	int y;
	struct tail_t * tail;
	size_t tsize;
}  snake_t;

typedef struct food_t{
	int x;
	int y;
} food_t;

struct snake_t initSnake(int direction, int x, int y, size_t tsize){
	struct snake_t snake;
	snake.direction=direction;
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

void printSnake(snake_t snake, food_t food){
		char matrix[MAX_X][MAX_Y];
		for (int i = 0; i < MAX_X; ++i){
			for (int j = 0; j < MAX_Y; ++j){
				matrix[i][j] = '.';
			}
		}
		
		matrix[snake.x][snake.y] = '@';
		matrix[food.x][food.y] = 'o';
		for (int i = 0; i < snake.tsize; ++i){
			matrix[snake.tail[i].x][snake.tail[i].y] = '*';
		}
		
		for (int i=0; i<16; i++){
			printf ("\033[A");
		}
		
		for (int j = 0; j < MAX_Y; ++j){
			for (int i = 0; i < MAX_X; ++i){
				printf("%c", matrix[i][j]);
			}
				printf("\n");
		}
	}
	

snake_t move(snake_t snake){
	if (snake.direction==STOP) return snake;
	for (int i = snake.tsize - 1; i > 0; i--){
		snake.tail[i] = snake.tail[i-1];
		}
	snake.tail[0].x = snake.x;
	snake.tail[0].y = snake.y;
	if (snake.direction==UP){
		snake.y = snake.y - 1;	
		if (snake.y < 0){
			snake.y = MAX_Y - 1;
			}
	}
	if (snake.direction==DOWN){
		snake.y = snake.y + 1;	
		if (snake.y > MAX_Y-1){
			snake.y = 0;
		}
	}
	if (snake.direction==LEFT){
		snake.x = snake.x - 1;	
		if (snake.x < 0){
			snake.x = MAX_X - 1;
		}
	}
	if (snake.direction==RIGHT){
		snake.x = snake.x + 1;	
		if (snake.x > MAX_X-1){
			snake.x = 0;
		}
	}
	return snake;
}

void checkDirection(snake_t snake,  char ch){
	if (snake.tsize==0) return;
	if ((snake.direction==LEFT && (ch=='d' || ch=='D')) ||
		(snake.direction==RIGHT && (ch=='a' || ch=='A')) || 
		(snake.direction==UP && (ch=='s' || ch=='S')) ||
		(snake.direction==DOWN && (ch=='w' || ch=='W'))){
			printf ("Game over!");
			exit(0);
		}
}

food_t putFood(food_t food){
	food.x=rand() % MAX_X;
	food.y=rand() % MAX_Y;
	return food;
}

int checkEat(snake_t snake, food_t food){
	if (snake.x==food.x && snake.y==food.y) return 1;
	return 0;
}

void delay(unsigned milliseconds){
    clock_t pause;
    clock_t start;
    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    start = clock();
    while( (clock() - start) < pause );
}

int main(){
	struct snake_t snake = initSnake(STOP, 5, 5, 0);
	struct food_t food = putFood(food);
	float speed=1;
	system("cls");
	while(1)
	{
		if (kbhit()) {
            char ch = getch();
			checkDirection (snake, ch);
			if (ch=='w' || ch=='W') snake.direction=UP;
			if (ch=='a' || ch=='A') snake.direction=LEFT;
			if (ch=='s' || ch=='S') snake.direction=DOWN;
			if (ch=='d' || ch=='D') snake.direction=RIGHT;
			if (ch=='p' || ch=='P') snake.direction=STOP;
		}
		
		snake = move(snake);
		printSnake(snake, food);
		printf("Score-%d P-pause\n", snake.tsize);
		delay(1000/speed);
		if (checkEat(snake, food)){
			snake.tsize++;
			food = putFood(food);
			speed = speed + 0.3;
		}
	}
	return 0;
}
