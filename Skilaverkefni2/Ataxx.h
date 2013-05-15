#ifndef ATAXX_H
#define ATAXX_H
#include "game.h"

class Ataxx : public GamePlay{
public:
    Ataxx();      //set up the board and the game for ataxx
    virtual bool legalMove(int from_col, int from_row, int to_col, int to_row);
    virtual void make(int from_col, int from_row, int to_col, int to_row);
private:
    Board m_board;
};

#endif // ATAXX_H
