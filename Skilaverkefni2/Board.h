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
class Board
{
public:
    //Constructor
    Board() {}

    //Destructor
    ~Board();

    //Constructs a square board with a specific size of length and width.
    Board(int length, int width);

    ///Returns the board
    Piece** getBoard();

    ///Asignment operator
    Board& operator =(const Board& rhs)
    {
        if(this != &rhs)
        {
            m_length = rhs.m_length;
            m_width = rhs.m_width;;

            m_tiles = new Piece*[m_width];
            for(int k = 0; k < m_width; k++)
            {
                m_tiles[k] = new Piece[m_length];
            }

            for(int i = 0; i < m_width; ++i)
            {
                for(int j = 0; j < m_length; ++j)
                {
                    m_tiles[i][j] = rhs.m_tiles[i][j];
                }
            }
        }
        return *this;
    }

    ///Copy constructor
    Board(const Board& rhs) : m_length(rhs.m_length), m_width(rhs.m_width)
    {
        m_tiles = new Piece*[m_width];
        for(int k = 0; k < m_width; k++)
        {
            m_tiles[k] = new Piece[m_length];
        }

        for(int i = 0; i < m_width; ++i)
        {
            for(int j = 0; j < m_length; ++j)
                m_tiles[i][j] = rhs.m_tiles[i][j];
        }
    }

private:
    int m_length;
    int m_width;
    Piece **m_tiles;
};

#endif // BOARD_H
