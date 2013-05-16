#include "Breakthrough.h"
#include <utility>
#include <algorithm>
using namespace std;

Breakthrough::Breakthrough() : GamePlay()
{
    m_board = Board(8,8);
    m_p1.setType('p');
    m_p1.setNoPawns(16);
    m_p2.setType('P');
    m_p2.setNoPawns(16);

}

void Breakthrough::make(int from_row, int from_col, int to_row, int to_col)
{

    if(!legalMove(from_row, from_col, pair<int,int>(to_row,to_col)))
    {
        //cout << "This is not a legal move, please try again." << endl;
        return;
    }
    //Finding the player which turn it is
    Player p;
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
}

void Breakthrough::retract(Player player)
{
    Player p;
    Player opponent;
    //Finding the correct player to move
    if(m_turns % 2 == 0)
    {
        pair<int,int> prevOp = m_p2.getPrevLocation();
        pair<int,int> nextOp = m_p2.getNextLocation();
        pair<int,int> prevP = m_p1.getPrevLocation();
        pair<int,int> nextP = m_p1.getNextLocation();

        //retrieveing the last move made from the opponent
        if(opponent.getKilled())
        {
            //Putting the old fellow back
            m_board.getBoard()[nextOp.first][nextOp.second] = m_p1.getType();
            m_board.getBoard()[nextOp.first][nextOp.second].setOwner(m_p1);
            opponent.setkilled(false);
            //Move the opponent back to it's old location
            m_board.getBoard()[prevOp.first][prevOp.second].setOwner(m_p2);
            m_board.getBoard()[prevOp.first][prevOp.second] = m_p2.getType();
        }
        else
        {
            //Move the opponent back to it's old location
            m_board.getBoard()[prevOp.first][prevOp.second].setOwner(m_p2);
            m_board.getBoard()[prevOp.first][prevOp.second] = m_board.getBoard()[nextOp.first][nextOp.second];
            //The next move for the opponent is undetermined
            m_board.getBoard()[nextOp.first][nextOp.second].setOwner(Player());
            m_board.getBoard()[nextOp.first][nextOp.second].setLocation(nextOp.first, nextOp.second);
            m_board.getBoard()[nextOp.first][nextOp.second] = '.';

            //Move the player back to it's old location
            m_board.getBoard()[prevP.first][prevP.second].setOwner(m_p1);
            m_board.getBoard()[prevP.first][prevP.second] = m_p1.getType();
            //The new location is unoccupied
            m_board.getBoard()[nextP.first][nextP.second].setOwner(Player());
            m_board.getBoard()[nextP.first][nextP.second] = '.';
        }
        //Returning the nextLocation to it's old state for both players.
        m_p2.setNextLocation(prevOp.first, prevOp.second);
        m_p1.setNextLocation(prevP.first, prevP.second);
    }
    else{

        pair<int,int> prevOp = m_p1.getPrevLocation();
        pair<int,int> nextOp = m_p1.getNextLocation();
        pair<int,int> prevP = m_p2.getPrevLocation();
        pair<int,int> nextP = m_p2.getNextLocation();

        //retrieveing the last move made from the opponent
        if(m_p1.getKilled())
        {
            //Putting the old fellow back
            m_board.getBoard()[nextOp.first][nextOp.second] = m_p2.getType();
            m_board.getBoard()[nextOp.first][nextOp.second].setOwner(m_p2);
            opponent.setkilled(false);
            //Move the opponent back to it's old location
            m_board.getBoard()[prevOp.first][prevOp.second].setOwner(m_p1);
            m_board.getBoard()[prevOp.first][prevOp.second] = m_p1.getType();
        }
        else
        {
            //Move the opponent back to it's old location
            m_board.getBoard()[prevOp.first][prevOp.second].setOwner(m_p1);
            m_board.getBoard()[prevOp.first][prevOp.second] = m_board.getBoard()[nextOp.first][nextOp.second];
            //The next move for the opponent is undetermined
            m_board.getBoard()[nextOp.first][nextOp.second].setOwner(Player());
            m_board.getBoard()[nextOp.first][nextOp.second].setLocation(nextOp.first, nextOp.second);
            m_board.getBoard()[nextOp.first][nextOp.second] = '.';

            //Move the player back to it's old location
            m_board.getBoard()[prevP.first][prevP.second].setOwner(m_p2);
            m_board.getBoard()[prevP.first][prevP.second] = m_p2.getType();
            //The new location is unoccupied
            m_board.getBoard()[nextP.first][nextP.second].setOwner(Player());
            m_board.getBoard()[nextP.first][nextP.second] = '.';
        }
        //Returning the nextLocation to it's old state for both players.
        m_p1.setNextLocation(prevOp.first, prevOp.second);
        m_p2.setNextLocation(prevP.first, prevP.second);
    }
    m_turns--;
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

void Breakthrough::legal(int row, int col)
{
    pair<int,int> currentLocation = pair<int,int>(row,col);
    int localY = currentLocation.first;
    int localX = currentLocation.second;
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

}

Breakthrough::~Breakthrough()
{
    //dtor
}
