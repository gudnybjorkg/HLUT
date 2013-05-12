#ifndef GAME_H
#define GAME_H

enum Game{ Breakthrough = 0, Ataxx = 1};

struct Player{
public:
    Player();
private:
    int m_noPlayers;
    int m_score;
};

struct Board{
public:
    /*Constructs a square board with a specific size of length and width.
           L  e  n  g  t  h
        W  |  |  |  |  |  |
        i  |  |  |  |  |  |
        d  |  |  |  |  |  |
        t  |  |  |  |  |  |
        h  |  |  |  |  |  |
    */
    Board();
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
    Player p2;
};


#endif //GAME_H
