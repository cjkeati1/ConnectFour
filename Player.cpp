//
// Created by User on 8/3/2019.
//

#include <iostream>
#include "Player.h"

Player::Player(PlayerNumber playerNumber) : playerNumber(playerNumber) {}

PlayerNumber Player::getPlayerNumber() const {
    return playerNumber;
}

bool Player::makeMove(ConnectFourBoard &board) {
    int column;
    std::cout << "Enter the column: \n";
    std::cin >> column;
    column -= 1;

    if (board.isColumnFull(column)) {
        std::cout << "That column is full.\n";
        return false;
    }
    PositionOccupant disc = getPlayerNumber() == PLAYER_ONE ? BLACK : RED;
    board.insertPiece(disc, column);
    return true;
}


