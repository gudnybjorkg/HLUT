#include "Breakthrough.h"

Breakthrough::Breakthrough()
{
    //ctor
}

bool Breakthrough::legalMove(Piece p, std::pair<int, int> destination)
{
    std::pair<int,int> currentLocation = p.getLocation;
    int localY = std::get<0>(currentLocation);
    int localX = std::get<1>(currentLocation);
    int destY = std::get<0>(destination);
    int destX = std::get<1>(destination);
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
             if((destx - localX) != 1)
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
             if((destx - localX) != 0)
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
             if((destx - localX) != 1)
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
             if((destx - localX) != 0)
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
