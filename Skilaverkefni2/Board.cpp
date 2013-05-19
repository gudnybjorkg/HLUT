#include "Board.h"
using namespace std;

///Destructor for the board
Board::~Board(){
    for(int i = 0; i < m_width; i++)
        delete [] m_tiles[i];
    delete [] m_tiles;
}

///Constructor for the board
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

///Returns the tiles on the board
Piece** Board::getBoard(){
    return m_tiles;
}
