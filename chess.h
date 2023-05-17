#ifndef CHESS_HEADER
#define CHESS_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// color definitions
#define NON -1
#define BLACK 0
#define WHITE 1

// piece definitions
#define KING 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROCK 4
#define QUEEN 5

// point definitions
#define KING_VALUE 0
#define PAWN_VALUE 1
#define KNIGHT_VALUE 3
#define BISHOP_VALUE 3
#define ROCK_VALUE 5
#define QUEEN_VALUE 9

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

struct position{
  int i;
  int j;
};


void init_game(struct game *game, int time);

// turn: black -> 0, white -> 1
void print_game(struct game game, int turn);

// turn: black -> 0, white -> 1
// return:
//  0 -> ok
//  1 -> move not possible
int move_possible(struct game *game, int turn, struct position start_position, struct position end_position);
int bishop_move_possible(struct game *game, int turn, struct position start_position, struct position end_position);
int rock_move_possible(struct game *game, int turn, struct position start_position, struct position end_position);
int make_move(struct game *game, int turn, struct position start_position, struct position end_position);

// true -> 1, false -> 0
bool ckeck_is_white_in_check(struct game *game);
bool ckeck_is_black_in_check(struct game *game);

#endif
