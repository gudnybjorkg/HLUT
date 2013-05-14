#include "Piece.h"
#include <iostream>
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
    m_location = std::make_pair(x,y);
}

Piece::~Piece(){}