#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H
#include "game.h"
#include <iostream>

class Breakthrough : public GamePlay
{
    public:
        Breakthrough();
        ~Breakthrough();
        void start();
        bool legalMove(Piece p, std::pair<int, int> destination);
        void make(int from_col, int from_row, int to_col, int to_row);
        void go();
        void retract(Player player);
        void legal(Piece piece);
        void display();

        void level(std::string difficulty){}
        void debug(){}
        int evaluate(Board board){ return 1; }
};

#endif // BREAKTHROUGH_H
