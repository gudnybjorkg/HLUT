#include "Ataxx.h"


Ataxx::Ataxx()
{
    Piece p1('P');
    Piece p2('p');
    //m_board.setTile(7, 0, 'P');
    //m_board.setTile(0, 7, 'P');
    //m_board.setTile(0, 0, 'p');
    //m_board.setTile(7, 7, 'p');

    p1.setLocation(7, 0); //player 1 set in left bottom corner
    p1.setLocation(0, 7); //player 1 set in right top corner
    p2.setLocation(0, 0); //player 2 set in right bottom corner
    p2.setLocation(7, 7); //player 2 set in right bottom corner
}

bool Ataxx::legalMove(int from_col, int from_row, int to_col, int to_row)
{
    //checks if the move is 2 blocks away
    if ((-2<=(from_col - to_col) && (from_col - to_col) <=2) && (-2<=(from_row - to_row) && (from_row - to_row)<=2))
        return true;
    else
        return false;
}
