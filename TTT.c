#include <stdbool.h>
#include <stdio.h>
#include "TTT.h"

void TTT_display(struct TTT *game) {
    for (int i = 0; i < 9; i++) {
        printf("%c ", game->board[i]); //(*game).board
        if ((i + 1) % 3 == 0) {
            puts("");
        }
    }
}

struct TTT TTT_initialize() {
    struct TTT game = {};

    for (int i = 0; i < 9; i++) {
        game.board[i] = i + '1'; //adds 49
    }

    return game;
}

struct TTT TTT_copy(struct TTT *game) {
    struct TTT copy = {};

    for (int i = 0; i < 9; i++) {
        copy.board[i] = game->board[i];
    }
    copy.current_turn = game->current_turn;

    return copy;
}

bool TTT_update_board(struct TTT *game, int input_square) {
    char turn_char;
    if (game->current_turn % 2 == 0) {
        turn_char = 'X';
    } else {
        turn_char = 'O';
    }
    if (game->board[input_square] == 'X' || game->board[input_square] == 'O') {
        return false;
    }
    game->board[input_square] = turn_char;

    game->current_turn++;
    return true;
}

bool TTT_check_win(struct TTT *game) {
    if (game->current_turn < 5) {
        return false;
    }
    
    for (int i = 0; i < 9; i += 3) { // rows
        if (game->board[i] == game->board[i + 1] 
            && game->board[i + 1] == game->board[i + 2]) {
                return true;
            }
    }
    for (int i = 0; i < 3; i++) { //cols
        if (game->board[i] == game->board[i + 3]
            && game->board[i + 3] == game->board[i + 6]) {
            return true;
            }
    }
    if (game->board[0] == game->board[4] // left to right diagonal
        && game-> board[4] == game->board[8]) {
        return true;
        }
    if (game->board[2] == game->board[4] // right to left diagonal
        && game-> board[4] == game->board[6]) {
        return true;
        }
    return false;
}

char TTT_get_last_turn(struct TTT *game) {
    if ((game->current_turn) % 2 == 0) {
        return 'O';
    } else {
        return 'X';
    }
}

bool TTT_check_draw(struct TTT *game) {
    return game->current_turn >= 9;
}