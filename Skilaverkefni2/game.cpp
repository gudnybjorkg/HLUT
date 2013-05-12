#include <iostream>
#include "game.h"

using namespace std;

/*-------------------------------------------------------------

Implementation of the GamePlay class

---------------------------------------------------------------*/
Player::Player(int noPlayers){
    m_noPlayers = noPlayers;
    m_score = 0;
    //test2
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
}
GamePlay()::~GamePlay(){

}
