#include <iostream>
#include "game.h"
#include <stdlib.h>
#include <stack>
using namespace std;

GamePlay::GamePlay()
{
    m_p1 = Player();
    m_p2 = Player();
    m_p1.setId(0);
    m_p2.setId(1);
    m_p1.setType('.');
    m_p2.setType('.');
    m_turns = 0;
    m_difficulty = "random";
    m_win = false;
}

///Increases the number of turns by one
void GamePlay::incTurns()
{
    m_turns++;
}

///Destructor
GamePlay::~GamePlay() {}

///Returns the board
Board GamePlay::getBoard()
{
    return m_board;
}

///Outputs the list of games available to play
void GamePlay::listOfGames()
{
    for(unsigned int i = 0; i < sizeof(Game); ++i)
    {
        if(i == 0)
            cout << "Nr. 1: Breakthrough" ;
        if(i == 1)
            cout << "Nr. 2: Ataxx";
        cout << endl;
    }
}

int GamePlay::getNoPieces(Player player)
{
    return player.getNoPawns();
}

void GamePlay::retract()
{
    if (m_states.empty())
    {
        cout << "No previous state" << endl;
        return;
    }
    State previousState = m_states.top();
    m_turns--;
    m_p1 = previousState.p1;
    m_p2 = previousState.p2;
    m_board = previousState.b;
    m_states.pop();
}

void GamePlay::level(std::string difficulty)
{
    m_difficulty = difficulty;
}

int GamePlay::evaluate()
{
    if(m_turns % 2 == 0)
    {
        return m_p1.getNoPawns();
    }
    else
    {
        return m_p2.getNoPawns();
    }
}

///Quits the game play
void GamePlay::quit()
{
    cout << "Are you sure you want to quit the game? (y/n)" << endl;
    char ans;
    cin >> ans;
    if(ans == 'y' || ans == 'Y')
        exit(0);
    else return;
}

bool GamePlay::getWinState()
{
    return m_win;
}

string GamePlay::getDifficulty()
{
    return m_difficulty;
}

vector<Moves> GamePlay::getlegalMoves()
{
    return m_legalMoves;
}


