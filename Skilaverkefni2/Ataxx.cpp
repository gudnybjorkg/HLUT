#include "Ataxx.h"
#include <cmath>
#include <algorithm>
using namespace std;

Ataxx::Ataxx() : GamePlay()
{
    m_board = Board(7,7);
    m_p1.setType('X');
    m_p1.setNoPawns(2);
    m_p2.setType('O');
    m_p2.setNoPawns(2);
}

void Ataxx::start()
{

    m_board.getBoard()[0][0].setOwner(m_p2);
    m_board.getBoard()[0][0] = m_p2.getType();
    m_board.getBoard()[0][6].setOwner(m_p1);
    m_board.getBoard()[0][6] = m_p1.getType();
    m_board.getBoard()[6][0].setOwner(m_p1);
    m_board.getBoard()[6][0] = m_p1.getType();
    m_board.getBoard()[6][6].setOwner(m_p2);
    m_board.getBoard()[6][6] = m_p2.getType();
}

bool Ataxx::legalMove(int from_row,int from_col, std::pair<int, int> destination)
{
    int to_row = destination.first;
    int to_col = destination.second;
    if(m_turns % 2 == 0)
    {
        if(m_board.getBoard()[from_row][from_col].getOwner().getId() == m_p2.getId())
        {
            cout << "Illegal move, this is not your pawn!" << endl;
            return false;
        }
    }
    else
    {
        if(m_board.getBoard()[from_row][from_col].getOwner().getId() == m_p1.getId())
        {
            cout << "Illegal move, this is not your pawn!" << endl;
            return false;
        }
    }
    if (max(abs(from_col-to_col),(abs(from_row - to_row)))<= 2)  ///checks if the move is 2 blocks away
    {
        if (m_board.getBoard()[to_row][to_col].getType() == '.') /// if the tile is free
        {
            return true;
        }
        else
        {
            cout << "Illegal move, this tile is occupado!" << endl;
        }
    }
    cout << "Illegal move, you cannot go there" << endl;
    return false;
}

void Ataxx::convertPiece(int row, int col, Player p, Player opp)
{
    if(m_turns % 2 == 0)
    {
        if (m_p1.getId() != m_board.getBoard()[row][col].getOwner().getId() && m_board.getBoard()[row][col].getOwner().getId() != -1) /// if the player doesnt own the current pawn and the tile isn't empty
        {
            m_board.getBoard()[row][col].setOwner(m_p1);
            m_board.getBoard()[row][col] = m_p1.getType();
            m_p1.setNoPawns(m_p1.getNoPawns()+1);
            m_p2.setNoPawns(m_p2.getNoPawns()-1);  ///win state hér ef opp á 0
        }
    }
    else
    {
        if (m_p2.getId() != m_board.getBoard()[row][col].getOwner().getId() && m_board.getBoard()[row][col].getOwner().getId() != -1) /// if the player doesnt own the current pawn and the tile isn't empty
        {
            m_board.getBoard()[row][col].setOwner(m_p2);
            m_board.getBoard()[row][col] = m_p2.getType();
            m_p2.setNoPawns(m_p2.getNoPawns()+1);
            m_p1.setNoPawns(m_p1.getNoPawns()-1);  ///win state hér ef opp á 0
        }
    }
}

void Ataxx::make(int from_row, int from_col, int to_row, int to_col)
{
    if (!legalMove(from_row,from_col,pair<int,int>(to_row,to_col)))
        return;

    State currentState;
    currentState.p1 = m_p1;
    currentState.p2 = m_p2;
    currentState.b = m_board;
    //currentState.turns = m_turns;
    m_states.push(currentState);

    if(m_turns % 2 == 0)
    {
        m_p1.setLastLocation(from_row, from_col);
        m_p1.setNextLocation(to_row, to_col);
    }
    else
    {
        m_p2.setLastLocation(from_row, from_col);
        m_p2.setNextLocation(to_row, to_col);
    }
    go();
}

void Ataxx::go()
{
    if (m_turns %2 == 0)
    {
        std::pair<int, int> to = m_p1.getNextLocation();
        std::pair<int, int> from = m_p1.getPrevLocation();
        cout << "Player 1 from: " << m_p1.getPrevLocation().first << " " << m_p1.getPrevLocation().second << endl;
        cout << "Player 1 to: " << m_p1.getNextLocation().first << " " << m_p2.getNextLocation().second << endl;
        int from_row = from.first;
        int from_col = from.second;
        int to_row = to.first;
        int to_col = to.second;
        Player playa = m_board.getBoard()[from_row][from_col].getOwner();

        if (max(abs(from_col - to_col), abs(from_row - to_row)) == 1)  ///checks if the   move is 1 block away
        {
            //m_board.setPieceOnBoard(to_row, to_col, playa); ///no need to remove pawn since we are cloning
            m_board.getBoard()[to_row][to_col].setOwner(m_p1);
            m_board.getBoard()[to_row][to_col] = m_p1.getType();
            m_p1.setNoPawns(m_p1.getNoPawns()+1);
        }
        else /// the move must be 2 blocks away since its legal and not 1 block away
        {
            m_board.getBoard()[to_row][to_col].setOwner(m_p1);
            m_board.getBoard()[to_row][to_col] = m_p1.getType();

            m_board.getBoard()[from_row][from_col].setOwner(Player());
            m_board.getBoard()[from_row][from_col] = '.';
        }


        ///convert all the pawns around the pawn
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0 ; j < 7; j++)
            {
                if (max(abs(to_row - i), abs(to_col - j)) == 1)
                {
                    convertPiece(i, j, m_p1, m_p2);
                }
            }
        }
        if(finalState())
        {
            if(m_p1.getNoPawns() < m_p2.getNoPawns())
                cout << "Player 2 wins!" << endl;
            if(m_p1.getNoPawns() > m_p2.getNoPawns())
                cout << "Player 1 wins!" << endl;
            else
                cout << "There was a tie" << endl;
        }
    }
    else
    {
        std::pair<int, int> to = m_p2.getNextLocation();
        std::pair<int, int> from = m_p2.getPrevLocation();
        int from_row = from.first;
        int from_col = from.second;
        int to_row = to.first;
        int to_col = to.second;
        Player playa = m_board.getBoard()[from_row][from_col].getOwner();

        if (max(abs(from_col - to_col), abs(from_row - to_row)) == 1)  ///checks if the   move is 1 block away
        {
            m_board.getBoard()[to_row][to_col].setOwner(m_p2);
            m_board.getBoard()[to_row][to_col] = m_p2.getType();
            m_p2.setNoPawns(m_p2.getNoPawns()+1);
        }
        else /// the move must be 2 blocks away since its legal and not 1 block away
        {
            m_board.getBoard()[to_row][to_col].setOwner(m_p2);
            m_board.getBoard()[to_row][to_col] = m_p2.getType();

            m_board.getBoard()[from_row][from_col].setOwner(Player());
            m_board.getBoard()[from_row][from_col] = '.';
        }


        ///convert all the pawns around the pawn
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0 ; j < 7; j++)
            {
                if (max(abs(to_row - i), abs(to_col - j)) == 1)
                {
                    convertPiece(i, j, m_p2, m_p1);
                }
            }
        }
    }
    //m_turns++;
}

bool Ataxx::finalState()
{
    for(int i = 0; i < 7; ++i)
    {
        for(int j = 0; j < 7; ++j)
            if(m_board.getBoard()[i][j].getOwner().getId() == -1)
                return false;
    }
    return true;
}

void Ataxx::display()
{
    Piece** p = m_board.getBoard();

    cout << "                              " << '\n';
    cout << "      0   1   2   3   4   5   6  " << '\n';
    cout << "    ____________________________ " <<'\n';

    for(int i = 0; i < 7; i++)
    {
        cout << "    |   |   |   |   |   |   |   | " << '\n';
        cout << " " << i <<"  |";

        for(int j = 0; j < 7; j++)
        {
            cout << " " << p[i][j].getType() << " |";
        }
        cout << '\n';
        cout << "    |   |   |   |   |   |   |   | " << '\n';
        cout << "    _____________________________ " <<'\n';

    }
    cout << "Player: " << (m_turns % 2) << endl;
    cout << "Player 1 has " << m_p1.getNoPawns() << " pawns." << endl;
    cout << "Player 2 has " << m_p2.getNoPawns() << " pawns." << endl;
}
