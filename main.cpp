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
#include <unordered_map>
#include "ConnectFourBoard.h"
#include "Player.h"

int main() {
    std::unordered_map<PlayerNumber, std::string> titles{{PLAYER_ONE, "Player One (Black)"},
                                                         {PLAYER_TWO, "Player Two (Red)"}};
    ConnectFourBoard connectFourBoard;
    GameState gameState;

    Player currentPlayer{PLAYER_ONE};

    connectFourBoard.display();
    do {
        currentPlayer.makeMove(connectFourBoard);
        connectFourBoard.display();

        gameState = connectFourBoard.checkGameState();

        currentPlayer.switchPlayer();
    } while (gameState == IN_PROGRESS);

    currentPlayer.switchPlayer(); // Switch back to the player that won
    if (gameState == WIN) {
        std::cout << titles[currentPlayer.getPlayerNumber()] << " has won!";
    } else {
        std::cout << "It's a draw!";
    }

    return 0;
}
