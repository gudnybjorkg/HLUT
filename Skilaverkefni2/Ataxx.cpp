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

///Sets up the board to start the game
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

///Checks if the move sent in is legal by following the rules given in the project
bool Ataxx::legalMove(int from_row,int from_col, int to_row, int to_col)
{
    
    ///out of bounds check
    if(from_row < 0 || from_row > 6)
        return false;
    if(from_col < 0 || from_col > 6)
        return false;
    if(to_row < 0 || to_row > 6)
        return false;
    if(to_col < 0 || to_col > 6)
        return false;

    ///Player turn check
    if(m_turns % 2 == 0)
{
        if(m_board.getBoard()[from_row][from_col].getType() != m_p1.getType())
            return false;
    }
    else
    {
        if(m_board.getBoard()[from_row][from_col].getType() != m_p2.getType())
            return false;
    }
    if (max(abs(from_col-to_col),(abs(from_row - to_row)))<= 2)  ///checks if the move is 2 blocks away
    {
        if (m_board.getBoard()[to_row][to_col].getType() == '.') /// if the tile is free
            return true;
    }
    return false;
}

//Converts a piece on the set row and column to the current players side
void Ataxx::convertPiece(int row, int col)
{
    if(m_turns % 2 == 0)
    {   /// if the player doesnt own the current pawn and the tile isn't empty
        if (m_p1.getType() != m_board.getBoard()[row][col].getType() && m_board.getBoard()[row][col].getType()!= '.') 
        {
            m_board.getBoard()[row][col].setOwner(m_p1);
            m_board.getBoard()[row][col] = m_p1.getType();
            m_p1.setNoPawns(m_p1.getNoPawns()+1);
            m_p2.setNoPawns(m_p2.getNoPawns()-1);
        }
    }
    else
    {   /// if the player doesnt own the current pawn and the tile isn't empty
        if (m_p2.getType() != m_board.getBoard()[row][col].getType() && m_board.getBoard()[row][col].getType() != '.') 
        {
            m_board.getBoard()[row][col].setOwner(m_p2);
            m_board.getBoard()[row][col] = m_p2.getType();
            m_p2.setNoPawns(m_p2.getNoPawns()+1);
            m_p1.setNoPawns(m_p1.getNoPawns()-1);
        }
    }
}

///Makes the move from a specific row/col to a specific row/col
void Ataxx::make(int from_row, int from_col, int to_row, int to_col)
{
    if (!legalMove(from_row,from_col,to_row, to_col))
    {
        cout << "Illegal move! Try again." << endl;
        return;
    }
    //State created to save the current state in order to be able to retract to it later
    State currentState;
    currentState.p1 = m_p1;
    currentState.p2 = m_p2;
    currentState.b = m_board;
    m_states.push(currentState);
    
    if(m_turns % 2 == 0)
    {
        m_p1.setLastLocation(from_row, from_col);
        m_p1.setNextLocation(to_row, to_col);
        Player playa = m_board.getBoard()[from_row][from_col].getOwner();
        ///checks if the   move is 1 block away, if so we clone the pawn
        if (max(abs(from_col - to_col), abs(from_row - to_row)) == 1)   
        {
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
    }
    else
    {
        m_p2.setLastLocation(from_row, from_col);
        m_p2.setNextLocation(to_row, to_col);
        Player playa = m_board.getBoard()[from_row][from_col].getOwner();
        ///checks if the move is 1 block away, if so we clone the pawn
        if (max(abs(from_col - to_col), abs(from_row - to_row)) == 1)   
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
    }

    ///convert all the pawns around the pawn
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0 ; j < 7; j++)
        {
            if (max(abs(to_row - i), abs(to_col - j)) == 1)
            {
                convertPiece(i, j);
            }
        }
    }

    if(finalState())
    {
        if(m_p1.getNoPawns() > m_p2.getNoPawns())
        {
            cout << "Player 1 wins!" << endl;
            m_win = true;
        }
        else if(m_p2.getNoPawns() > m_p1.getNoPawns())
        {
            cout << "Player 2 wins!" << endl;
            m_win = true;
        }
        else
        {
            cout << "There was a tie." << endl;
            m_win = true;
        }
    }
    m_turns++;
    cout << "move " << from_row << " " << from_col << " " << to_row << " " << to_col << endl;
}

///Gets all legal moves for the player
void Ataxx::setLegalMoves()
{
    m_legalMoves.clear();

    Piece** p = m_board.getBoard();
    
    ///We iterate through the board until we find our pawn and then check the rest of the board and see
    ///if its legal to move there, if so we push that move to the legalMoves vector
    if(m_turns % 2 == 0)
    {
        for(int i = 0; i < 7; ++i)
        {
            for(int j = 0; j < 7; ++j)
            {
                if(p[i][j].getType() == m_p1.getType())
                {
                    for(int k = (i-2); k < ((i-2)+5); k++)
                    {
                        for(int l = (j-2); l < ((j-2)+5); l++)
                        {
                            if(legalMove(i,j,k,l))
                                m_legalMoves.push_back(Moves(i,j,k,l));
                        }
                    }
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < 7; ++i)
        {
            for(int j = 0; j < 7; ++j)
            {
                if(p[i][j].getType() == m_p2.getType())
                {
                    for(int k = (i-2); k < ((i-2)+5); ++k)
                    {
                        for(int l = (j-2); l < ((j-2)+5); ++l)
                        {
                            if(legalMove(i,j,k,l))
                                m_legalMoves.push_back(Moves(i,j,k,l));
                        }
                    }
                }
            }
        }
    }
}

///Checks whether the board is full to see if the game is over
bool Ataxx::finalState()
{
    for(int i = 0; i < 7; ++i)
    {
        for(int j = 0; j < 7; ++j)
            if(m_board.getBoard()[i][j].getType() == '.')
                return false;
    }
    return true;
}
///A display function for the board
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
