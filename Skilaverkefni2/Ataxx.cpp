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
    if ((-2<=(from_col - to_col) && (from_col - to_col) <=2) && (-2<=(from_row - to_row) && (from_row - to_row)<=2)){ //checks if the move is 2 blocks away
        if (m_board.getTiles()[to_row][to_col].getType() == '.') // if the tile is free
                {
                    return true;
                }
        }
    return false;
}

void Ataxx::make(int from_col, int from_row, int to_col, int to_row){
    Piece p = m_board.getPieceOnTile(from_row, from_col);
    Piece empty('.');
    if (legalMove(from_col, from_row, to_col, to_row))
        if ((-1<=(from_col - to_col) && (from_col - to_col) <=1) && (-1<=(from_row - to_row) && (from_row - to_row)<=1)) {//checks if the   move is 1 block away
            m_board.setPieceOnBoard(to_row, to_col, p); //no need to remove pawn since we are cloning
        else{
            m_board.setPieceOnBoard(to_row, to_col, p); //moves the piece for the player
            m_board.setPieceOnBoard(from_row, from_col, empty); //removes the old since we are not moving 1 piece
            }
        }
}