#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include "Player.h"
/*---------------------------------------------------------------------------

A class representing a piece on a board game to be played and strategized
by the player.

---------------------------------------------------------------------------*/
class Piece
{
public:
    ///Constructor
    Piece();

    ///Constructor, initializing the type of the piece
    Piece(char type);

    ///Set function for the owner of the piece
    void setOwner(Player owner);

    ///Returns the owner of the piece
    Player getOwner();

    ///Returns the type of the piece
    char getType();

    ///Sets the type
    void setType(char type);

    ///Returns the location of the piece as a pair of coordinates, Example <0,1> represents the row 0 and column 1 on the board.
    std::pair<int,int> getLocation();

    ///Anitializes the location of the piece
    void setLocation(int x, int y);

    ///Asignment operator
    Piece& operator =(const Piece& rhs)
    {
        if(this != &rhs)
        {
            m_type = rhs.m_type;
            m_owner = rhs.m_owner;
            m_location.first = rhs.m_location.first;
            m_location.second = rhs.m_location.second;
        }
        return *this;
    }

    ///Copy constructor
    Piece(const Piece& rhs)
    {
        m_type = rhs.m_type;
        m_owner = rhs.m_owner;

        m_location.first = rhs.m_location.first;
        m_location.second = rhs.m_location.second;

    }

private:
    char m_type;
    Player m_owner;
    std::pair<int,int> m_location;
};

#endif // PIECE_H
