#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>
#include <list>
#include <iomanip>
#include "ConnectFourBoard.h"
#include "Player.h"

int main() {
    ConnectFourBoard connectFourBoard;
    std::map<GameState, std::string> gameStateName{{IN_PROGRESS, "In Progress"},
                                                   {WIN,         "Win"},
                                                   {DRAW,        "Draw"}};
    connectFourBoard.display();

    Player playerOne{PLAYER_ONE};
    Player playerTwo{PLAYER_TWO};

    playerOne.makeMove(connectFourBoard);
    playerOne.makeMove(connectFourBoard);
    playerOne.makeMove(connectFourBoard);
    playerOne.makeMove(connectFourBoard);


    connectFourBoard.display();

    GameState gameState = connectFourBoard.checkGameState();
    std::cout << gameStateName[gameState] << std::endl;






    return 0;
}
