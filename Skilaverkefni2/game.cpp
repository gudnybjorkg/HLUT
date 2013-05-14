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

void Player::setDifficulty(std::string difficulty){
    m_difficulty = difficulty;
}

Player::~Player(){}

/*-------------------------------------------------------------

Implementation of the Piece class

---------------------------------------------------------------*/
Piece::Piece(){
    m_type = '.';
    m_owner = -1;
}

Piece::Piece(char type){
    m_type = type;
}

void Piece::setOwner(int owner){
    m_owner = owner;
}

int Piece::getOwner(){
    return 1;
}

std::pair<int, int> Piece::getLocation(Piece piece){
    return piece.m_location;
}

void Piece::setLocation(int x, int y){
    m_location = make_pair(x,y);
}

Piece::~Piece(){}

/*-------------------------------------------------------------

Implementation of the Board class

---------------------------------------------------------------*/
Board::Board(int length, int width){
    m_length = length;
    m_width = width;
    tiles = new Piece*[m_width];
    //Creating the board
    for(int i = 0; i < m_width; i++){
        tiles[i] = new Piece[m_length];
    }
    //Publicating the board with default setup og pieces
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
}

GamePlay::~GamePlay(){
    //~Board();
}
///Outputs the list of games available to play
void GamePlay::listOfGames(){
    for(unsigned int i = 0; i < sizeof(Game); i++){
        switch(i){
            case 0: cout << "Breakthrough";
            case 1: cout << "Ataxx";
        }
        cout << endl;
    }
}

///Quits the game play
void quit();

