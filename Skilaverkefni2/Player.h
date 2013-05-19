#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
/*---------------------------------------------------------------------------

A class representing the player participating in a board game.

---------------------------------------------------------------------------*/
class Player
{
public:
    ///Constructor.
    Player();

    ///Returns number of pawns
    int getNoPawns();

    ///Sets the previous location
    void setLastLocation(int row, int col);

    ///returns the next location
    std::pair<int,int> getNextLocation();

    ///returns the last location
    std::pair<int,int> getPrevLocation();

    ///Sets the next location
    void setNextLocation(int row, int col);

    ///increments the score with 1 point
    void decPawns();

    ///Sets killed
    void setkilled(bool b);

    ///Returns true if the last move killed an opponent
    bool getKilled();

    ///Returns the type
    char getType();

    ///Sets the type
    void setType(char c);

    ///Set id
    void setId(int id);

    ///Get id
    int getId();

    ///Destructor
    ~Player();

    ///sets the number of pawns
    void setNoPawns(int value);

private:
    int m_id;
    char m_type;
    std::pair<int, int> m_lastLocation;     ///For retrieval moves
    std::pair<int, int> m_nextLocation;     ///For making the next move
    int noPawns;                            ///The number of the pawns
    int m_score;                            ///The score for the current player
    bool m_killed;                          ///True if last move killed
};

#endif // PLAYER_H
