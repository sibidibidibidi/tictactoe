#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct TicTacToe {
    char board[3][3];
    char currentPlayer;
    bool isUserX;

    TicTacToe(bool userX) {
        isUserX = userX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = isUserX ? 'X' : 'O';
    }

    void printBoard() {
        cout << "\nboard:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " << board[i][j];
                if (j < 2) cout << " |";
            }
            cout << endl;
            if (i < 2) cout << "---|---|---\n";
        }
        cout << endl;
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                return true;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
                return true;
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
            return true;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
            return true;
        }
        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    bool makeMove(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            return true;
        }
        return false;
    }

    void switchPlayer() {
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        }
        else {
            currentPlayer = 'X';
        }
    }


    void userMove() {
        int row, col;
        bool validMove;
        while (!validMove) {
            cout << "Enter row (0-2) and column (0-2): ";
            cin >> row >> col;
            validMove = makeMove(row, col);
            if (!validMove) {
                cout << "Wrong symbol, try again:\n";
            }
        }
    }

    void computerMove() {
        int row, col;
        bool validMove;
        srand(time(0));
        while(!validMove) {
            row = rand() % 3;
            col = rand() % 3;
            validMove = makeMove(row, col);
        } 
        cout << "Computer chose: " << row << " " << col << endl;
    }
    
    void startGame() {
        while (true) {
            printBoard();
            if (currentPlayer == 'X' || (currentPlayer == 'O' && !isUserX)) {
                userMove();
            }
            else {
                computerMove();
            }

            if (checkWin()) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isBoardFull()) {
                printBoard();
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }
    }


};

int main() {
    char choice;
    cout << "Do you want to play as X or O? (X/O): ";
    cin >> choice;
    while (choice != 'X' && choice != 'O') {
        cout << "Wrong symbol, try again: ";
        cin >> choice;
    }
    TicTacToe game(choice == 'X');
    game.startGame();
    return 0;
}
