#include <iostream>
#include <sstream>
#include "Player.h"

Player::Player(PlayerNumber playerNumber) : playerNumber(playerNumber) {}

PlayerNumber Player::getPlayerNumber() const {
    return playerNumber;
}

bool Player::makeMove(ConnectFourBoard &board) {
    int column;
    bool isColumnFull;
    do {
        column = getValidInput();

        isColumnFull = board.isColumnFull(column);
        if (isColumnFull) {
            std::cerr << "Column " << column << " is full. Try again." << std::endl;
        }
    } while (board.isColumnFull(column));

    PositionOccupant disc = playerNumber == PLAYER_ONE ? BLACK : RED;
    board.insertPiece(disc, column);
    return true;
}

void Player::switchPlayer() {
    this->playerNumber = this->playerNumber == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;
}

int Player::getValidInput() {
    int column;
    std::string input{};
    bool isValidInput;

    do {
        std::cout << "Enter the column number [" << (getPlayerNumber() == PLAYER_ONE ? "P1 (B)" : "P2 (R)") << "]:\n";
        std::cin >> input;

        std::stringstream ss{input};
        if (ss >> column)
            if (column < LOWEST_COLUMN_NUM || column > HIGHEST_COLUMN_NUM) {
                std::cerr << "ERROR: Enter an integer from " << LOWEST_COLUMN_NUM << '-' << HIGHEST_COLUMN_NUM
                          << std::endl;
                isValidInput = false;
            } else {
                column -= 1; // Array is 0 indexed
                isValidInput = true;
            }
        else {
            std::cerr << "ERROR: You did not enter an integer. Try again." << std::endl;
            isValidInput = false;
        }
    } while (!isValidInput);

    return column;
}
