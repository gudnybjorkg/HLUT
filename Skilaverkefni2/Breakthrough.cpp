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

void Breakthrough::make(int from_col, int from_row, int to_col, int to_row)
{
    if(!legalMove(m_board.getBoard()[from_row][from_col],pair<int,int>(to_row,to_col)))
    {
        cout << "This is not a legal move, please try again." << endl;
        return;
    }
    //Finding the player which turn it is
    Player p;
    if(m_turns % 2 == 0)
    {
        p = m_p1;
    }
    else
    {
        p = m_p2;
    }
    //Sets the locations to be moved to.
    p.setLastLocation(from_row,from_col);
    p.setNextLocation(to_row, to_col);
}

void Breakthrough::go()
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
    //The locations
    int to_row = p.getNextLocation().first;
    int to_col = p.getNextLocation().second;
    int from_row = p.getPrevLocation().first;
    int from_col = p.getPrevLocation().second;

    if(to_row == from_row && to_col == from_col)
        cout << "You are already there, please make a move." << endl;

    //if there is a pawn in the tile that is being mobed to, then incrementing the number of pawns for the opponent
    if(m_board.getBoard()[to_row][to_col].getType() != '.')
    {
        opponent.incPawns();
        opponent.setkilled(true);
    }
    //Moves the piece to it's next location
    m_board.getBoard()[to_row][to_col].setOwner(p);
    m_board.getBoard()[to_row][to_col] = m_board.getBoard()[from_row][from_col].getType();
    m_board.getBoard()[from_row][from_col].setOwner(opponent);
    m_board.getBoard()[from_row][from_col] = '.';

    m_turns++;

    cout << "move " << from_col	<< " " << from_row << " " << to_col << " " << to_row << endl;
}

void Breakthrough::retract(Player player)
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

    //retrieveing the last move made from the opponent
    if(opponent.getKilled())
    {
        //Putting the old fellow back
        m_board.getBoard()[nextOp.first][nextOp.second] = p.getType();
        m_board.getBoard()[nextOp.first][nextOp.second].setOwner(p);
        opponent.setkilled(false);
        //Move the opponent back to it's old location
        m_board.getBoard()[prevOp.first][prevOp.second].setOwner(opponent);
        m_board.getBoard()[prevOp.first][prevOp.second] = opponent.getType();
    }
    else
    {
        //Move the opponent back to it's old location
        m_board.getBoard()[prevOp.first][prevOp.second].setOwner(opponent);
        m_board.getBoard()[prevOp.first][prevOp.second] = m_board.getBoard()[nextOp.first][nextOp.second];
        //The next move for the opponent is undetermined
        m_board.getBoard()[nextOp.first][nextOp.second].setOwner(Player());
        m_board.getBoard()[nextOp.first][nextOp.second].setLocation(nextOp.first, nextOp.second);
        m_board.getBoard()[nextOp.first][nextOp.second] = '.';

        //Move the player back to it's old location
        m_board.getBoard()[prevP.first][prevP.second].setOwner(p);
        m_board.getBoard()[prevP.first][prevP.second] = p.getType();
        //The new location is unoccupied
        m_board.getBoard()[nextP.first][nextP.second].setOwner(Player());
        m_board.getBoard()[nextP.first][nextP.second] = '.';
    }
    //Returning the nextLocation to it's old state for both players.
    opponent.setNextLocation(prevOp.first, prevOp.second);
    p.setNextLocation(prevP.first, prevP.second);

    m_turns--;
}

void Breakthrough::start()
{
    for(int i = 0; i < 8; ++i)
    {
        cout << i+1 << " tilraun byrjar" << '\n';
        Piece **temp = m_board.getBoard();
        cout << temp[0][0].getType();
        //Player 1
        (temp[0][i]).setOwner(m_p1);
        cout << "Test 1" << endl;
        m_board.getBoard()[0][i] = m_p1.getType();
        cout << "Test 2" << endl;
        m_board.getBoard()[1][i].setOwner(m_p1);
        m_board.getBoard()[1][i] = m_p1.getType();
        cout << i+1 << " tilraun midja" << '\n';
        //Player 2
        m_board.getBoard()[6][i].setOwner(m_p2);
        m_board.getBoard()[6][i] = m_p2.getType();
        m_board.getBoard()[7][i].setOwner(m_p2);
        m_board.getBoard()[7][i] = m_p2.getType();
        cout << i+1 << " endar" << '\n';
    }
}
bool Breakthrough::legalMove(Piece p, pair<int, int> destination)
{
    pair<int,int> currentLocation = p.getLocation();
    int localY = currentLocation.first;
    int localX = currentLocation.second;
    int destY = destination.first;
    int destX = destination.second;
    Piece** the_pieces = m_board.getBoard();
    Piece destPiece = the_pieces[destY][destX];

    Player player;
    Player opponent;
    if(m_turns % 2 == 0)
    {
        player = m_p1;
        opponent = m_p2;
    }
    else
    {
        player = m_p2;
        opponent = m_p1;
    }

    if(p.getOwner().getId() == m_p1.getId() && p.getOwner().getId() == player.getId())
    {
        if((destY - localY) != 1)
        {
            return false;
        }

        if(destX < localX)
        {
            if((localX - destX) != 1)
            {
                return false;
            }
            if(destPiece.getOwner().getId() == p.getOwner().getId())
            {
                return false;
            }
            return true;
        }
        else if(destX > localX)
        {
            if((destX - localX) != 1)
            {
                return false;
            }
            if(destPiece.getOwner().getId() == p.getOwner().getId())
            {
                return false;
            }
            return true;
        }
        else
        {
            if((destX - localX) != 0)
            {
                return false;
            }
            if(destPiece.getType() != '.')
            {
                return false;
            }
            return true;
        }


    }
    else if(p.getOwner().getId() == m_p2.getId() && p.getOwner().getId() == player.getId())
    {
        if((localY - destY) != 1)
        {
            return false;
        }

        if(destX < localX)
        {
            if((localX - destX) != 1)
            {
                return false;
            }
            if(destPiece.getOwner().getId() == p.getOwner().getId())
            {
                return false;
            }
            return true;
        }
        else if(destX > localX)
        {
            if((destX - localX) != 1)
            {
                return false;
            }
            if(destPiece.getOwner().getId() == p.getOwner().getId())
            {
                return false;
            }
            return true;
        }
        else
        {
            if((destX - localX) != 0)
            {
                return false;
            }
            if(destPiece.getType() != '.')
            {
                return false;
            }
            return true;
        }


    }
    return false;
}

void Breakthrough::legal(Piece piece)
{
    pair<int,int> currentLocation = piece.getLocation();
    int localY = currentLocation.first;
    int localX = currentLocation.second;
    bool check = false;

    if((piece.getOwner()).getId() == 0)
    {
        cout << "Legal moves: " << '\n';
        for(int i = 0; i < 3; i++)
        {
            pair<int,int> dest(localY+1,((localX-1)+i));
            if(legalMove(piece,dest))
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
    else if((piece.getOwner()).getId() == 1)
    {
        cout << "Legal moves: " << '\n';
        for(int i = 0; i < 3; i++)
        {
            pair<int,int> dest(localY-1,((localX-1)+i));
            if(legalMove(piece,dest))
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
    //Piece** p = m_board.getBoard();

    cout << "                              " << '\n';
    cout << "     0  1  2  3  4  5  6  7   " << '\n';
    cout << "    _________________________________  " <<'\n';

    for(int i = 0; i < 8; i++)
    {
        cout << "    |   |   |   |   |   |   |   |   |  " << '\n';
        cout << "    |";

        for(int j = 0; j < 8; j++)
        {
            cout << " " << m_board.getBoard()[i][j].getType() << " |";
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
