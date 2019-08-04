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
public:
    static const int COLUMNS = 7;
    static const int ROWS = 6;
    static const int TOTAL_SPOTS = COLUMNS * ROWS;

private:
    std::array<PositionOccupant, TOTAL_SPOTS> board{};
    std::map<LinesToWin, int> steps{
            {VERTICAL,      -COLUMNS},
            {HORIZONTAL,    1},
            {DIAGONAL_UP,   -(COLUMNS - 1)},
            {DIAGONAL_DOWN, COLUMNS + 1},
    };
public:
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

    static bool outOfRange(int index);
};

#endif //STL_CONNECTFOURBOARD_H