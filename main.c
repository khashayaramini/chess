#include "chess.h"
#include <stdio.h>

int main(){
        struct game game;
        init_game(&game, 5);
        bool game_ended = false;
        while (!game_ended) {
                print_game(game, game.move);
                char si, sj, ei, ej;
                scanf(" %c%c%c%c", &si, &sj, &ei, &ej);
                printf(" %d %d %d %d\n", si-97, sj-49, ei-97, ej-49);
                int i = make_move(&game, game.move, (struct position){.i=si-97, .j=sj-49}, (struct position){.i=ei-97, .j=ej-49});
                // int i = make_move(&game, game.move, (struct position){.i=0, .j=1}, (struct position){.i=ei97, .j=ej-49});
                if(i == 1)
                        printf("move not possible!");
                printf("\n----------------------------------------------\n");
        }
        return 0;
}
