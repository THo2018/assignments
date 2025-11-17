#include <iostream>
using namespace std;

/*
    The TicTacToe class represents a complete Tic-Tac-Toe game.
    It manages:
      - Game board (3x3)
      - Player turns
      - Move validation
      - Win and draw detection
      - Full gameplay loop
*/

class TicTacToe {
private:
    char board[3][3];      // stores 'X', 'O', or ' '
    char currentPlayer;    // player whose turn it is
    int moveCount;         // counts total moves made

public:
    // Constructor initializes the board and sets starting player to X
    TicTacToe() {
        resetBoard();
    }

    // Resets the game board and variables for replay
    void resetBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
        moveCount = 0;
    }

    // Displays the current game board
    void displayBoard() {
        cout << "\n   1   2   3\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << "  ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "  ---+---+---\n";
        }
        cout << endl;
    }

    // Checks whether a move is valid
    bool isValidMove(int row, int col) {
        if (row < 0 || row > 2 || col < 0 || col > 2)
            return false;
        return board[row][col] == ' ';
    }

    // Places the player's marker on the board
    void makeMove(int row, int col) {
        board[row][col] = currentPlayer;
        moveCount++;
    }

    // Switches active player from X to O or O to X
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Checks all possible winning combinations
    bool checkWinner() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer &&
                board[i][1] == currentPlayer &&
                board[i][2] == currentPlayer)
                return true;
        }

        for (int i = 0; i < 3; i++) {
            if (board[0][i] == currentPlayer &&
                board[1][i] == currentPlayer &&
                board[2][i] == currentPlayer)
                return true;
        }

        if (board[0][0] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][2] == currentPlayer)
            return true;

        if (board[0][2] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][0] == currentPlayer)
            return true;

        return false;
    }

    // Returns true if the game is a draw (all spaces used)
    bool isDraw() {
        return moveCount == 9;
    }

    // Runs the full game loop until win or draw
    void playGame() {
        displayBoard();

        while (true) {
            int row, col;
            cout << "Player " << currentPlayer << "'s turn.\n";

            while (true) {
                cout << "Enter row (1-3): ";
                cin >> row;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input! Please enter a number.\n";
                    continue;
                }

                cout << "Enter column (1-3): ";
                cin >> col;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input! Please enter a number.\n";
                    continue;
                }

                row--;
                col--;

                if (!isValidMove(row, col)) {
                    cout << "Invalid move! Choose an empty spot.\n";
                } else {
                    break;
                }
            }

            makeMove(row, col);
            displayBoard();

            if (checkWinner()) {
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isDraw()) {
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    char playAgain;

    do {
        game.resetBoard();
        cout << "=== Tic-Tac-Toe ===\n";
        game.playGame();

        cout << "Play again? (y/n): ";
        cin >> playAgain;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter y or n: ";
            cin >> playAgain;
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
