#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

enum Game{ Breakthrough = 0, Ataxx = 1};

struct Player{
public:
    //test1
    //Constructs a Player with a specific number of "pawns"
    Player(int noPlayers);
    int getScore();
private:
    void setScore(int score);

    int m_noPlayers;
    int m_score;
};

struct Board{
public:
    //Constructs a square board of a specific size.
    Board(int length, int width);
private:
    int m_length;
    int m_width;
    int **tiles;
};
//The interface for implementing board games.
class GamePlay{
public:
    GamePlay(int gametype);
    virtual ~GamePlay();
    virtual bool legalMove() = 0;
private:
    int m_gametype;
    Board m_board;
    Player p1;
    Player P2;
};


#endif //GAME_H
