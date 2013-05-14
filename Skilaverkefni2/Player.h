#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "Piece.h"
/*---------------------------------------------------------------------------

A class representing the player participating in a board game.

---------------------------------------------------------------------------*/
class Player{
public:
    ///Constructor.
    Player();

    ///Sets the difficulty of the moves to be played.
    void setDifficulty(std::string difficulty);

    ///Destructor
    ~Player();
private:
    std::pair<int, int> m_lastLocation;     ///For retrieval moves
    std::pair<int, int> m_nextLocation;     ///For making the next move
    int noPawns;
    int m_score;
    std::string m_difficulty;               /// Represents the difficulty of moves to be played
    std::vector<Piece> m_pieces;
};

#endif // PLAYER_H
