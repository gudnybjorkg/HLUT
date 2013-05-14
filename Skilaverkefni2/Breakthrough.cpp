#include "Breakthrough.h"

Breakthrough::Breakthrough() : GamePlay()
{
    m_board = Board(8,8);
}
Breakthrough::~Breakthrough() {}

bool Breakthrough::legalMove(Piece p, std::pair<int, int> destination)
{
    return true;
}
void Breakthrough::start()
{
    for(int i = 0; i < 8.; ++i)
    {
        //Player 1
        m_board.getTiles()[0][i].setOwner(0);
        m_board.getTiles()[0][i] = 'p';
        m_board.getTiles()[1][i].setOwner(0);
        m_board.getTiles()[1][i] = 'p';
        //Player 2
        m_board.getTiles()[6][i].setOwner(1);
        m_board.getTiles()[6][i] = 'P';
        m_board.getTiles()[7][i].setOwner(1);
        m_board.getTiles()[7][i] = 'P';
    }

}
///Returns the number of pieces for the corresponding player
int Breakthrough::getNoPieces(Player player){
    return 1;
}

///Outputs all legal moves for the corresponding piece to perform.
void Breakthrough::legal(Piece piece){

}

///Moves a pice from a position to another position
void Breakthrough::make(int from_col, int from_row, int to_col, int to_row){

}

///Retracts the last move performed by the corresponding player,
///also retrieving the last move og the opposite player
void Breakthrough::retract(Player player){

}

///Displays the current gamestate, ie. each piece on the board in it's position
///Each tile containing a '.' is an empty square.
void Breakthrough::display(){

}

/*
Sets the difficulty of the moves to be played
    random: plays a random legal move
    easy: plays the best legal move using an one-ply look-a-head and piece count evaluation
    medium: plays the best legal move using a three-ply minimax search and a piece count evaluation
    hard: plays the best legal move using a three-ply minimax search and an advanced evaluation
*/
void Breakthrough::level(std::string difficulty){

}

///Returns the evaluation value of the current board state
int Breakthrough::evaluate(Board board){
    return 1;
}

/*
The computer plays for the player to move using the current difficulty level
and outputs the move it made as <from_col, from_row, to_col, to_row>
Displays the winner if a winnig state has been reached
*/
void Breakthrough::go(){

}

///Toggle debug	mode on	or off. In debug made your software	can	display	to standard	output any additional
///information it wants. However, when debug mode is off only the asked	for	output should be displayed.
///By default the debug	should be off.
void Breakthrough::debug(){

}
