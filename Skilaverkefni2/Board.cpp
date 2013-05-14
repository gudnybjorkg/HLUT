#include "Board.h"

Board::~Board(){
    for(int i = 0; i < m_width; i++)
        delete [] m_tiles[i];
    delete [] m_tiles;
}

Board::Board(int length, int width){
    m_length = length;
    m_width = width;
    m_tiles = new Piece*[m_width];
    //Creating the board
    for(int i = 0; i < m_width; i++){
        m_tiles[i] = new Piece[m_length];
    }
    //Publicating the board with default setup og pieces
    for(int j = 0; j < m_width; j++){
        for(int k = 0; k < m_length; k++){
            m_tiles[j][k] = Piece('.');
            m_tiles[j][k].setOwner(-1);
            m_tiles[j][k].setLocation(j,k);
        }
    }
}

Piece** Board::getTiles(){
        return m_tiles;
}
<<<<<<< HEAD
int Board::getWidth(){
    return m_width;
}
=======

Piece Board::getPieceOnTile(int row, int col){
    return m_tiles[row][col];
}

void Board::setPieceOnBoard(int row, int col, Piece piece)
{
    m_tiles[row][col].setType(piece.getType());
    m_tiles[row][col].setOwner(piece.getOwner());
    m_tiles[row][col].setLocation(col, row);
}
>>>>>>> 4083c5d7ce489326651027d0a404f9c41184a65d
