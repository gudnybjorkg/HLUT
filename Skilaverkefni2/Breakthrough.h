#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H
#include "game.h"
#include <iostream>

class Breakthrough : GamePlay
{
    public:
        Breakthrough();
        virtual void start();
        virtual bool legalMove(Piece p, std::pair<int, int> destination);
        virtual void make(int from_col, int from_row, int to_col, int to_row);
        virtual int getNoPieces(Player player);
        virtual ~Breakthrough();
        virtual void go();
        virtual void retract(Player player);
        virtual void legal(Piece piece);
};

#endif // BREAKTHROUGH_H
