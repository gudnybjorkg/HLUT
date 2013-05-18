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

        void start();
        bool legalMove(int from_row, int from_col, std::pair<int, int> destination);
        void make(int from_row, int from_col, int to_row, int to_col);
        void go();
        void legal();
        void display();

        void level(std::string difficulty){}
        void debug(){}
};

#endif // BREAKTHROUGH_H
