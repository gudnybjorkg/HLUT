#include "Board.h"
using namespace std;

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
    for(int j = 0; j < m_length; j++){
        for(int k = 0; k < m_length; k++){
            m_tiles[j][k] = Piece();
            m_tiles[j][k].setOwner(Player());
            m_tiles[j][k].setLocation(j,k);
        }
    }
}

void Board::setPieceOnBoard(int col, int row, Piece piece)
{
    m_tiles[col][row].setType(piece.getType());
    m_tiles[col][row].setOwner(piece.getOwner());
    m_tiles[col][row].setLocation(col, row);
}

Piece** Board::getBoard(){
    return m_tiles;
}
