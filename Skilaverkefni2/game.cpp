#include <iostream>
#include "game.h"

using namespace std;

/*-------------------------------------------------------------

Implementation of the GamePlay class

---------------------------------------------------------------*/
Player::Player(){
    m_score = 0;
}
/*-------------------------------------------------------------

Implementation of the GamePlay class

---------------------------------------------------------------*/
Board::Board(int length, int width){
    m_length = length;
    m_width = width;
    tiles = new int*[m_width-1];
    for(int i = 0; i < m_width; i++)
        tiles[i] = new int[m_length-1];
}
/*-------------------------------------------------------------

Implementation of the GamePlay class

---------------------------------------------------------------*/
GamePlay::GamePlay(int gametype){
    m_gametype = gametype;
    p1 = new Player();
    p2 = new Player();
    if(m_gametype == 0)
        m_board = new Board(7,7);
    else if(m_gametype == 1)
        m_board = new Board(8,8);
}
GamePlay()::~GamePlay(){

}
