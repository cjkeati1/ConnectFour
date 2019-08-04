#ifndef STL_PLAYER_H
#define STL_PLAYER_H

#include "ConnectFourBoard.h"

enum PlayerNumber{
    PLAYER_ONE,
    PLAYER_TWO
};

class Player {
public:
    PlayerNumber playerNumber;
public:
    explicit Player(PlayerNumber playerNumber);

    [[nodiscard]] PlayerNumber getPlayerNumber() const;

    bool makeMove(ConnectFourBoard &board);




};


#endif //STL_PLAYER_H
