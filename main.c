#include "chess.h"
#include <stdbool.h>
#include <stdio.h>

int main(){
    struct game game;
    init_game(&game, 5);
    bool game_ended = false;
    while (!game_ended) {
        bool valid_input = true;
        print_game(game, game.move);
        char si, sj, ei, ej;
        int isi, isj, iei, iej;
        scanf(" %c%c%c%c", &si, &sj, &ei, &ej);
        isi = si - 97;
        isj = sj - 49;
        iei = ei - 97;
        iej = ej - 49;
        if(isi < 0 || isj < 0 || iei < 0 || iej < 0)
            valid_input = false;
        if(isi > 7 || isj > 7 || iei > 7 || iej > 7)
            valid_input = false;
        if(valid_input)
            make_move(&game, game.move, (struct position){.i=isi, .j=isj}, (struct position){.i=iei, .j=iej});
        printf("\n----------------------------------------------\n");
    }
    return 0;
}
