#include <iostream>
#include "game.h"
#include <stdlib.h>
using namespace std;

GamePlay::GamePlay(){
    m_p1 = Player();
    m_p2 = Player();
    m_p1.setId(0);
    m_p2.setId(1);
    m_p1.setType('.');
    m_p2.setType('.');
    m_turns = 0;
}

GamePlay::~GamePlay(){
    //~Board();
}
///Returns the board
Board GamePlay::getBoard(){
    return m_board;
}

///Outputs the list of games available to play
void GamePlay::listOfGames(){
    for(unsigned int i = 0; i < sizeof(Game); ++i){
        if(i == 0)
            cout << "Nr. 1: Breakthrough" ;
        if(i == 1)
            cout << "Nr. 2: Ataxx";
        cout << endl;
    }
}

int GamePlay::getNoPieces(Player player)
{
    return player.getNoPawns();
}

///Quits the game play
void GamePlay::quit(){
    cout << "Are you sure you want to quit the game? (y/n)" << endl;
    char ans;
    cin >> ans;
    if(ans == 'y' || ans == 'Y')
        exit(0);
    else return;
}
