#include "Player.h"

Player::Player(){
    m_score = 0;
}

void Player::setDifficulty(std::string difficulty){
    m_difficulty = difficulty;
}

Player::~Player(){}
