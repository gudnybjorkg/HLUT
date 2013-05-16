#ifndef ATAXX_H
#define ATAXX_H
#include "game.h"
#include <iostream>

class Ataxx : public GamePlay{
public:
    Ataxx();      //set up the board and the game for ataxx
    ~Ataxx(){}
    virtual bool legalMove(Piece p, std::pair<int, int> destination);
    virtual void make(int from_col, int from_row, int to_col, int to_row);
    virtual void go();
    virtual void start();
    virtual void retract(Player player);
    void convertPiece(int row, int col, Player p, Player opp);
    
    //yet to implement
    virtual void level(std::string difficulty){}
    virtual void debug(){}
    virtual int evaluate(Board board){ return 1; }
    virtual void display();
    virtual void legal(int row, int col){}
};

#endif // ATAXX_H
