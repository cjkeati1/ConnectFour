//
// Created by User on 8/3/2019.
//

#include <iostream>
#include <iomanip>
#include "ConnectFourBoard.h"

void ConnectFourBoard::display() {

    int counter = 0;
    for (int j = 1; j <= 7; ++j) {
        std::cout << std::setw(3) << std::left << j;
    }
    std::cout << "\n";
    for (const auto &item : board) {
        if (counter % 7 == 0 && counter != 0)
            std::cout << "\n";
        std::cout << std::setw(3) << std::left;

        if (item == BLACK) std::cout << 'B';
        else if (item == RED) std::cout << 'R';
        else std::cout << 0;

        counter++;
    }
    std::cout << std::endl;
}

bool ConnectFourBoard::isColumnFull(int column) {
    return board[column] != EMPTY;
}

bool ConnectFourBoard::insertPiece(PositionOccupant disc, int column) {
    int position = column;

    while (((position + COLUMNS) <= (TOTAL_SPOTS - 1)) && board.at(position + COLUMNS) == EMPTY)
        position += COLUMNS;

    board.at(position) = disc;

    return true;
}

GameState ConnectFourBoard::checkGameState() {
    if (isBoardFull()) return DRAW;
    else
        for (int i = 0; i < TOTAL_SPOTS; ++i) {
            if (checkForWinner(i, VERTICAL) // Vertical
                || checkForWinner(i, HORIZONTAL) // Horizontal
                || checkForWinner(i, DIAGONAL_UP) // Diagonal Up
                || checkForWinner(i, DIAGONAL_DOWN))  // Diagonal Down
            {
                return WIN;
            }
        }
    return IN_PROGRESS;
}

bool ConnectFourBoard::checkForWinner(int position, LinesToWin step) {
    for (int i = 0; i < 3; ++i) {
        int nextPositionToCheck = position + steps[step]; // Each line direction has its own unique step
        if (outOfRange(nextPositionToCheck) || board.at(position) != board.at(nextPositionToCheck) ||
            board.at(position) == EMPTY)
            return false;
        position = nextPositionToCheck;
    }
    return true;
}

bool ConnectFourBoard::outOfRange(int index) {
    return index < 0 || index > (TOTAL_SPOTS - 1);
}

bool ConnectFourBoard::isBoardFull() {
    for (int i = 0; i < 6; ++i) {
        if (!isColumnFull(i)) return false;
    }

    return true;
}






