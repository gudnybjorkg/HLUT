#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
/*---------------------------------------------------------------------------

A class representing the player participating in a board game.

---------------------------------------------------------------------------*/
class Player{
public:
    ///Constructor.
    Player();

    ///Sets the difficulty of the moves to be played.
    void setDifficulty(std::string difficulty);

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
    void incPawns();

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

    ///Assignment operator
    Player& operator =(const Player& rhs){
        m_id = rhs.m_id;
        m_type = rhs.m_type;
        m_lastLocation.first = rhs.m_lastLocation.first;
        m_lastLocation.second = rhs.m_lastLocation.second;
        //std::cout << "ASSIGNMENT GAUR " << m_lastLocation.first << " " << m_lastLocation.second;
        m_nextLocation = rhs.m_nextLocation;
        noPawns = rhs.noPawns;
        m_score = rhs.m_score;
        m_killed = rhs.m_killed;
        m_difficulty = rhs.m_difficulty;
        return *this;
    }

    ///Copy constructor
    Player(const Player& rhs){
        m_id = rhs.m_id;
        m_type = rhs.m_type;
        m_lastLocation = rhs.m_lastLocation;
        m_nextLocation = rhs.m_nextLocation;
        noPawns = rhs.noPawns;
        m_score = rhs.m_score;
        m_killed = rhs.m_killed;
        m_difficulty = rhs.m_difficulty;
    }

    ///Destructor
    ~Player();

    ///sets the number of pawns
    void setNoPawns(int value);

private:
    int m_id;
    char m_type;
    std::pair<int, int> m_lastLocation;     ///For retrieval moves
    std::pair<int, int> m_nextLocation;     ///For making the next move
    int noPawns;
    int m_score;
    bool m_killed;                          ///True if last move killed
    std::string m_difficulty;               /// Represents the difficulty of moves to be played
};

#endif // PLAYER_H
