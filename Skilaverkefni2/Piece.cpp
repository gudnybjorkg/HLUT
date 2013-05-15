#include "Piece.h"
#include <iostream>
using namespace std;

Piece::Piece(){
    m_type = '.';
    m_owner.setId(-1);
}

Piece::Piece(char type){
    m_type = type;
    if(isupper(type))
        m_owner.setId(0);
    else
        m_owner.setId(1);
}

void Piece::setOwner(Player owner){
    cout << "Set owner";
    m_owner = owner;
}

Player Piece::getOwner(){
    return m_owner;
}

char Piece::getType(){
    return m_type;
}

///Sets the type
void Piece::setType(Piece piece){
    m_type = piece.getType();
}

pair<int, int> Piece::getLocation(){
    return m_location;
}

void Piece::setLocation(int x, int y){
    m_location = std::make_pair(x,y);
}

Piece::~Piece(){}
