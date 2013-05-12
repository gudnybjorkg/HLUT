#ifndef GAME_H
#define GAME_H

enum Game{ Breakthrough = 0, Ataxx = 1};

struct Player{
public:
    Player();
private:
    int m_score;
    int noPawns;
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
    Board(){}
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
    //Part 2
    void listOfGames();
    void quit();

    virtual void start() = 0;
    virtual int getNopawns(Player player) = 0;
    virtual void legal() = 0;
    virtual void make(int from_col, int from_row, int to_col, int to_row) = 0;
    virtual void retract() = 0;
    virtual void display() = 0;
    virtual void level(int difficulty) = 0;
    virtual void evaluate(Board board) = 0;
    virtual void go() = 0;
    virtual void debug() = 0;

private:
    int difficulty;
    int m_gametype;
    Board m_board;
    Player p1;
    Player p2;
};


#endif //GAME_H
