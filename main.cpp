#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class TicTacToe {
private:
    std::vector<char> board;
    char humanPlayer;
    char botPlayer;

public:
    TicTacToe() : board(9, ' '), humanPlayer('X'), botPlayer('O') {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }

    void displayBoard() const {
        std::cout << "\n";
        std::cout << " " << (board[0] == ' ' ? '1' : board[0]) << " | " 
                  << (board[1] == ' ' ? '2' : board[1]) << " | " 
                  << (board[2] == ' ' ? '3' : board[2]) << " \n";
        std::cout << "---+---+---\n";
        std::cout << " " << (board[3] == ' ' ? '4' : board[3]) << " | " 
                  << (board[4] == ' ' ? '5' : board[4]) << " | " 
                  << (board[5] == ' ' ? '6' : board[5]) << " \n";
        std::cout << "---+---+---\n";
        std::cout << " " << (board[6] == ' ' ? '7' : board[6]) << " | " 
                  << (board[7] == ' ' ? '8' : board[7]) << " | " 
                  << (board[8] == ' ' ? '9' : board[8]) << " \n\n";
    }

    bool isWinner(char player) const {
        const int wins[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
            {0, 4, 8}, {2, 4, 6}             // Diagonals
        };
        for (const auto& w : wins) {
            if (board[w[0]] == player && board[w[1]] == player && board[w[2]] == player) {
                return true;
            }
        }
        return false;
    }

    bool isBoardFull() const {
        for (char c : board) {
            if (c == ' ') return false;
        }
        return true;
    }

    bool makeMove(int position, char player) {
        if (position < 1 || position > 9 || board[position - 1] != ' ') {
            return false;
        }
        board[position - 1] = player;
        return true;
    }

    void botMove() {
        std::vector<int> available;
        for (int i = 0; i < 9; ++i) {
            if (board[i] == ' ') available.push_back(i + 1);
        }
        if (!available.empty()) {
            int choice = available[std::rand() % available.size()];
            makeMove(choice, botPlayer);
            std::cout << "Bot picked square " << choice << ".\n";
        }
    }

    void play() {
        std::cout << "=================================\n";
        std::cout << "       Welcome to Tic-Tac-Toe    \n";
        std::cout << "=================================\n";
        std::cout << "Instructions:\n";
        std::cout << "- The grid has 9 squares numbered 1 through 9.\n";
        std::cout << "- You play as X, Bot plays as O.\n";
        std::cout << "- Get three in a row, column, or diagonal to win!\n";

        displayBoard();

        while (true) {
            int move = 0;
            std::cout << "Your turn (X). Enter square (1-9): ";
            while (!(std::cin >> move) || !makeMove(move, humanPlayer)) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid move! Please enter an open square (1-9): ";
            }

            displayBoard();
            if (isWinner(humanPlayer)) {
                std::cout << "🎉 Congratulations! You WON!\n";
                break;
            }
            if (isBoardFull()) {
                std::cout << "🤝 It's a draw!\n";
                break;
            }

            std::cout << "Bot is thinking...\n";
            botMove();
            displayBoard();
            if (isWinner(botPlayer)) {
                std::cout << "🤖 Bot wins! Better luck next time.\n";
                break;
            }
            if (isBoardFull()) {
                std::cout << "🤝 It's a draw!\n";
                break;
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
