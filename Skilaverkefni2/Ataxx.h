#ifndef ATAXX_H
#define ATAXX_H
#include "game.h"
#include <iostream>

class Ataxx : public GamePlay{
public:
    Ataxx();      //set up the board and the game for ataxx
    ~Ataxx();
    virtual bool legalMove(Piece p, std::pair<int, int> destination);
    virtual void make(int from_col, int from_row, int to_col, int to_row);
    virtual void go();
    virtual void start();
    virtual void retract(Player player);
    void convertPiece(int row, int col, Player p, Player opp);
<<<<<<< HEAD

private:
    //Board m_board;
=======
    
    
    //yet to implement
    void level(std::string difficulty){}
    void debug(){}
    int evaluate(Board board){ return 1; }
    void display();
    void legal(Piece piece);
    
    
    
    
//public:
    //Breakthrough();
    //~Breakthrough();
    //void start();
    //bool legalMove(Piece p, std::pair<int, int> destination);
    //void make(int from_col, int from_row, int to_col, int to_row);
    //void go();
    //void retract(Player player);
    //void legal(Piece piece);
    //oid display();
    
    //void level(std::string difficulty){}
    //void debug(){}
    //int evaluate(Board board){ return 1; }
>>>>>>> 3622af32958330fb68454f2aa384c186d50c87c4
};

#endif // ATAXX_H
