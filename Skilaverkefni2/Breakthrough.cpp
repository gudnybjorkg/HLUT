#include "Breakthrough.h"
<<<<<<< HEAD
#include <utility>
#include <algorithm>
using namespace std;

Breakthrough::Breakthrough() : GamePlay(){
    m_board = Board(8,8);
}
void Breakthrough::make(int from_col, int from_row, int to_col, int to_row){
    int owner = m_board.getBoard()[from_row][from_col].getOwner();
    char value = m_board.getBoard()[from_row][from_col].getType();
    m_board.getBoard()[from_row][from_col].setOwner(-1);
    m_board.getBoard()[from_row][from_col] = '.';
    m_board.getBoard()[to_row][to_col].setOwner(owner);
    m_board.getBoard()[to_row][to_col] = value;
}
void Breakthrough::start(){
    for(int i = 0; i < 8; ++i){
        //Player 1
        m_board.getBoard()[0][i].setOwner(0);
        m_board.getBoard()[0][i] = 'p';
        m_board.getBoard()[1][i].setOwner(0);
        m_board.getBoard()[1][i] = 'p';
        //Player 2
        m_board.getBoard()[6][i].setOwner(1);
        m_board.getBoard()[6][i] = 'P';
        m_board.getBoard()[7][i].setOwner(1);
        m_board.getBoard()[7][i] = 'P';
    }
=======
#include <iostream>
#include <utility>
#include <tuple>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <set>
#include <list>
#include <algorithm>
#include <map>




Breakthrough::Breakthrough() : GamePlay()
{
    //ctor
>>>>>>> 25de843d02efc057d91b97c1f738130e6b3bfb59
}

bool Breakthrough::legalMove(Piece p, pair<int, int> destination){
    pair<int,int> currentLocation = p.getLocation(p);
    int localY = currentLocation.first;//get<0>(currentLocation);
    int localX = currentLocation.second;//get<1>(currentLocation);
    int destY = destination.first;//get<0>(destination);
    int destX = destination.second;//get<1>(destination);
    Piece** the_pieces = m_board.getBoard();
    Piece destPiece = the_pieces[destY][destX];

    if(p.getOwner() == 0)
    {
        if((destY - localY) != 1)
        {
            return false;
        }

        if(destX < localX)
        {
             if((localX - destX) != 1)
             {
                 return false;
             }
             if(destPiece.getOwner() == p.getOwner())
             {
                 return false;
             }
             return true;
        }
        else if(destX > localX)
        {
             if((destX - localX) != 1)
             {
                 return false;
             }
             if(destPiece.getOwner() == p.getOwner())
             {
                 return false;
             }
             return true;
        }
        else
        {
             if((destX - localX) != 0)
             {
                 return false;
             }
               if(destPiece.getType() != '.')
             {
                 return false;
             }
             return true;
        }


    }
    else if(p.getOwner() == 1)
    {
        if((localY - destY) != 1)
        {
            return false;
        }

        if(destX < localX)
        {
             if((localX - destX) != 1)
             {
                 return false;
             }
             if(destPiece.getOwner() == p.getOwner())
             {
                 return false;
             }
             return true;
        }
        else if(destX > localX)
        {
             if((destX - localX) != 1)
             {
                 return false;
             }
             if(destPiece.getOwner() == p.getOwner())
             {
                 return false;
             }
             return true;
        }
        else
        {
             if((destX - localX) != 0)
             {
                 return false;
             }
               if(destPiece.getType() != '.')
             {
                 return false;
             }
             return true;
        }


    }
    return false;
}

Breakthrough::~Breakthrough()
{
    //dtor
}
