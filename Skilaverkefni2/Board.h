#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "Piece.h"
/*---------------------------------------------------------------------------


A class representing the boad of size length x whidth. Each tile on the
board holds a pawn that is to be moved around.

Constructs a square board with a specific size of length and width.

           L  e  n  g  t  h
        W  |  |  |  |  |  |
        i  |  |  |  |  |  |
        d  |  |  |  |  |  |
        t  |  |  |  |  |  |
        h  |  |  |  |  |  |

---------------------------------------------------------------------------*/
class Board{
public:
    //Constructor
    Board(){}

    //Destructor
    ~Board();

    //Constructs a square board with a specific size of length and width.
    Board(int length, int width);

<<<<<<< HEAD
    //Returns the board
    Piece** getTiles();
    int getWidth();
=======
    //Returns the tiles
    Piece** getTiles();
    
    Piece getPieceOnTile(int row, int col);
    
    void setPieceOnBoard(int row, int col, Piece piece);

>>>>>>> 4083c5d7ce489326651027d0a404f9c41184a65d
private:
    int m_length;
    int m_width;
    Piece **m_tiles;
};

#endif // BOARD_H
