#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
/*
An interface for implemtation of two-player board games.
*/
enum Game{ Breakthrough = 0, Ataxx = 1};
/*---------------------------------------------------------------------------

A class representing a piece on a board game to be played and strategized
by the player.
---------------------------------------------------------------------------*/
class Piece{
public:
    ///Constructor
    Piece();

    ///Constructor, initializing the type of the piece
    Piece(char type);

    ///Set function for the owner of the piece
    void setOwner(int owner);

    ///Returns the owner of the piece
    int getOwner();

    ///Returns the location of the piece as a pair of coordinates, Example <0,1> represents the row 0 and column 1 on the board.
    std::pair<int, int> getLocation(Piece piece);

    ///Anitializes the location of the piece
    void setLocation(int x, int y);

    ///Destructor
    virtual ~Piece();
    
private:
    char m_type;
    int m_owner;
    std::pair<int,int> m_location;
};
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
/*---------------------------------------------------------------------------


A class representing the boad of size length x whidth. Each tile on the
board holds a pawn that is to be moved around.

class Board{
public:
/*Constructs a square board with a specific size of length and width.

           L  e  n  g  t  h
        W  |  |  |  |  |  |
        i  |  |  |  |  |  |
        d  |  |  |  |  |  |
        t  |  |  |  |  |  |
        h  |  |  |  |  |  |

---------------------------------------------------------------------------*/
struct Board{
public:
    //Constructor
    Board(){}
    
    //Destructor
    ~Board();

    //Constructs a square board with a specific size of length and width.
    Board(int length, int width);
    
    //Returns the board
    Piece** getBoard();

private:
    int m_length;
    int m_width;
    Piece **m_tiles;
};
/*---------------------------------------------------------------------------

The interface for implementing a two-player board game with a set of rules and
strategies.

---------------------------------------------------------------------------*/
class GamePlay{
public:
    ///Construtor
    GamePlay();

    ///Returns the board
    Board getBoard();

    ///Destructor
    virtual ~GamePlay();

    ///Returns true if move for the corresponding piece is valid
    virtual bool legalMove(Piece p, std::pair<int, int> destination) = 0;

    ///Outputs the list of games available to play
    void listOfGames();

    ///Quits the game play
    void quit();

    ///Starts a new match game with all pieces in start position.
    virtual void start() = 0;

    ///Returns the number of pieces for the corresponding player
    virtual int getNoPieces(Player player) = 0;

    ///Outputs all legal moves for the corresponding piece to perform.
    virtual void legal(Piece piece) = 0;

    ///Moves a pice from a position to another position
    virtual void make(int from_col, int from_row, int to_col, int to_row) = 0;

    ///Retracts the last move performed by the corresponding player,
    ///also retrieving the last move og the opposite player
    virtual void retract(Player player) = 0;

    ///Displays the current gamestate, ie. each piece on the board in it's position
    ///Each tile containing a '.' is an empty square.
    virtual void display() = 0;

    /*
    Sets the difficulty of the moves to be played
        random: plays a random legal move
        easy: plays the best legal move using an one-ply look-a-head and piece count evaluation
        medium: plays the best legal move using a three-ply minimax search and a piece count evaluation
        hard: plays the best legal move using a three-ply minimax search and an advanced evaluation
    */
    virtual void level(std::string difficulty) = 0;

    ///Displays the evaluation value of the current board state
    virtual void evaluate(Board board) = 0;

    /*
    The computer plays for the player to move using the current difficulty level
    and outputs the move it made as <from_col, from_row, to_col, to_row>
    Displays the winner if a winnig state has been reached
    */
    virtual void go() = 0;

    ///Toggle debug	mode on	or off. In debug made your software	can	display	to standard	output any additional
    ///information it wants. However, when debug mode is off only the asked	for	output should be displayed.
    ///By default the debug	should be off.
    virtual void debug() = 0;

private:
    int m_turns;            /// Counts the number of turns in the game
    Board m_board;
    Player m_p1;
    Player m_p2;
};

class Atixx : public GamePlay{
public:
    Atixx();      //set up the board and the game for ataxx
    virtual bool legalMove(int from_col, int from_row, int to_col, int to_row);
private:
    Board m_board;
    
};


#endif //GAME_H
