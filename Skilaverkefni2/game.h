#ifndef GAME_H
#define GAME_H
#include <vector>

enum Game{ Breakthrough = 0, Ataxx = 1};

class Piece{
public:
    Piece();
    Piece(char type);
    void setOwner(int owner);
    int getOwner();
    std::pair<int, int> getLocation();
    void setLocation(int x, int y);
    virtual ~Piece();
private:
    char m_type;
    int m_owner;
    std::pair<int,int> m_location;
};

struct Player{
public:
    Player();
private:
    pair<int, int> m_lastLocation;
    int m_score;
    std::vector<Piece> m_pieces;
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
    Piece **tiles;
};
//The interface for implementing board games.
class GamePlay{
public:
    GamePlay();
    virtual ~GamePlay();
    virtual bool legalMove() = 0;

    //Part 2
    void listOfGames();
    void quit();

    virtual void start() = 0;
    virtual int getNoPieces(Player player) = 0;
    virtual void legal(Piece piece) = 0;
    virtual void make(int from_col, int from_row, int to_col, int to_row) = 0;
    virtual void retract() = 0;
    virtual void display() = 0;
    virtual void level(int difficulty) = 0;
    virtual void evaluate(Board board) = 0;
    virtual void go() = 0;
    virtual void debug() = 0;

private:
    int m_turns;
    int m_difficulty;
    int m_gametype;
    Board m_board;
    Player m_p1;
    Player m_p2;
};


#endif //GAME_H
