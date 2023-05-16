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

void init_game(struct game* game, int time){
  // setting game status
  game->black_time = time;
  game->white_time = time;
  game->black_score = 0;
  game->white_score = 0;
  game->move = 1;
  game->is_black_check = false;
  game->is_white_check = false;

  // setting square index
  for(int i = 0; i < 64; i++){
    game->board[i].i = i % 8;
    game->board[i].j = i / 8;
    game->board[i].empty = true;
    game->board[i].piece.color = -1;
    game->board[i].piece.type= -1;
    game->board[i].piece.value = -1;
  }

  // putting pieces in place
  for(int i = 0; i < 8; i++){
    // setting white pawns
    game->board[i+8].piece.color = 1;
    game->board[i+8].piece.type= 1;
    game->board[i+8].piece.value = 1;
    // setting black pawns
    game->board[i+48].piece.color = 0;
    game->board[i+48].piece.type= 1;
    game->board[i+48].piece.value = 1;
  }

  // setting white queen
  game->board[3].piece.color = 1;
  game->board[3].piece.type= 5;
  game->board[3].piece.value = 9;

  // setting white king
  game->board[4].piece.color = 1;
  game->board[4].piece.type= 0;
  game->board[4].piece.value = 0;

  // setting black queen
  game->board[59].piece.color = 0;
  game->board[59].piece.type= 5;
  game->board[59].piece.value = 9;

  // setting black king
  game->board[60].piece.color = 0;
  game->board[60].piece.type= 0;
  game->board[60].piece.value = 0;

  //setting white rocks
  game->board[0].piece.color = 1;
  game->board[0].piece.type= 4;
  game->board[0].piece.value = 5;
  game->board[7].piece.color = 1;
  game->board[7].piece.type= 4;
  game->board[7].piece.value = 5;

  //setting black rocks
  game->board[56].piece.color = 0;
  game->board[56].piece.type= 4;
  game->board[56].piece.value = 5;
  game->board[63].piece.color = 0;
  game->board[63].piece.type= 4;
  game->board[63].piece.value = 5;

  //setting white knights
  game->board[1].piece.color = 1;
  game->board[1].piece.type= 2;
  game->board[1].piece.value = 3;
  game->board[6].piece.color = 1;
  game->board[6].piece.type= 2;
  game->board[6].piece.value = 3;

  //setting black knights
  game->board[57].piece.color = 0;
  game->board[57].piece.type= 2;
  game->board[57].piece.value = 3;
  game->board[62].piece.color = 0;
  game->board[62].piece.type= 2;
  game->board[62].piece.value = 3;

  //setting white bishops
  game->board[2].piece.color = 1;
  game->board[2].piece.type= 3;
  game->board[2].piece.value = 3;
  game->board[5].piece.color = 1;
  game->board[5].piece.type= 3;
  game->board[5].piece.value = 3;

  //setting black bishops
  game->board[58].piece.color = 0;
  game->board[58].piece.type= 3;
  game->board[58].piece.value = 3;
  game->board[61].piece.color = 0;
  game->board[61].piece.type= 3;
  game->board[61].piece.value = 3;
}

// turn: black -> 0, white -> 1
void print_game(struct game game, int turn){
  if(turn)
    for(int j = 7; j >= 0; j--){
      for(int i = 0; i < 8; i++){
        int index = j*8 + i;
        printf(" %c%d ", game.board[index].piece.color ? 'W' : 'B', game.board[index].piece.value);
      }
      printf("\n");
    }
  else
    for(int j = 0; j < 8; j++){
      for(int i = 0; i < 8; i++){
        int index = j*8 + i;
        printf(" %c%d ", game.board[index].piece.color ? 'W' : 'B', game.board[index].piece.value);
      }
      printf("\n");
    }
}

int main(){
  struct game game;
  init_game(&game, 5);
  print_game(game, 1);
  return 0;
}
