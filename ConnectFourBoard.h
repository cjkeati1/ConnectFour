#ifndef STL_CONNECTFOURBOARD_H
#define STL_CONNECTFOURBOARD_H

#include <array>
#include <map>

enum GameState {
    IN_PROGRESS,
    WIN,
    DRAW,
};

enum PositionOccupant {
    EMPTY,
    BLACK,
    RED
};

enum LinesToWin {
    VERTICAL,
    HORIZONTAL,
    DIAGONAL_UP,
    DIAGONAL_DOWN
};

class ConnectFourBoard {
private:
    std::array<PositionOccupant, 42> board{};
    std::map<LinesToWin, int> steps{
            {VERTICAL,      -7},
            {HORIZONTAL,    1},
            {DIAGONAL_UP,   -6},
            {DIAGONAL_DOWN, 6},
    };
public:
    const int COLUMNS = 7;
    const int ROWS = 6;
    const int TOTAL_SPOTS = COLUMNS * ROWS;

    ConnectFourBoard() {
        for (auto &item : board) {
            item = EMPTY;
        }
    };

    void display();

    bool isColumnFull(int column);

    bool insertPiece(PositionOccupant disc, int column);

    bool checkForWinner(int position, LinesToWin step);


    GameState checkGameState();

    bool isBoardFull();


    bool outOfRange(int index);
};


#endif //STL_CONNECTFOURBOARD_H
