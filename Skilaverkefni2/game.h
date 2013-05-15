#ifndef GAME_H
#define GAME_H
#include "Piece.h"
#include "Board.h"
#include "Player.h"

#include <vector>
#include <string>
/*
An interface for implemtation of two-player board games.
*/
enum Game{ breakthrough = 0, ataxx = 1};

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
    virtual int getNoPieces(Player player);

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

    ///Returns the evaluation value of the current board state
    virtual int evaluate(Board board) = 0;

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

protected:
    int m_turns;            /// Counts the number of turns in the game
    Board m_board;
    Player m_p1;
    Player m_p2;
};



#endif //GAME_H
