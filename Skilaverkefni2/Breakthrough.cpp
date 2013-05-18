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

    if(!legalMove(from_row, from_col, pair<int,int>(to_row,to_col)))
    {
        //cout << "This is not a legal move, please try again." << endl;
        return;
    }

    State currentState;
    currentState.p1 = m_p1;
    currentState.p2 = m_p2;
    currentState.b = m_board;
    currentState.turns = m_turns;
    m_states.push(currentState);

    //Finding the player which turn it is
    if(m_turns % 2 == 0)
    {
        m_p1.setLastLocation(from_row,from_col);
        m_p1.setNextLocation(to_row, to_col);
    }
    else
    {
        m_p2.setLastLocation(from_row,from_col);
        m_p2.setNextLocation(to_row, to_col);
    }
    //Sets the locations to be moved to.
    cout << "Make : turns " << m_turns << endl;
    go();
}

void Breakthrough::go()
{
    if(m_turns % 2 == 0)
    {
        //The locations
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

        cout << "move " << from_col	<< " " << from_row << " " << to_col << " " << to_row << endl;
    }
    else
    {
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
    m_turns++;

    if(m_p1.getId() == finalState())
        cout << "Congratulations, Player 1 wins!" << endl;
    else if(m_p2.getId() == finalState())
        cout << "Congratulations, Player 2 wins!" << endl;
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
bool Breakthrough::legalMove(int row, int col, pair<int, int> destination)
{
    int destX = destination.first;
    int destY = destination.second;

    if(m_turns % 2 == 0)
    {
        //if the player tries to move a pawn that is not his
        if(m_board.getBoard()[row][col].getOwner().getId() != m_p1.getId())
        {
            cout << "Illegal move, this is not your pawn." << endl;
            return false;
        }
        //if the destination tile is further than one tile away
        //and if the player tries to move the piece backwards or sideways
        if((destX - row) != 1  || (row >= destX))
        {
            cout << "Illegal move, you cannot go there." << endl;
            return false;
        }
        //If there is an opponent in the destination tile and the tile is infront of the pawn to be moved
        if(m_board.getBoard()[destX][destY].getOwner().getId() == m_p2.getId() && destY == col)
        {
            cout << "Illigal move, you cannot kill this pawn." << endl;
            return false;
        }
        //if the destination tile holds a pawn that is on the players team
        else if(m_board.getBoard()[destX][destY].getOwner().getId() == m_p1.getId())
        {
            cout << "Illigal move, you already have a pawn there." << endl;
            return false;
        }

    }
    else
    {
        //if the player tries to move a pawn that is not his
        if(m_board.getBoard()[row][col].getOwner().getId() != m_p2.getId())
        {
            cout << "Illegal move, this is not your pawn." << endl;
            return false;
        }
        //if the destination tile is further than one tile away
        //and if the player tries to move the piece backwards or sideways
        if((destX - row) != -1  || (row <= destX))
        {
            cout << "Illegal move, you cannot go there." << endl;
            return false;
        }
        //If there is an opponent in the destination tile and the tile is infront of the pawn to be moved
        if(m_board.getBoard()[destX][destY].getOwner().getId() == m_p1.getId() && destY == col)
        {
            cout << "Illigal move, you cannot kill this pawn." << endl;
            return false;
        }
        //if the destination tile holds a pawn that is on the players team
        else if(m_board.getBoard()[destX][destY].getOwner().getId() == m_p2.getId())
        {
            cout << "Illigal move, you already have a pawn there." << endl;
            return false;
        }
        return true;
    }
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
        if(m_board.getBoard()[6][i].getOwner().getId() == m_p1.getId())
            return m_p1.getId();
    }
    return -1;
}

void Breakthrough::legal()
{
    /*pair<int,int> currentLocation = pair<int,int>(row,col);
    //int localY = currentLocation.first;
    //int localX = currentLocation.second;
    bool check = false;

    Player p;
    if(m_turns % 2 == 0)
    {
        p = m_p1;
    }

    if(p.getId() == 0)
    {
        cout << "Legal moves: " << '\n';
        for(int i = 0; i < 3; i++)
        {
            pair<int,int> dest(localY+1,((localX-1)+i));
            if(legalMove(row, col, dest))
            {
                check = true;
                cout << "(" << dest.first << "," << dest.second << ")" << '\n';
            }

        }

        if(!check)
        {
            cout << "There are no legal moves for this piece" << '\n';
        }


    }
    else if(p.getId() == 1)
    {
        cout << "Legal moves: " << '\n';
        for(int i = 0; i < 3; i++)
        {
            pair<int,int> dest(localY-1,((localX-1)+i));
            if(legalMove(row, col, dest))
            {
                check = true;
                cout << "(" << dest.first << "," << dest.second << ")" << '\n';
            }

        }

        if(!check)
        {
            cout << "There are no legal moves for this piece" << '\n';
        }
    }
    else
    {
        cout << "That's not a knife, that's a spoon." << '\n';
    }*/
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
