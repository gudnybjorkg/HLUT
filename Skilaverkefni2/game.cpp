#include <iostream>
#include "game.h"
#include <map>
using namespace std;

/*-------------------------------------------------------------

Implementation of the Player class

---------------------------------------------------------------*/
Player::Player(){
    m_score = 0;
}
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
/*-------------------------------------------------------------

Implementation of the GamePlay class

---------------------------------------------------------------*/
GamePlay::GamePlay(){
    m_p1 = Player();
    m_p2 = Player();
    m_turns = 0;
    if(m_gametype == 0)
        m_board = Board(7,7);
    else if(m_gametype == 1)
        m_board = Board(8,8);
}
GamePlay::~GamePlay(){
}


