#ifndef PIECE_H
#define PIECE_H
#include <iostream>
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
    void setOwner(int owner);

    ///Returns the owner of the piece
    int getOwner();

    ///Returns the location of the piece as a pair of coordinates, Example <0,1> represents the row 0 and column 1 on the board.
    std::pair<int,int> getLocation(Piece piece);

    ///Anitializes the location of the piece
    void setLocation(int x, int y);

    ///Destructor
    virtual ~Piece();

private:
    char m_type;
    int m_owner;
    std::pair<int,int> m_location;
};

#endif // PIECE_H
