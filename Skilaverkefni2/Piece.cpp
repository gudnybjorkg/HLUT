#include "Piece.h"
#include <iostream>
using namespace std;

Piece::Piece(){
    m_type = '.';
    m_owner.setId(-1);
}

Piece::Piece(char type){
    m_type = type;
    if(type == 'X')
        m_owner.setId(1);
    else
        m_owner.setId(0);
}

void Piece::setOwner(Player owner){
    m_owner = owner;
}

Player Piece::getOwner(){
    return m_owner;
}

char Piece::getType(){
    return m_type;
}

///Sets the type
void Piece::setType(char type){
    m_type = type;
}

pair<int, int> Piece::getLocation(){
    return m_location;
}

void Piece::setLocation(int x, int y){
    m_location.first = x;
    m_location.second = y;
}

Piece::~Piece(){}
