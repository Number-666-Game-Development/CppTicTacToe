#include <iostream>
#include <iomanip>

using namespace std;

#include <iostream>
#include <iomanip>

using namespace std;

bool isDraw(char** board, int size) {
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (board[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool checkWin(char** board, int size, char currentPlayer) {
    // Check rows and columns
    for (int i = 0; i < size; ++i) {
        // Check row i
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true; // Current player has won
        }

        // Check column i
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true; // Current player has won
        }
    }

    // Check main diagonal
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true; // Current player has won
    }

    // Check anti-diagonal
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true; // Current player has won
    }

    return false; // No win condition found
}

int getUserBoardSize() {
    int boardSize;
    cout << "What size board do you want to play? (0 to exit) ";
    cin >> boardSize;

    if (boardSize == 0) {
        exit(0);
    }

    return boardSize;
}

void drawBoard(char** board, int size) {
    cout << "  ";
    for (int col = 0; col < size; ++col) {
        cout << setw(2) << col + 1;
        if (col < size - 1) {
            cout << "  ";
        }
    }
    cout << endl;

    for (int row = 0; row < size; ++row) {
        cout << row + 1 << " ";
        for (int col = 0; col < size; ++col) {
            cout << setw(2) << board[row][col];
            if (col < size - 1) {
                cout << " |";
            }
        }
        cout << endl;

        if (row < size - 1) {
            cout << "  ";
            for (int col = 0; col < size; ++col) {
                cout << "---";
                if (col < size - 1) {
                    cout << "+";
                }
            }
            cout << endl;
        }
    }
}


char** initializeBoard(int size) {
    char** board = new char*[size]; // Create an array of pointers to char
    for (int row = 0; row < size; ++row) {
        board[row] = new char[size]; // Allocate heap memory for each row (array of char)
        for (int col = 0; col < size; ++col) {
            board[row][col] = ' '; // Initialize the value of each element to ' '
        }
    }
    return board;
}

void deallocateBoard(char** board, int size) {
    for (int row = 0; row < size; ++row) {
        delete[] board[row];
    }
    delete[] board;
}

bool isValidMove(char** board, int size, int row, int col) {
    if (row >= 1 && row <= size && col >=1 && col <= size) {
        if (board[row - 1][col - 1] == ' ') {
            return true;
        }
    }
    return false;
}


int main() {
    char** board;
    int boardSize;
    bool gameOver;
    char currentPlayer = 'X';

    do {
        boardSize = getUserBoardSize();
        board = initializeBoard(boardSize);
        gameOver = false;

        drawBoard(board, boardSize);
        do {
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (Row): ";
            cin >> row;
            cout << "Player " << currentPlayer << ", enter your move (Column): ";
            cin >> col;

            if (isValidMove(board, boardSize, row, col)) {
                board[row - 1][col - 1] = currentPlayer; // Assign player's move

                if (checkWin(board, boardSize, currentPlayer)) {
                    drawBoard(board, boardSize); // Display the final winning board
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameOver = true;
                } else if (isDraw(board, boardSize)) {
                    drawBoard(board, boardSize); // Display the final drawn board
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }

                drawBoard(board, boardSize);
            } else {
                cout << "Invalid move. Try again." << endl;
            }

        } while(!gameOver);

        // When the game is over or the program exits
        deallocateBoard(board, boardSize);

    } while (true);

    return 0;
}
