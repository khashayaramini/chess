#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * color: black -> 0, white -> 1
 * type:
 * king -> 0
 * pawn -> 1
 * knight -> 2
 * bishop -> 3
 * rock -> 4
 * queen -> 5
 * */
struct piece{
  int value;
  int type;
  int color;
};

struct square{
  int i;
  int j;
  struct piece piece;
  bool empty;
};

/*
 * move: black -> 0, white -> 1
 * board index starts from bottom left corner
 * index increase ny going right in each row then going to the upper row
 * */
struct game{
  struct square board[64];
  int white_score;
  int black_score;
  int move;
  bool is_white_check;
  bool is_black_check;
  int white_time;
  int black_time;
};

void init_game(struct game* game){
  // setting square index
  for(int i = 0; i < 64; i++){
    game->board[i].i = i % 8;
    game->board[i].j = i / 8;
    game->board[i].empty = true;
  }

  // putting pieces in place
}

void print_game(struct game game){

}

int main(){
  struct game game;
  init_game(&game);
  printf("%d, %d \n", game.board[10].i, game.board[10].j);
  return 0;
}
