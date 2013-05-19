#ifndef ATAXX_H
#define ATAXX_H
#include "game.h"
#include <iostream>

class Ataxx : public GamePlay{
public:
    Ataxx();      //set up the board and the game for ataxx
    ~Ataxx(){}
    bool finalState();

    virtual void setLegalMoves();
    virtual bool legalMove(int from_row, int from_col, int to_row, int to_col);
    virtual void make(int from_row, int from_col, int to_row, int to_col);
    virtual void start();
    void convertPiece(int row, int col);
    virtual void display();
};

#endif // ATAXX_H
