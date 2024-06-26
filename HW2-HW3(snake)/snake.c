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

void printSnake(snake_t snake, snake_t snake2, food_t food, int players){
		char matrix[MAX_X][MAX_Y];
		for (int i = 0; i < MAX_X; ++i){
			for (int j = 0; j < MAX_Y; ++j){
				matrix[i][j] = '.';
			}
		}
		matrix[snake.x][snake.y] = '@';
		for (int i = 0; i < snake.tsize; ++i){
			matrix[snake.tail[i].x][snake.tail[i].y] = '*';
		}

		if (players==2){
			matrix[snake2.x][snake2.y] = '%';
			for (int i = 0; i < snake2.tsize; ++i){
				matrix[snake2.tail[i].x][snake2.tail[i].y] = '+';
			}
		}

		matrix[food.x][food.y] = 'o';
		for (int i=0; i<16; i++){
			printf ("\033[A");
		}
		
		for (int j = 0; j < MAX_Y; ++j){
			for (int i = 0; i < MAX_X; ++i){
				if (matrix[i][j]=='@' || matrix[i][j]=='*'){
					printf("\x1b[31m%c\x1b[0m", matrix[i][j]);
				}
				else if (matrix[i][j]=='%' || matrix[i][j]=='+'){
					printf("\x1b[34m%c\x1b[0m", matrix[i][j]);
				}
				else if (matrix[i][j]=='o'){
					printf("\x1b[32m%c\x1b[0m", matrix[i][j]);
				}
				else{
					printf("%c", matrix[i][j]);
				}
		
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

int checkDirection(snake_t snake,  char ch, int players){
	if (snake.tsize==0) return;
	if ((snake.direction==LEFT && (ch=='d' || ch=='D')) ||
		(snake.direction==RIGHT && (ch=='a' || ch=='A')) || 
		(snake.direction==UP && (ch=='s' || ch=='S')) ||
		(snake.direction==DOWN && (ch=='w' || ch=='W'))){
			if (players==2){
				printf ("\nGame over! Move back snake_1! Snake_2 win!");
			}
			else{
				printf ("\nGame over! Move back!");
			}
			delay(5000);
			return 1;
		}
	return 0;
}

int checkDirection2(snake_t snake,  char ch, int players){
	if (snake.tsize==0) return;
	if ((snake.direction==LEFT && (ch==';' || ch==':')) ||
		(snake.direction==RIGHT && (ch=='k' || ch=='K')) || 
		(snake.direction==UP && (ch=='l' || ch=='L')) ||
		(snake.direction==DOWN && (ch=='o' || ch=='O'))){
			printf ("\nGame over! Move back snake_2! Snake_1 win!");
			delay(5000);
			return 1;
		}
	return 0;
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

_Bool isCrush(snake_t snake){
	for(size_t i=1; i<snake.tsize; i++){
		if(snake.x == snake.tail[i].x && snake.y == snake.tail[i].y) return 1;
	}
 	return 0;
}

int mainMenu(){
	system("cls");
	printf("-=Game Snake=-\n");
	printf("Options:\n 1 - One player. \n 2 - Two players.\n 3 - Exit.\n");
	while(1){
		char ch = getch();
		if (ch=='1') return 1;
		if (ch=='2') return 2;
		if (ch=='3'){
			printf("Thanks for playing! Good luck!");
			exit(0);
		}
	}
}

void main(){
	while(1){
		float speed=1;
		int players=mainMenu();
		struct snake_t snake = initSnake(STOP, 5, 5, 0);
		struct snake_t snake2 = initSnake(STOP, 10, 10, 0);
		struct food_t food = putFood(food);

		system("cls");
		while(1){ 
			if (kbhit()) {
            	char ch = getch();
				if (ch=='p' || ch=='P') snake.direction=STOP;
				if (ch=='q' || ch=='Q') break;;
				if (checkDirection (snake, ch, players)==1) break;
				if (ch=='w' || ch=='W') snake.direction=UP;
				if (ch=='a' || ch=='A') snake.direction=LEFT;
				if (ch=='s' || ch=='S') snake.direction=DOWN;
				if (ch=='d' || ch=='D') snake.direction=RIGHT;
				if (players==2){
					if (checkDirection2 (snake2, ch, players)==1) break;;
					if (ch=='o' || ch=='O') snake2.direction=UP;
					if (ch=='k' || ch=='K') snake2.direction=LEFT;
					if (ch=='l' || ch=='L') snake2.direction=DOWN;
					if (ch==';' || ch==':') snake2.direction=RIGHT;
				}
			}
		
			snake = move(snake);
			if (players==2) snake2 = move(snake2);
			printSnake(snake, snake2, food, players);

			printf("Score: snake_1=%d | snake_2=%d | P-pause | Q-main menu\n", snake.tsize, snake2.tsize);
			delay(1000/speed);
			if (checkEat(snake, food)){
				snake.tsize++;
				food = putFood(food);
				speed = speed + 0.3;
			}
			if (checkEat(snake2, food)){
				snake2.tsize++;
				food = putFood(food);
				speed = speed + 0.3;
			}
			if(isCrush(snake)){
				if (players==2) printf ("\nGame over!!! Suicide snake_1! Snake_2 win!");
				else printf ("\nGame over!!! Suicide snake.");
				delay(5000);
				break;
			} 
			if(isCrush(snake2)){
				printf ("\nGame over!!! Suicide snake_2! Snake_1 win!");
				delay(5000);
				break;
			} 
		}
	}
}