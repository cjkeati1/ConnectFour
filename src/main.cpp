#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <iomanip>
#include <unordered_map>
#include "ConnectFourBoard.h"
#include "Player.h"

int main() {
    std::unordered_map<PlayerNumber, std::string> titles{std::make_pair(PLAYER_ONE, "Player One (Black)"),
                                                         std::make_pair(PLAYER_TWO, "Player Two (Red)")};
    ConnectFourBoard connectFourBoard;
    GameState gameState;
    Player currentPlayer{PLAYER_ONE};

    std::cout << "===== Connect Four =====\n\n";
    connectFourBoard.display();
    do {
        currentPlayer.makeMove(connectFourBoard);
        connectFourBoard.display();

        gameState = connectFourBoard.checkGameState(); // Get updated game state

        currentPlayer.switchPlayer(); // switch player
    } while (gameState == IN_PROGRESS);

    currentPlayer.switchPlayer(); // Switch back to the player that won
    if (gameState == WIN) {
        std::cout << titles[currentPlayer.getPlayerNumber()] << " has won!";
    } else {
        std::cout << "It's a draw!";
    }
    return 0;
}
