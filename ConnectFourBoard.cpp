//
// Created by User on 8/3/2019.
//

#include <iostream>
#include <iomanip>
#include "ConnectFourBoard.h"

void ConnectFourBoard::display() {
    int counter = 0;
    for (int j = 1; j <= COLUMNS; ++j) {
        std::cout << std::setw(3) << std::left << j;
    }
    std::cout << "\n";
    for (const auto &item : board) {
        if (counter % COLUMNS == 0 && counter != 0)
            std::cout << "\n";
        std::cout << std::setw(3) << std::left;

        if (item == BLACK) std::cout << 'B';
        else if (item == RED) std::cout << 'R';
        else std::cout << '-';

        counter++;
    }
    std::cout << std::endl;
}

bool ConnectFourBoard::isColumnFull(int column) {
    return board[column] != EMPTY;
}

bool ConnectFourBoard::insertPiece(PositionOccupant disc, int column) {
    int position = column;

    while (((position + COLUMNS) < TOTAL_SPOTS) &&      // Add to position until it reaches the bottom of the board or
           board.at(position + COLUMNS) == EMPTY)    // a spot that is already occupied
        position += COLUMNS;

    board.at(position) = disc; // Set the value at the position index to the disc value

    return true;
}

GameState ConnectFourBoard::checkGameState() {
    if (isBoardFull()) return DRAW;
    else
        for (int i = 0; i < TOTAL_SPOTS; ++i) {
            if (checkForWinner(i, VERTICAL)
                || checkForWinner(i, HORIZONTAL)
                || checkForWinner(i, DIAGONAL_UP)
                || checkForWinner(i, DIAGONAL_DOWN)) {
                return WIN;
            }
        }
    return IN_PROGRESS;
}

bool ConnectFourBoard::checkForWinner(int position, LinesToWin step) {
    int numOfColumnsUntilLastColumn = (COLUMNS - (position % COLUMNS));
    if (step != VERTICAL && numOfColumnsUntilLastColumn < 4) return false;
    // If there are less than 4 columns to the right, then it is impossible to get anything but a vertical win
    // NOTE: We need to do this check since it's a 1D array, or else, for example, you could have a horizontal win
    // when the discs are on different rows, but their indices in the array are next to each other

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
    return index < 0 || index >= TOTAL_SPOTS;
}

bool ConnectFourBoard::isBoardFull() {
    for (int i = 0; i < COLUMNS; ++i) {
        if (!isColumnFull(i)) return false;
    }
    return true;
}






