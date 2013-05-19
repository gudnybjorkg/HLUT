#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H
#include "game.h"
#include <iostream>

class Breakthrough : public GamePlay
{
    public:
        Breakthrough();
        ~Breakthrough();
        //returns the id of the player that won, -1 otherwise
        int finalState();

        virtual void setLegalMoves();
        virtual void start();
        virtual bool legalMove(int from_row, int from_col, int to_row, int to_col);
        virtual void make(int from_row, int from_col, int to_row, int to_col);
        virtual void display();

        virtual void debug(){}
};

#endif // BREAKTHROUGH_H
