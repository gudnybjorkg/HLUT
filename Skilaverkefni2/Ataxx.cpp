#include "Ataxx.h"


Ataxx::Ataxx()
{
    
}

 void Ataxx::start(){
     m_board = Board(7,7);
     Piece p1('P');
     Piece p2('p');
     
     m_board.setPieceOnBoard(7, 0, p1); //pawn set in left bottom corner
     m_board.setPieceOnBoard(0, 7, p1);  //pawn set in right top corner
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
    else
        return false;
};
