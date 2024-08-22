#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <conio.h>

#include "config.h"
#include "menu.h"
#include "field.h"
#include "drone.h"

void main(){
    int game_mode=0;
    int place_field=MAX_X*MAX_Y;
    char matrix[MAX_X][MAX_Y];
    char matrix2[MAX_X][MAX_Y];
    
    while(1){
        int ripe_pumpkins=0;
        int taked_pumpkins=0;
        start_screen();
        game_mode=main_menu();
        clear_screen();
        fill_field(matrix);
        fill_drone(matrix2);
        drone_t matrix3[6]={init_drone(STOP,0,10,0,'X'), init_drone(STOP,0,12,0,'B'), init_drone(STOP,0,14,0,'C'),
        init_drone(STOP,0,16,0,'P'), init_drone(STOP,0,18,0,'K'), init_drone(STOP,0,20,0,'Z')};

        while(1){
            for (int n=0; n<=game_mode; n++){
                if (n>0){
                    direction(matrix, &matrix3[n]);
                }
                move_drone(matrix2, &matrix3[n]);
                check_pump(matrix, &matrix3[n], &taked_pumpkins);
            }
            print_field(matrix);
            print_drone(matrix2);
            
            printf("_____________________________\n\n");
            if (game_mode==0){
                printf("UP-W DOWN-S LEFT-A RIGHT-D QUIT-Q PAUSE-P\n");
                printf("Drone %c take %d pumpkins\n", matrix3[0].symbol, matrix3[0].pumpkins);
            }
            else{
                printf("UP-W DOWN-S LEFT-A RIGHT-D QUIT-Q PAUSE-P\n");
                for (int n=0; n<=game_mode; n++){
                    printf("Drone %c take %d pumpkins\n", matrix3[n].symbol, matrix3[n].pumpkins);
                }
            }

            if (ripe_pumpkins<place_field){ //checking all ripe pumpkins
                ripening_pumpkis(matrix, &ripe_pumpkins);
            }
            if (taked_pumpkins==place_field){
                printf("CONGRATULATIONS! All the pumpkins have been taken!\n");
                //check for winner
                int winner=0;
                int max_pump=matrix3[0].pumpkins;
                for (int n=0; n<game_mode; n++){
                    if (matrix3[n].pumpkins>max_pump){
                        winner=n;
                        max_pump=matrix3[n].pumpkins;
                    }
                }
                printf("Winner is drone %C. He collected %d pumpkins\n", matrix3[winner].symbol, matrix3[winner].pumpkins);
                printf("Press space to exit main menu.\n");
                
                while (1){
                        if (kbhit()){
                            char ch = getch();
                            if (ch==' '){
                                system("cls");
                                break;
                            }
                        }
                    }
                  break;
            }
            if (kbhit()) {
            	char ch = getch();
				if (ch=='w' || ch=='W') matrix3[0].direction=UP;
				if (ch=='a' || ch=='A') matrix3[0].direction=LEFT;
				if (ch=='s' || ch=='S') matrix3[0].direction=DOWN;
				if (ch=='d' || ch=='D') matrix3[0].direction=RIGHT;
				if (ch=='p' || ch=='P'){
                    printf("GAME PAUSED. Press P to continue.");
                    matrix3[0].direction=STOP;
                    while (1){
                        if (kbhit()){
                            char ch = getch();
                            if (ch=='p' || ch=='P'){
                                system("cls");
                                break;
                            }
                        }
                    }
                }
				if (ch=='q' || ch=='Q') break;;
            }
            delay(200);
        }
    }
}