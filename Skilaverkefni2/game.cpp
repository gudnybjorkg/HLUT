#include <iostream>
#include "game.h"
#include <stdlib.h>
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
    if(isupper(type))
        m_owner = 0;
    else
        m_owner = 1;
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

Piece** Board::getBoard(){
        return m_tiles;
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
///Returns the board
Board GamePlay::getBoard(){
    return m_board;
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
void GamePlay::quit(){
    cout << "Are you sure you want to quit the game? (y/n)" << endl;
    char ans;
    cin >> ans;
    if(ans == 'y' || ans == 'Y')
        exit(0);
    else return;
}


/*-------------------------------------------------------------
 
 Implementation of the atixx gameplay class
 
 ---------------------------------------------------------------*/

Atixx::Atixx(){
    Piece p1('P');
    Piece p2('p');
    //m_board.setTile(7, 0, 'P');
    //m_board.setTile(0, 7, 'P');
    //m_board.setTile(0, 0, 'p');
    //m_board.setTile(7, 7, 'p');
    
    p1.setLocation(7, 0); //player 1 set in left bottom corner 
    p1.setLocation(0, 7); //player 1 set in right top corner
    p2.setLocation(0, 0); //player 2 set in right bottom corner
    p2.setLocation(7, 7); //player 2 set in right bottom corner
}

bool Atixx::legalMove(int from_col, int from_row, int to_col, int to_row)
{
    {
        
    }
    
    if ((-2<=(from_col - to_col)<=2) && (-2<=(from_row - to_row)<=2)) //checks if the move is 2 blocks away
    {
        return true;
    }
    else
        return false;
}
