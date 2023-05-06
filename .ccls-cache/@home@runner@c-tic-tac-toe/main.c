#include <stdbool.h>
#include <stdio.h>
#include "TTT.h"

// TODO: computer opponent
// Minimax - https://en.wikipedia.org/wiki/Minimax
// Monte Carlo - https://en.wikipedia.org/wiki/Monte_Carlo_method

/* function  minimax(node, depth, maximizingPlayer) is
    if depth = 0 or node is a terminal node then
        return the heuristic value of node
    if maximizingPlayer then
        value := −∞
        for each child of node do
            value := max(value, minimax(child, depth − 1, FALSE))
        return value
    else (* minimizing player *)
        value := +∞
        for each child of node do
            value := min(value, minimax(child, depth − 1, TRUE))
        return value
*/

int minimax(struct TTT *board, int depth, bool maximizing_player) {
    if (TTT_check_win(board)) {
        if (TTT_get_last_turn(board) == 'O') {
            return 1;
        } else {
            return -1;
        }
    } else if (TTT_check_draw(board)) {
        return 0;
    }

    if (maximizing_player) {
        int value = -2;
        int best_square = -1;
        for (int i = 0; i <= 8; i++) {
            // copy board
            struct TTT copy = TTT_copy(board);
            // apply move i using TTT_update_board (T/F)
            bool res = TTT_update_board(&copy, i);
            // if T, recurse with the child and flip maximizing_player
            // max(value, child call) 
            if (res) {
                int child_value = minimax(&copy, depth + 1, !maximizing_player);
                if (value < child_value) {
                    value = child_value;
                    best_square = i;
                }
            }
        }
        return depth == 0 ? best_square : value;
    } else { //minimizing player
        int value = 2;
        for (int i = 0; i <= 8; i++) {
            // copy board
            struct TTT copy = TTT_copy(board);
            // apply move i using TTT_update_board (T/F)
            bool res = TTT_update_board(&copy, i);
            // if T, recurse with the child and flip maximizing_player
            // min(value, child call) 
            if (res) {
                int child_value = minimax(&copy, depth + 1, !maximizing_player);
                if (value > child_value) {
                    value = child_value;
                }
            }
        }
        return value;
    }
}


int main(void) {
    /* Program Plan
    // board (array of chars) + current turn (bool?) in struct 
    // check_win (take board, return bool for if player has won)
    // update_board (take board and current turn, return new board)
    // check_draw (take board, return bool )
    // display (take TTT, print to console)
        */
    
    struct TTT g = TTT_initialize();
    struct TTT *game = &g;
    int input_square;
    int res;
    TTT_display(game);
    while (true) {
        res = scanf("%d", &input_square);
    
        if (res) {
            bool success = TTT_update_board(game, input_square - 1);
            while (!success) {
                res = scanf("%d", &input_square);
                if (res) {
                    success = TTT_update_board(game, input_square - 1);
                }
            }
            if (TTT_check_win(game)) {
                printf("Player %c won!", TTT_get_last_turn(game));
                break;
            } else if (TTT_check_draw(game)) {
                puts("Draw!");
                break;
            }
            
            int computer_move = minimax(game, 0, true);
            TTT_update_board(game, computer_move);
        }
        TTT_display(game);

        if (TTT_check_win(game)) {
            printf("Player %c won!", TTT_get_last_turn(game));
            break;
        } else if (TTT_check_draw(game)) {
            puts("Draw!");
            break;
        }
    }
    
  return 0;
}