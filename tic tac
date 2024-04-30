#include <iostream>
#include <vector>
#include <limits>
 
using namespace std;
 
const int SIZE = 3;
const char EMPTY = ' ';
const char HUMAN = 'X';
const char AI = 'O';
 
// Function to print the Tic Tac Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl << "---------" << endl;
    }
}
 
// Function to check if the game is over
bool gameOver(const vector<vector<char>>& board) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true; // Row i
        }
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true; // Column i
        }
    }
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true; // Diagonal top-left to bottom-right
    }
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true; // Diagonal top-right to bottom-left
    }
    // Check if board is full
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == EMPTY) {
                return false;
            }
        }
    }
    return true;
}
 
// Function to evaluate the current board state
int evaluateBoard(const vector<vector<char>>& board) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == AI) ? 10 : -10; // Row i
        }
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == AI) ? 10 : -10; // Column i
        }
    }
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == AI) ? 10 : -10; // Diagonal top-left to bottom-right
    }
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == AI) ? 10 : -10; // Diagonal top-right to bottom-left
    }
    return 0; // No winner
}
 
// Minimax algorithm with alpha-beta pruning
int minimax(vector<vector<char>>& board, int depth, bool isMaximizer, int alpha, int beta) {
    if (gameOver(board)) {
        return evaluateBoard(board);
    }
 
    if (isMaximizer) {
        int bestScore = numeric_limits<int>::min();
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = AI;
                    bestScore = max(bestScore, minimax(board, depth + 1, !isMaximizer, alpha, beta));
                    alpha = max(alpha, bestScore);
                    board[i][j] = EMPTY;
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = numeric_limits<int>::max();
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = HUMAN;
                    bestScore = min(bestScore, minimax(board, depth + 1, !isMaximizer, alpha, beta));
                    beta = min(beta, bestScore);
                    board[i][j] = EMPTY;
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return bestScore;
    }
}
 
// Function for computer's move
pair<int, int> computerMove(vector<vector<char>>& board) {
    int bestScore = numeric_limits<int>::min();
    pair<int, int> move;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                board[i][j] = AI;
                int score = minimax(board, 0, false, numeric_limits<int>::min(), numeric_limits<int>::max());
                board[i][j] = EMPTY;
                if (score > bestScore) {
                    bestScore = score;
                    move = make_pair(i, j);
                }
            }
        }
    }
    return move;
}
 
int main() {
    vector<vector<char>> board(SIZE, vector<char>(SIZE, EMPTY)); // Initialize empty board
 
    bool playerTurn = true; // Player starts first
 
    while (!gameOver(board)) {
        if (playerTurn) {
            printBoard(board);
            int row, col;
            cout << "Enter your move (row col): ";
            cin >> row >> col;
            if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
                board[row][col] = HUMAN;
                playerTurn = false;
            } else {
                cout << "Invalid move! Try again." << endl;
            }
        } else {
            pair<int, int> move = computerMove(board);
            board[move.first][move.second] = AI;
            playerTurn = true;
        }
    }
 
    printBoard(board);
 
    if (evaluateBoard(board) == 10) {
        cout << "AI wins!" << endl;
    } else if (evaluateBoard(board) == -10) {
        cout << "You win!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
 
    return 0;
}
