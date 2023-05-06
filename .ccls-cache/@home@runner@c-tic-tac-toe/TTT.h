#ifndef TTT_H
#define TTT_H
#include <stdbool.h>
#include <stdio.h>

struct TTT {
    char board[9];
    int current_turn; // even is X, odd is O
};

void TTT_display(struct TTT *game);

struct TTT TTT_initialize();

struct TTT TTT_copy(struct TTT *game);

bool TTT_update_board(struct TTT *game, int input_square);

bool TTT_check_win(struct TTT *game);

char TTT_get_last_turn(struct TTT *game);

bool TTT_check_draw(struct TTT *game);

#endif /* TTT_H */