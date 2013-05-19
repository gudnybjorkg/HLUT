#include "Breakthrough.h"
#include <utility>
#include <algorithm>
using namespace std;

Breakthrough::Breakthrough() : GamePlay()
{
    m_board = Board(8,8);
    m_p1.setType('X');
    m_p1.setNoPawns(16);
    m_p2.setType('O');
    m_p2.setNoPawns(16);

}

void Breakthrough::make(int from_row, int from_col, int to_row, int to_col)
{

    if(!legalMove(from_row, from_col, to_row, to_col)){
        cout << "Illegal move! Try again." << endl;
        return;
    }

    State currentState;
    currentState.p1 = m_p1;
    currentState.p2 = m_p2;
    currentState.b = m_board;
    m_states.push(currentState);

    //Finding the player which turn it is
    if(m_turns % 2 == 0)
    {
        m_p1.setLastLocation(from_row,from_col);
        m_p1.setNextLocation(to_row, to_col);

        int to_row = m_p1.getNextLocation().first;
        int to_col = m_p1.getNextLocation().second;
        int from_row = m_p1.getPrevLocation().first;
        int from_col = m_p1.getPrevLocation().second;

        //if there is a pawn in the tile that is being mobed to, then incrementing the number of pawns for the opponent
        if(m_board.getBoard()[to_row][to_col].getType() != '.')
        {
            m_p2.decPawns();
            m_p2.setkilled(true);
        }
        //Moves the piece to it's next location
        m_board.getBoard()[to_row][to_col].setOwner(m_p1);
        m_board.getBoard()[to_row][to_col] = m_p1.getType();
        m_board.getBoard()[from_row][from_col].setOwner(Player());
        m_board.getBoard()[from_row][from_col] = '.';

        m_p1.setLastLocation(from_row, from_col);

        cout << "move " << from_row	<< " " << from_col << " " << to_row << " " << to_col << endl;
    }
    else
    {
        m_p2.setLastLocation(from_row,from_col);
        m_p2.setNextLocation(to_row, to_col);

        //The locations
        int to_row = m_p2.getNextLocation().first;
        int to_col = m_p2.getNextLocation().second;
        int from_row = m_p2.getPrevLocation().first;
        int from_col = m_p2.getPrevLocation().second;

        //if there is a pawn in the tile that is being mobed to, then incrementing the number of pawns for the opponent
        if(m_board.getBoard()[to_row][to_col].getType() != '.')
        {
            m_p1.decPawns();
            m_p1.setkilled(true);
        }
        //Moves the piece to it's next location
        m_board.getBoard()[to_row][to_col].setOwner(m_p2);
        m_board.getBoard()[to_row][to_col] = m_board.getBoard()[from_row][from_col].getType();
        m_board.getBoard()[from_row][from_col].setOwner(m_p1);
        m_board.getBoard()[from_row][from_col] = '.';

        cout << "move " << from_row	<< " " << from_col << " " << to_row << " " << to_col << endl;
    }

    if(m_p1.getId() == finalState())
    {
        cout << "Congratulations, Player 1 wins!" << endl;
        m_win = true;
    }
    else if(m_p2.getId() == finalState())
    {
        cout << "Congratulations, Player 2 wins!" << endl;
        m_win = true;
    }
    m_turns++;
}

void Breakthrough::start()
{
    for(int i = 0; i < 8; ++i)
    {
        //Player 1
        m_board.getBoard()[0][i].setOwner(m_p1);
        m_board.getBoard()[0][i] = m_p1.getType();
        m_board.getBoard()[1][i].setOwner(m_p1);
        m_board.getBoard()[1][i] = m_p1.getType();
        //Player 2
        m_board.getBoard()[6][i].setOwner(m_p2);
        m_board.getBoard()[6][i] = m_p2.getType();
        m_board.getBoard()[7][i].setOwner(m_p2);
        m_board.getBoard()[7][i] = m_p2.getType();

    }
}
bool Breakthrough::legalMove(int from_row, int from_col, int to_row, int to_col)
{
    cout << "LEGAL MOVE BEGINS" << endl;
    ///Checks if you try to access pieces outside of the board
    if(from_row < 0 || from_row > 7)
        return false;
    if(from_col < 0 || from_col > 7)
        return false;
    if(to_row < 0 || to_row > 7)
        return false;
    if(to_col < 0 || to_col > 7)
        return false;

    if(m_turns % 2 == 0)
    {
        //if the player tries to move a pawn that is not his
        if(m_board.getBoard()[from_row][from_col].getOwner().getId() != m_p1.getId())
        {
            cout << "Illegal move, this is not your pawn." << endl;
            return false;
        }
        //if the destination tile is further than one tile away
        //and if the player tries to move the piece backwards or sideways
        if((to_row - from_row) != 1  || (from_row >= to_row))
        {
            cout << "Illegal move, you cannot go there." << endl;
            return false;
        }
        //If there is an opponent in the destination tile and the tile is infront of the pawn to be moved
        if(m_board.getBoard()[to_row][to_col].getOwner().getId() == m_p2.getId() && to_col == from_col)
        {
            cout << "Illegal move, you cannot kill this pawn." << endl;
            return false;
        }
        //if the destination tile holds a pawn that is on the players team
        else if(m_board.getBoard()[to_row][to_col].getOwner().getId() == m_p1.getId())
        {
            cout << "Illegal move, you already have a pawn there." << endl;
            return false;
        }
    }
    else
    {
        //if the player tries to move a pawn that is not his
        if(m_board.getBoard()[from_row][from_col].getOwner().getId() != m_p2.getId())
        {
            //cout << "Illegal move, this is not your pawn." << endl;
            return false;
        }
        //if the destination tile is further than one tile away
        //and if the player tries to move the piece backwards or sideways
        if((to_row - from_row) != -1  || (from_row <= to_row))
        {
            //cout << "Illegal move, you cannot go there." << endl;
            return false;
        }
        //If there is an opponent in the destination tile and the tile is infront of the pawn to be moved
        if(m_board.getBoard()[to_row][to_col].getOwner().getId() == m_p1.getId() && to_col == from_col)
        {
            //cout << "Illigal move, you cannot kill this pawn." << endl;
            return false;
        }
        //if the destination tile holds a pawn that is on the players team
        else if(m_board.getBoard()[to_row][to_col].getOwner().getId() == m_p2.getId())
        {
            //cout << "Illigal move, you already have a pawn there." << endl;
            return false;
        }
    }
    cout << "LEGAL MOVE ENDS" << endl;
    return true;
}

int Breakthrough::finalState()
{
    for(int i = 0; i < 8; ++i)
    {
        //Player 2 wins
        if(m_board.getBoard()[0][i].getOwner().getId() == m_p2.getId())
            return m_p2.getId();
        //Player 1 wins
        if(m_board.getBoard()[7][i].getOwner().getId() == m_p1.getId())
            return m_p1.getId();
    }
    if(m_p1.getNoPawns() == 0)
        return m_p2.getId();
    else if(m_p2.getNoPawns() == 0)
        return m_p1.getId();
    return -1;
}

 void Breakthrough::setLegalMoves()
{
    m_legalMoves.clear();
    Piece** p = m_board.getBoard();

    if(m_turns % 2 == 0)
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if((p[i][j]).getOwner().getId() == 0)
                {
                    cout << "Set legal moves IN IF OWNER" << i << j << i+1 << j-1 << endl;
                    if(legalMove(i,j,(i+1),(j-1))){
                        m_legalMoves.push_back(Moves(i, j, i+1, j-1));
                         cout << "INPUT" << endl;
                    }
                    //cout << "Set legal moves IN IF OWNER AFTER J-1" << i << j << i+1 << j-1 << endl;
                    if(legalMove(i,j,(i+1),(j))){
                        m_legalMoves.push_back(Moves(i, j, i+1, j));
                        cout << "INPUT" << endl;
                    }
                    //cout << "Set legal moves IN IF OWNER AFTER J" << i << j << i+1 << j-1 << endl;
                    if(legalMove(i,j,(i+1),(j+1))){
                        m_legalMoves.push_back(Moves(i, j, i+1, j+1));
                        cout << "INPUT" << endl;
                    }
                    cout << "Set legal moves IN IF OWNER AFTER J+1" << i << j << i+1 << j-1 << endl;
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if((p[i][j]).getOwner().getId() == 1)
                {
                    if(legalMove(i,j,(i-1),(j-1)))
                        m_legalMoves.push_back(Moves(i,j,i-1,j-1));
                    if(legalMove(i,j,(i-1),(j)))
                        m_legalMoves.push_back(Moves(i,j,i-1,j));
                    if(legalMove(i,j,(i-1),(j+1)))
                        m_legalMoves.push_back(Moves(i,j,i-1,j+1));
                }
            }
        }
    }
}

void Breakthrough::display()
{
    Piece** p = m_board.getBoard();

    cout << "                              " << '\n';
    cout << "      0   1   2   3   4   5   6   7   " << '\n';
    cout << "    _________________________________  " <<'\n';

    for(int i = 0; i < 8; i++)
    {
        cout << "    |   |   |   |   |   |   |   |   |  " << '\n';
        cout << " " << i <<"  |";

        for(int j = 0; j < 8; j++)
        {
            cout << " " << p[i][j].getType() << " |";
        }
        cout << '\n';
        cout << "    |   |   |   |   |   |   |   |   |  " << '\n';
        cout << "    _________________________________  " <<'\n';

    }
    cout << "Player: " << (m_turns % 2) << endl;
    cout << "Player 1 has " << m_p1.getNoPawns() << " pawns." << endl;
    cout << "Player 2 has " << m_p2.getNoPawns() << " pawns." << endl;
}

Breakthrough::~Breakthrough()
{
    //dtor
}
