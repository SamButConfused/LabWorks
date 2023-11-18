#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 4;
const int COLS = 4;
const int BLANK_TILE = 16;
const int NUM_MOVES = 4;
const int ROW_MOVES[NUM_MOVES] = {0, 0, -1, 1};
const int COL_MOVES[NUM_MOVES] = {-1, 1, 0, 0};

void initBoard(int board[][COLS]);
void printBoard(int board[][COLS]);
void shuffleBoard(int board[][COLS]);
void getMove(int& rowMove, int& colMove);
bool makeMove(int board[][COLS], int rowMove, int colMove);
bool isSolved(int board[][COLS]);

int main() {
    int board[ROWS][COLS];
    int rowMove, colMove;

    srand(time(NULL));
    initBoard(board);
    shuffleBoard(board);
    printBoard(board);

    while (!isSolved(board)) {
        getMove(rowMove, colMove);
        if (!makeMove(board, rowMove, colMove)) {
            cout << " Unexpected movement,Please try again! " << endl;
        }
        else {
            printBoard(board);
        }
    }

    cout << "Congratulations!!!" << endl;
    return 0;
}

void initBoard(int board[][COLS]) {
    int count = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = count;
            count++;
        }
    }
    board[ROWS-1][COLS-1] = BLANK_TILE;
}

void printBoard(int board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == BLANK_TILE) {
                cout << "   ";
            }
            else {
                cout << board[i][j] << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void shuffleBoard(int board[][COLS]) {
    int rowBlank = ROWS-1;
    int colBlank = COLS-1;
    int rowMove, colMove;
    for (int i = 0; i < 1000; i++) {
        do {
            int moveIndex = rand() % NUM_MOVES;
            rowMove = ROW_MOVES[moveIndex];
            colMove = COL_MOVES[moveIndex];
        } while ((rowBlank+rowMove < 0) || (rowBlank+rowMove >= ROWS) ||
                 (colBlank+colMove < 0) || (colBlank+colMove >= COLS));
        swap(board[rowBlank][colBlank], board[rowBlank+rowMove][colBlank+colMove]);
        rowBlank += rowMove;
        colBlank += colMove;
    }
}

void getMove(int& rowMove, int& colMove) {
    char direction;
    cout << "Enter direction (U=up, D=down, L=left, D=right): ";
    cin >> direction;
    switch (direction) {
        case 'U':
        case 'u':
            rowMove = -1;
            colMove = 0;
            break;
        case 'D':
        case 'd':
            rowMove =1;
colMove = 0;
break;
case 'L':
case 'l':
rowMove = 0;
colMove = -1;
break;
case 'R':
case 'r':
rowMove = 0;
colMove = 1;
break;
default:
cout << "Invalid direction." << endl;
rowMove = 0;
colMove = 0;
break;
}
}

bool makeMove(int board[][COLS], int rowMove, int colMove) {
int rowBlank, colBlank;
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
if (board[i][j] == BLANK_TILE) {
rowBlank = i;
colBlank = j;
}
}
}
int newRow = rowBlank + rowMove;
int newCol = colBlank + colMove;
if ((newRow < 0) || (newRow >= ROWS) || (newCol < 0) || (newCol >= COLS)) {
return false;
}
swap(board[rowBlank][colBlank], board[newRow][newCol]);
return true;
}

bool isSolved(int board[][COLS]) {
int count = 1;
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
if ((i == ROWS-1) && (j == COLS-1)) {
if (board[i][j] != BLANK_TILE) {
return false;
}
}
else {
if (board[i][j] != count) {
return false;
}
count++;
}
}
}
return true;
}