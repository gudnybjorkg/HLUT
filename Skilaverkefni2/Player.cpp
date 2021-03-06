#include "Player.h"
using namespace std;
Player::Player(){
    m_score = 0;
    m_type = '.';
    m_id = -1;
}

///Set id
void Player::setId(int id){
    m_id = id;
}

///Get id
int Player::getId(){
    return m_id;
}

int Player::getNoPawns()
{
    return noPawns;
}
void Player::setNoPawns(int value){
    noPawns = value;
}

///Sets killed
void Player::setkilled(bool b)
{
    m_killed = b;
}

///Sets the type
void Player::setType(char c)
{
    m_type = c;
}

///Returns the type
char Player::getType()
{
    return m_type;
}

///Returns true if the last move killed an opponent
bool Player::getKilled()
{
    return m_killed;
}

///Returns the location of the
void Player::setLastLocation(int row, int col)
{
    m_lastLocation = std::make_pair(row,col);
}

void Player::setNextLocation(int row, int col)
{
    m_nextLocation = std::make_pair(row,col);
}

///returns the next location
pair<int,int> Player::getNextLocation()
{
    return m_nextLocation;
}

///returns the last location
pair<int,int> Player::getPrevLocation()
{
    return m_lastLocation;
}

///decrements the pawn count of the player
void Player::decPawns()
{
    noPawns--;
}
Player::~Player() {}
