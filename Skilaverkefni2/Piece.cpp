#include "Piece.h"
#include <iostream>
using namespace std;

///constructor for the piece
Piece::Piece(){
    m_type = '.';
    m_owner.setId(-1);
}

///constructor for piece with a char
Piece::Piece(char type){
    m_type = type;
    if(type == 'X')
        m_owner.setId(0);
    else
        m_owner.setId(1);
}

///sets the owner of the current piece
void Piece::setOwner(Player owner){
    m_owner = owner;
}

///returns the owner of the piece
Player Piece::getOwner(){
    return m_owner;
}

///returns the type of the piece
char Piece::getType(){
    return m_type;
}

///Sets the type of the piece
void Piece::setType(char type){
    m_type = type;
}

///Returns the location of the piece
pair<int, int> Piece::getLocation(){
    return m_location;
}

///Sets the location of the piece
void Piece::setLocation(int x, int y){
    m_location.first = x;
    m_location.second = y;
}
