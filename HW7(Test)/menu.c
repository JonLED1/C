#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <sys/time.h>

void delay(unsigned milliseconds){
    clock_t pause;
    clock_t start;
    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    start = clock();
    while( (clock() - start) < pause );
}

void set_cursor(unsigned x, unsigned y){
  printf("%c[%d;%df",0x1B,x,y);
}

void clear_screen(){
  set_cursor(1,1);
  for (int n=1; n<19; n++){
    printf("                                                             \n");
    delay(25);
  }
}

void start_screen(){
  system("cls");
  printf("           --                                  --            \n\
   -----   --  ------                  -----   --  ------    \n\
 -----------------------            -------------------------\n\
          -----                               -----          \n\
         ------                               ------         \n\
         +++++++                             +++++++         \n\
         ------++++                       ++++------         \n\
         ------++++++++++   +++++   ++++++++++------         \n\
          -----   +++++++++++++++++++++++++   -----          \n\
                      +++++++++++++++++                      \n\
                     +++++ +++++++ ++++++                    \n\
                   +++++ ----...---- +++++                   \n\
                  +++++ +---.....---+ +++++                  \n\
                  ++++  +----...----+  ++++                  \n\
                 ++++    -----------    ++++                 \n\
                 ++++                   ++++                 \n\
                 ++++                    +++                 \n\
");
delay(1000);
clear_screen();
}

int main_menu(){
  set_cursor(3,10);
  printf("-= PUMPKIN DRONE =-\n\n");
  printf("Game options:\n");
  printf("1. Manual mode\n2. Automatic mode\n3. Exit\n");
  while(1){
		char ch = getch();
		if (ch=='1') return 0;
		if (ch=='2'){
      printf("Select the number of drones (1-5)\n");
      while(1){
        char ch = getch();
        if (ch=='1') return 1;
        if (ch=='2') return 2;
        if (ch=='3') return 3;
        if (ch=='4') return 4;
        if (ch=='5') return 5;
      }
    }
		if (ch=='3'){
			printf("Thanks for playing! Good luck!");
      delay(1000);
			exit(0);
		}
	}
}

int game_menu(int game_mode, int score[6]){
  printf("_____________________________\n\n");
  if (game_mode==0){
    printf("UP-W DOWN-S LEFT-A RIGHT-D QUIT-Q PAUSE-P\n");
    printf("Score - %d\n", score[0]);
  }
  else{
    printf("QUIT-Q PAUSE-P\n");
    for (int i=1; i<=game_mode; i++){
      printf("Score Drone %d - %d\n", i, score[i]);
    }
  }
}
