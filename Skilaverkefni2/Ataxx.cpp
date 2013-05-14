#include "Ataxx.h"


Ataxx::Ataxx()
{
    
}

 void Ataxx::start(){
     m_board = Board(7,7);  //board set up
     Piece p1('P');         //player 1 pawn set up
     Piece p2('p');         //player 2 pawn set up
     
     m_board.setPieceOnBoard(7, 0, p1); //pawn set in left bottom corner
     m_board.setPieceOnBoard(0, 7, p1); //pawn set in right top corner
     m_board.setPieceOnBoard(0, 0, p2); //left top corner
     m_board.setPieceOnBoard(7, 7, p2); //right bottom corner
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
    {
        if ((-1<=(from_col - to_col) && (from_col - to_col) <=1) && (-1<=(from_row - to_row) && (from_row - to_row)<=1)){ //moving 1 block which is legal so the player clones
            m_board.setPieceOnBoard(to_row, to_col, p);
        }
        else
        {
            m_board.setPieceOnBoard(to_row, to_col, p);
            m_board.setPieceOnBoard(from_row, from_col, empty);
        }
    }
}
