#ifndef GAME_H
#define GAME_H
#include "Piece.h"
#include "Board.h"
#include "Player.h"

#include <vector>
#include <string>
#include <stack>

/**
An interface for implemtation of two-player board games.
*/
enum Game { breakthrough = 0, ataxx = 1};

/**
A struct for containing the board state and the players in the game
*/
struct State
{
    Player p1;
    Player p2;
    Board b;
    int turns;
};

/***/
struct Moves
{
    Moves(int fRow, int fCol, int tRow, int tCol)
    {
        from_row = fRow;
        from_col = fCol;
        to_row = tRow;
        to_col = tCol;
    }
    bool operator ==(const Moves& rhs) const
    {
        return(from_col == rhs.from_col && from_row == rhs.from_row && to_col == rhs.to_col && to_row == rhs.to_row);
    }
    int from_row, from_col;
    int to_row, to_col;
};

/**--------------------------------------------------------------------------

The interface for implementing a two-player board game with a set of rules and
strategies.

---------------------------------------------------------------------------*/
class GamePlay
{
public:
    ///Construtor
    GamePlay();

    ///Returns the board
    Board getBoard();

    ///Destructor
    virtual ~GamePlay();

    ///Returns true if move for the corresponding piece is valid
    virtual bool legalMove(int from_row, int from_col, int to_row, int to_col) = 0;

    ///Outputs the list of games available to play
    void listOfGames();

    ///Quits the game play
    void quit();

    ///Starts a new match game with all pieces in start position.
    virtual void start() = 0;

    ///Returns the number of pieces for the corresponding player
    int getNoPieces(Player player);

    ///Outputs all legal moves for the corresponding piece to perform.
    virtual void setLegalMoves() = 0;

    ///Moves a pice from a position to another position
    virtual void make(int from_row, int from_col, int to_row, int to_col) = 0;

    ///Retracts the last move performed by the corresponding player,
    ///also retrieving the last move og the opposite player
    void retract();

    ///Displays the current gamestate, ie. each piece on the board in it's position
    ///Each tile containing a '.' is an empty square.
    virtual void display() = 0;

    /**
    Sets the difficulty of the moves to be played
        random: plays a random legal move
        easy: plays the best legal move using an one-ply look-a-head and piece count evaluation
        medium: plays the best legal move using a three-ply minimax search and a piece count evaluation
        hard: plays the best legal move using a three-ply minimax search and an advanced evaluation
    */
    virtual void level(std::string difficulty);

    ///Returns the evaluation value of the current board state
    virtual int evaluate();

    ///Returns true if the game has reached a winning state
    bool getWinState();

    ///Returns all legal moves.
    std::vector<Moves> getlegalMoves();

    std::string getDifficulty();

    void incTurns();

protected:
    std::string m_difficulty;
    int m_turns;            /// Counts the number of turns in the game
    bool m_win;
    Board m_board;
    Player m_p1;
    Player m_p2;
    std::stack<State> m_states;
    std::vector<Moves> m_legalMoves;
};



#endif //GAME_H
