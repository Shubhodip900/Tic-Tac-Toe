#include <iostream>
#include <vector>

using namespace std;

// Function to display the current state of the board
void displayBoard(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
}

// Function to check if a player has won
bool checkWin(const vector<char>& board, char player) {
    // Check rows, columns, and diagonals
    return (
        (board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)
    );
}

// Function to check if the game is a draw
bool checkDraw(const vector<char>& board) {
    for (char cell : board) {
        if (cell != 'X' && cell != 'O') {
            return false;
        }
    }
    return true;
}

// Function to switch the current player
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    vector<char> board(9);  // Game board
    char currentPlayer = 'X';  // Starting player
    char playAgain = 'y';  // Variable to check if players want to play again

    while (playAgain == 'y' || playAgain == 'Y') {
        // Initialize the board with numbers
        for (int i = 0; i < 9; ++i) {
            board[i] = '1' + i;
        }

        bool gameWon = false;
        bool gameDraw = false;

        while (!gameWon && !gameDraw) {
            displayBoard(board);

            // Prompt the current player to enter their move
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            // Check if the move is valid
            if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            // Update the board with the player's move
            board[move - 1] = currentPlayer;

            // Check for a win or draw
            gameWon = checkWin(board, currentPlayer);
            gameDraw = checkDraw(board);

            if (gameWon) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
            } else if (gameDraw) {
                displayBoard(board);
                cout << "The game is a draw!" << endl;
            } else {
                // Switch players
                currentPlayer = switchPlayer(currentPlayer);
            }
        }

        // Ask if the players want to play another game
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thank you for playing Tic-Tac-Toe. Goodbye!" << endl;

    return 0;
}
