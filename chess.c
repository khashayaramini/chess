#include "chess.h"
#include <stdio.h>
#include <wchar.h>

void init_game(struct game *game, int time){
  // setting game status
  game->black_time = time;
  game->white_time = time;
  game->black_score = 0;
  game->white_score = 0;
  game->move = WHITE;
  game->is_black_check = false;
  game->is_white_check = false;

  // setting square index
  for(int i = 0; i < 64; i++){
    game->board[i].i = i % 8;
    game->board[i].j = i / 8;
    game->board[i].empty = true;
    game->board[i].piece.color = NON;
    game->board[i].piece.type= NON;
    game->board[i].piece.value = NON;
  }

  // putting pieces in place
  for(int i = 0; i < 8; i++){
    // setting white pawns
    game->board[i+8].piece.color = WHITE;
    game->board[i+8].piece.type= PAWN;
    game->board[i+8].piece.value = PAWN_VALUE;
    game->board[i+8].empty = false;
    // setting black pawns
    game->board[i+48].piece.color = BLACK;
    game->board[i+48].piece.type= PAWN;
    game->board[i+48].piece.value = PAWN_VALUE;
    game->board[i+48].empty = false;
  }

  // setting white queen
  game->board[3].piece.color = WHITE;
  game->board[3].piece.type= QUEEN;
  game->board[3].piece.value = QUEEN_VALUE;
  game->board[3].empty = false;

  // setting white king
  game->board[4].piece.color = WHITE;
  game->board[4].piece.type= KING;
  game->board[4].piece.value = KING_VALUE;
  game->board[4].empty = false;

  // setting black queen
  game->board[59].piece.color = BLACK;
  game->board[59].piece.type= QUEEN;
  game->board[59].piece.value = QUEEN_VALUE;
  game->board[59].empty = false;

  // setting black king
  game->board[60].piece.color = BLACK;
  game->board[60].piece.type= KING;
  game->board[60].piece.value = KING_VALUE;
  game->board[60].empty = false;

  //setting white rocks
  game->board[0].piece.color = WHITE;
  game->board[0].piece.type= ROCK;
  game->board[0].piece.value = ROCK_VALUE;
  game->board[0].empty = false;
  game->board[7].piece.color = WHITE;
  game->board[7].piece.type= ROCK;
  game->board[7].piece.value = ROCK_VALUE;
  game->board[7].empty = false;

  //setting black rocks
  game->board[56].piece.color = BLACK;
  game->board[56].piece.type= ROCK;
  game->board[56].piece.value = ROCK_VALUE;
  game->board[56].empty = false;
  game->board[63].piece.color = BLACK;
  game->board[63].piece.type= ROCK;
  game->board[63].piece.value = ROCK_VALUE;
  game->board[63].empty = false;

  //setting white knights
  game->board[1].piece.color = WHITE;
  game->board[1].piece.type= KNIGHT;
  game->board[1].piece.value = KNIGHT_VALUE;
  game->board[1].empty = false;
  game->board[6].piece.color = WHITE;
  game->board[6].piece.type= KNIGHT;
  game->board[6].piece.value = KNIGHT_VALUE;
  game->board[6].empty = false;

  //setting black knights
  game->board[57].piece.color = BLACK;
  game->board[57].piece.type= KNIGHT;
  game->board[57].piece.value = KNIGHT_VALUE;
  game->board[57].empty = false;
  game->board[62].piece.color = BLACK;
  game->board[62].piece.type= KNIGHT;
  game->board[62].piece.value = KNIGHT_VALUE;
  game->board[62].empty = false;

  //setting white bishops
  game->board[2].piece.color = WHITE;
  game->board[2].piece.type= BISHOP;
  game->board[2].piece.value = BISHOP_VALUE;
  game->board[2].empty = false;
  game->board[5].piece.color = WHITE;
  game->board[5].piece.type= BISHOP;
  game->board[5].piece.value = BISHOP_VALUE;
  game->board[5].empty = false;

  //setting black bishops
  game->board[58].piece.color = BLACK;
  game->board[58].piece.type= BISHOP;
  game->board[58].piece.value = BISHOP_VALUE;
  game->board[58].empty = false;
  game->board[61].piece.color = BLACK;
  game->board[61].piece.type= BISHOP;
  game->board[61].piece.value = BISHOP_VALUE;
  game->board[61].empty = false;
}

void print_game(struct game game, int turn){
  if(turn == WHITE){
    for(int j = 7; j >= 0; j--){
      printf("%d| ", j+1);
      for(int i = 0; i < 8; i++){
        int index = j*8 + i;
        if(game.board[index].empty)
          printf(" .. ");
        else{
          struct piece piece = game.board[index].piece;
          printf(" ");
          if(piece.color == BLACK)
          switch (piece.type) {
            case PAWN:
              printf("\U00002659");
              break;
            case KNIGHT:
              printf("\U00002658");
              break;
            case BISHOP:
              printf("\U00002657");
              break;
            case ROCK:
              printf("\U00002656");
              break;
            case QUEEN:
              printf("\U00002655");
              break;
            case KING:
              printf("\U00002654");
              break;
          }
        else
          switch (piece.type) {
            case PAWN:
              printf("\U0000265F");
              break;
            case KNIGHT:
              printf("\U0000265E");
              break;
            case BISHOP:
              printf("\U0000265D");
              break;
            case ROCK:
              printf("\U0000265C");
              break;
            case QUEEN:
              printf("\U0000265B");
              break;
            case KING:
              printf("\U0000265A");
              break;
          }
          printf("  ");
        }
        // printf(" %c%d ", game.board[index].piece.color == WHITE ? 'W' : 'B', game.board[index].piece.type);
      }
      printf("\n");
    }
    printf("  ");
    for(int i = 0; i < 8; i++)
      printf("  %c ", i+65);
  }else{
    for(int j = 0; j < 8; j++){
      printf("%d| ", j+1);
      for(int i = 7; i >= 0; i--){
        int index = j*8 + i;
        if(game.board[index].empty)
          printf(" .. ");
        else{
          struct piece piece = game.board[index].piece;
          printf(" ");
          if(piece.color == BLACK)
            switch (piece.type) {
              case PAWN:
                printf("\U00002659");
                break;
              case KNIGHT:
                printf("\U00002658");
                break;
              case BISHOP:
                printf("\U00002657");
                break;
              case ROCK:
                printf("\U00002656");
                break;
              case QUEEN:
                printf("\U00002655");
                break;
              case KING:
                printf("\U00002654");
                break;
            }
          else
            switch (piece.type) {
              case PAWN:
                printf("\U0000265F");
                break;
              case KNIGHT:
                printf("\U0000265E");
                break;
              case BISHOP:
                printf("\U0000265D");
                break;
              case ROCK:
                printf("\U0000265C");
                break;
              case QUEEN:
                printf("\U0000265B");
                break;
              case KING:
                printf("\U0000265A");
                break;
            }
          printf("  ");
        }
      }
      printf("\n");
    }
    printf("  ");
    for(int i = 7; i >= 0; i--)
      printf("  %c ", i+65);
  }
}

int bishop_move_possible(struct game *game, int turn, struct position start_position, struct position end_position){
  int i_diff = end_position.i - start_position.i; 
  int j_diff = end_position.j - start_position.j;
  if(i_diff == j_diff || i_diff == j_diff * -1){
    bool possible = true;
    if(i_diff > 0 && j_diff > 0)
      for(int k = 1; k < i_diff; k++)
        if(!game->board[(start_position.j + k)*8 + start_position.i + k].empty)
          possible = false;
    if(i_diff > 0 && j_diff < 0)
      for(int k = 1; k < i_diff; k++)
        if(!game->board[(start_position.j - k)*8 + start_position.i + k].empty)
          possible = false;
    if(i_diff < 0 && j_diff > 0)
      for(int k = 1; k < i_diff; k++)
        if(!game->board[(start_position.j + k)*8 + start_position.i - k].empty)
          possible = false;
    if(i_diff < 0 && j_diff < 0)
      for(int k = 1; k < i_diff; k++)
        if(!game->board[(start_position.j - k)*8 + start_position.i - k].empty)
          possible = false;
    if(possible)
      return 0;
  }
}
int rock_move_possible(struct game *game, int turn, struct position start_position, struct position end_position){
  if(start_position.i == end_position.i || start_position.j == end_position.j){
    bool possible = true;
    if(start_position.i == end_position.i){
      for (int k = start_position.j + 1; k < end_position.j; k++) {
        if(!game->board[k*8 + start_position.i].empty)
          possible = false;
      }
      for (int k = start_position.j + 1; k > end_position.j; k--) {
        if(!game->board[k*8 + start_position.i].empty)
          possible = false;
      }
    }
    if(start_position.j == end_position.j){
      for (int k = start_position.i + 1; k < end_position.i; k++) {
        if(!game->board[start_position.j*8 + k].empty)
          possible = false;
      }
      for (int k = start_position.i + 1; k > end_position.i; k--) {
        if(!game->board[start_position.j*8 + k].empty)
          possible = false;
      }
      if(possible)
        return 0;
    }
  }
}
int move_possible(struct game *game, int turn, struct position start_position, struct position end_position){
  // check obv illegal moves
  if(start_position.i == end_position.i && start_position.j == end_position.j)
    return 1;
  int start_index = start_position.j * 8 + start_position.i;
  int end_index = end_position.j * 8 + end_position.i;
  if(game->board[start_index].empty)
    return 1;
  struct piece piece = game->board[start_index].piece;
  if(piece.color != turn)
    return 1;
  if(game->board[end_index].piece.color == turn)
    return 1;

  // make move based on piece type
  if(piece.type == PAWN){
    if(turn == WHITE){
      if(start_position.i == end_position.i){
        if(start_position.j == end_position.j - 1 && 
          game->board[end_index].empty)
          return 0;
        if(start_position.j == end_position.j - 2 && 
          game->board[end_index].empty && 
          game->board[(start_position.j + 1)*8 + start_position.i].empty &&
          start_position.j == 1)
          return 0;
      }else if(start_position.j == end_position.j - 1 &&
          !game->board[end_index].empty &&
          game->board[end_index].piece.color != turn &&
          (start_position.i == end_position.i - 1 || start_position.i == end_position.i + 1))
        return 0;
    }else{
      if(start_position.i == end_position.i){
        if(start_position.j == end_position.j + 1 && 
          game->board[end_index].empty)
          return 0;
        if(start_position.j == end_position.j + 2 && 
          game->board[end_index].empty && 
          game->board[(start_position.j - 1)*8 + start_position.i].empty &&
          start_position.j == 6)
          return 0;
      }else if(start_position.j == end_position.j + 1 &&
          !game->board[end_index].empty &&
          game->board[end_index].piece.color != turn &&
          (start_position.i == end_position.i - 1 || start_position.i == end_position.i + 1))
        return 0;
    }
  }else if(piece.type == ROCK){
    return rock_move_possible(game, turn, start_position, end_position);
  }else if(piece.type == BISHOP){
    return bishop_move_possible(game, turn, start_position, end_position);
  }else if(piece.type == KNIGHT){
    int i_diff = end_position.i - start_position.i; 
    int j_diff = end_position.j - start_position.j;
    if(i_diff == 1 || i_diff == -1 || i_diff == 2 || i_diff == -2)
    if(j_diff == 1 || j_diff == -1 || j_diff == 2 || j_diff == -2)
    if(i_diff != j_diff && i_diff != j_diff * 1)
      return 0;
  }else if(piece.type == QUEEN){
    int bp = bishop_move_possible(game, turn, start_position, end_position);
    int rp = rock_move_possible(game, turn, start_position, end_position);
    return bp & rp;
  }else if(piece.type == KING){
    int i_diff = end_position.i - start_position.i; 
    int j_diff = end_position.j - start_position.j;
    if(i_diff >= -1 && i_diff <= 1 && j_diff >= -1 && j_diff <= 1)
      return 0;
  }
  return 1;
}

bool ckeck_is_white_in_check(struct game *game){
  bool check = false;
  int king_pos;
  for(int i = 0; i < 64; i++)
    if(game->board[i].piece.type == KING && game->board[i].piece.color == WHITE)
      king_pos = i;
  for(int i = 0; i < 64; i++)
    if(game->board->piece.color == BLACK
      && move_possible(game, BLACK, (struct position){.i = i% 8, .j = i / 8}, (struct position){.i = king_pos % 8, .j = king_pos / 8}) == 0){
      check = true;
    }
  return check;
}
bool ckeck_is_black_in_check(struct game *game){
  bool check = false;
  int king_pos;
  for(int i = 0; i < 64; i++)
    if(game->board[i].piece.type == KING && game->board[i].piece.color == BLACK)
      king_pos = i;
  for(int i = 0; i < 64; i++)
    if(game->board->piece.color == WHITE
      && move_possible(game, WHITE, (struct position){.i = i% 8, .j = i / 8}, (struct position){.i = king_pos % 8, .j = king_pos / 8}) == 0){
      check = true;
    }
  return check;
}

int make_move(struct game *game, int turn, struct position start_position, struct position end_position){
  if(move_possible(game, game->move, start_position, end_position) == 0){
    struct game back_game = *game;
    int start_index = start_position.j * 8 + start_position.i;
    int end_index = end_position.j * 8 + end_position.i;
    game->board[end_index].empty = false;
    game->board[end_index].piece = game->board[start_index].piece;
    game->board[start_index].empty = true;
    game->board[start_index].piece.type = NON;
    game->board[start_index].piece.value = NON;
    game->board[start_index].piece.color = NON;
    if(game->move == WHITE){
      if(!ckeck_is_white_in_check(game)){
        game->move = BLACK;
        return 0;
      }
    }else{
      if(!ckeck_is_black_in_check(game)){
        game->move = WHITE;
        return 0;
      }
    }
    *game = back_game;
    return 1;
  }
  return 1;
}
