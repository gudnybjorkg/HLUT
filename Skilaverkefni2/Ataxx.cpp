#include "Ataxx.h"
#include <cmath>
using namespace std;
/*
Ataxx::Ataxx() : GamePlay()
{
    m_board = Board(7,7);
    display();
    m_p1.setType('p');
    m_p1.setNoPawns(2);
    m_p2.setType('P');
    m_p2.setNoPawns(2);
}

void Ataxx::start(){
    Piece p1('P');
    Piece p2('p');
    Piece empty('.');

    for (int i=0; i < 7; i++)
    {
        for (int j=0; j < 7; j++)  ///initialize board
        {
            m_board.setPieceOnBoard(i, j, empty);
        }
    }
    m_board.setPieceOnBoard(0, 7, p1); ///player 1 set in left bottom corner
    m_board.setPieceOnBoard(7, 0, p1); ///player 1 set in right top corner
    m_board.setPieceOnBoard(0, 0, p2); ///player 2 set in right bottom corner
    m_board.setPieceOnBoard(7, 7, p2); ///player 2 set in right bottom corner
}

bool Ataxx::legalMove(Piece p, std::pair<int, int> destination)
{
    pair<int,int> currentLocation = p.getLocation();
    int from_row = currentLocation.first;
    int from_col = currentLocation.second;
    int to_row = destination.first;
    int to_col = destination.second;

    if ((-2<=(from_col - to_col) && (from_col - to_col) <=2) && (-2<=(from_row - to_row) && (from_row - to_row)<=2))  ///checks if the move is 2 blocks away
    {
        if (m_board.getBoard()[to_row][to_col].getType() == '.') // if the tile is free
        {
            return true;
        }
    }
    return false;
}

void Ataxx::convertPiece(int row, int col, Player p, Player opp){
    Piece pie = m_board.getBoard()[row][col];
    if (p.getId() != pie.getOwner().getId() && pie.getOwner().getId() != -1) /// if the player doesnt own the current pawn and the tile isn't empty
    {
        pie.setOwner(p);
        pie.setType(p.getType());
        p.setNoPawns(p.getNoPawns()+1);
        opp.setNoPawns(opp.getNoPawns()-1);  ///win state hér ef opp á 0
    }
}

void Ataxx::make(int from_col, int from_row, int to_col, int to_row)
{
    Piece p = m_board.getBoard()[from_row][from_col];
    Player owner = p.getOwner();
    Piece empty('.');

    if (legalMove(m_board.getBoard()[from_row][from_col],pair<int,int>(to_row,to_col))){
        owner.setLastLocation(from_row, to_row);
        owner.setNextLocation(to_row, to_col);
    }
}

void Ataxx::go()
{
    Player p, opponent;
    if (m_turns %2 == 0)
    {
        p = m_p1;
        opponent = m_p2;
    }
    else
    {
        p = m_p2;
        opponent = m_p1;
    }
    std::pair<int, int> to = m_p1.getNextLocation();
    std::pair<int, int> from = m_p1.getPrevLocation();
    int from_row = from.first;
    int from_col = from.second;
    int to_row = to.first;
    int to_col = to.second;
    Piece pie = m_board.getBoard()[from_row][from_col];
    Piece empty('.');


    if ((-1<=(from_col - to_col) && (from_col - to_col) <=1) && (-1<=(from_row - to_row) && (from_row - to_row)<=1))  ///checks if the   move is 1 block away
    {
        m_board.setPieceOnBoard(to_row, to_col, pie); ///no need to remove pawn since we are cloning
    }
    else /// the move must be 2 blocks away since its legal and not 1 block away
    {
        m_board.setPieceOnBoard(to_row, to_col, pie); ///moves the piece for the player
        m_board.setPieceOnBoard(from_row, from_col, empty); ///removes the old since we are not moving 1
    }


    ///convert all the pawns around the pawn
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0 ; j < 7; j++)
        {
            if (abs(to_row - i) == 1 || abs(to_col - j) == 1)
            {
                convertPiece(i, j, p, opponent);
            }
        }
    }
}


void Ataxx::retract(Player player)
{
    Player p;
    Player opponent;
    //Finding the correct player to move
    if(m_turns % 2 == 0)
    {
        p = m_p1;
        opponent = m_p2;
    }
    else
    {
        p = m_p2;
        opponent = m_p1;
    }

    pair<int,int> prevOp = opponent.getPrevLocation();
    pair<int,int> nextOp = opponent.getNextLocation();
    pair<int,int> prevP = p.getPrevLocation();
    pair<int,int> nextP = p.getNextLocation();




    if (abs(prevOp))  ///checks if the   move is 1 block away
    {
        ///if the move was at distance 1 i need to remove the clone and revert the convert

    }
    else /// the move must be 2 blocks away since its legal and not 1 block away
    {
        ///if the move was at distance 2 i just need to move the the pawn back and revert the convert
    }

    m_turns--;
}
*/

