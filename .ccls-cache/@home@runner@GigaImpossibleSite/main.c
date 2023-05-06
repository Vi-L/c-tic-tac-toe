#include <stdbool.h>
#include <stdio.h>

struct TTT {
    char board[9];
    bool current_turn;
};

int main(void) {
    int input_square;
    int res = scanf("%d", &input_square);
    printf("%d %d\n", input_square, res);

    // board (array of chars) + current turn (bool?) in struct 
    // check_win (take board, return bool for if player has won)
    // update_board (take board and current turn, return new board)
    // check_draw (take board, return bool )
    // display (take TTT, print to console)
    
    struct TTT game = {};

    for (int i = 0; i < 9; i++) {
        game.board[i] = i + 1;
    }
    
    printf("%c \n", game.board[0]);
  return 0;
}