#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
void initializeBoard(vector<vector<char> > &board);
void displayBoard(const vector<vector<char> > &board);
bool makeMove(vector<vector<char> > &board, int row, int col, char player);
bool checkWin(const vector<vector<char> > &board, char player);
bool checkDraw(const vector<vector<char> > &board);
void switchPlayer(char &currentPlayer);

int main() {
    vector<vector<char> > board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameOver = false;

    initializeBoard(board);

    do {
        int row, col;
        displayBoard(board);
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (1-3): ";
        cin >> row >> col;
        row--; // Adjusting row and col to match 0-based index
        col--;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        if (!makeMove(board, row, col, currentPlayer)) {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            gameOver = true;
        } else {
            switchPlayer(currentPlayer);
        }

    } while (!gameOver);

    return 0;
}

void initializeBoard(vector<vector<char> > &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char> > &board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool makeMove(vector<vector<char> > &board, int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool checkWin(const vector<vector<char> > &board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Columns
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Main diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Anti-diagonal

    return false;
}

bool checkDraw(const vector<vector<char> > &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

