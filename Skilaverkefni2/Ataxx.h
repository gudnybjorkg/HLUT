#ifndef ATAXX_H
#define ATAXX_H
#include "game.h"
#include <iostream>

class Ataxx : public GamePlay{
public:
    Ataxx();      ///constructor
    ~Ataxx(){}    ///destructor
    bool finalState();   ///checks whether the game is over

    virtual void setLegalMoves(); ///gets all the legal moves for the player playing
    virtual bool legalMove(int from_row, int from_col, int to_row, int to_col); ///checks whether the move is legal
    virtual void make(int from_row, int from_col, int to_row, int to_col); ///moves the pawn from row and col to a row and col
    virtual void start(); ///starts the game by setting up the board
    void convertPiece(int row, int col); ///convert one single piece on a specific tile on the board
    virtual void display(); ///displays the board for ataxx
};

#endif // ATAXX_H
