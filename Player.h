#ifndef STL_PLAYER_H
#define STL_PLAYER_H

#include "ConnectFourBoard.h"

enum PlayerNumber {
    PLAYER_ONE,
    PLAYER_TWO
};

class Player {
private:
    PlayerNumber playerNumber;

    const int LOWEST_COLUMN_NUM = 1;
    const int HIGHEST_COLUMN_NUM = ConnectFourBoard::COLUMNS;
public:
    explicit Player(PlayerNumber playerNumber);

    [[nodiscard]] PlayerNumber getPlayerNumber() const;

    bool makeMove(ConnectFourBoard &board);

    void switchPlayer();

    int getValidInput();
};

#endif //STL_PLAYER_H