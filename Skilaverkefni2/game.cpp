#include <iostream>
#include "game.h"
#include <map>
using namespace std;


/*-------------------------------------------------------------

Implementation of the Board class

---------------------------------------------------------------*/
Board::Board(int length, int width){
    m_length = length;
    m_width = width;
    tiles = new Piece*[m_width];
    for(int i = 0; i < m_width; i++){
        tiles[i] = new Piece[m_length];
    }
    for(int j = 0; j < m_width; j++){
        for(int k = 0; k < m_length; k++){
            tiles[j][k] = Piece('.');
            tiles[j][k].setOwner(-1);
            tiles[j][k].setLocation(j,k);
        }
    }
}

void Board::setTile(int col, int row, char letter){
    tiles[col][row] = *new Piece(letter);
}
/*-------------------------------------------------------------

Implementation of the GamePlay class

---------------------------------------------------------------*/
GamePlay::GamePlay(){
    m_p1 = Player();
    m_p2 = Player();
    m_turns = 0;
    /*if(m_gametype == 0)    // not needed since we just use the corresponding game when the user picks
        m_board = Board(7,7);
    else if(m_gametype == 1)
        m_board = Board(8,8);
     */   
}
GamePlay::~GamePlay(){
}



/*-------------------------------------------------------------
 
 Implementation of the atixx gameplay class
 
 ---------------------------------------------------------------*/

Atixx::Atixx(){
    Piece p1('P');
    Piece p2('p');
    
    p1.setLocation(7, 0); //player 1 set in left bottom corner 
    p1.setLocation(0, 7); //player 1 set in right top corner
    p2.setLocation(0, 0); //player 2 set in right bottom corner
    p2.setLocation(7, 7); //player 2 set in right bottom corner
}

bool Atixx::legalMove(int from_col, int from_row, int to_col, int to_row)
{
    if ((-2<=(from_col - to_col)<=2) && (-2<=(from_row - to_row)<=2)) //checks if the move is 2 blocks away
    {
        return true;
    }
    else
        return false;
}

