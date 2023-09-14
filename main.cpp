#include <iostream>
#include <iomanip>

using namespace std;

int BOARD_SIZE = 3;

#include <iostream>
#include <iomanip>

using namespace std;

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


int main() {
    char** board = initializeBoard(BOARD_SIZE);

    drawBoard(board, BOARD_SIZE);

    // When the game is over or the program exits
    deallocateBoard(board, BOARD_SIZE);
    return 0;
}
