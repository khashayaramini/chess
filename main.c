#include "chess.h"
#include <stdio.h>

int main(){
  struct game game;
  init_game(&game, 5);
  print_game(game, 1);
  int i = make_move(&game, WHITE, (struct position){.i=1, .j=0}, (struct position){.i=0, .j=2});
  printf("%d\n", i);
  print_game(game, 1);
  return 0;
}
