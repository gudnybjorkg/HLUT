#include <iostream>
#include <cstring>
#include <sstream>
#include <istream>
#include <ostream>
#include <cfloat>
#include "stdlib.h"
#include <time.h>
#include <iterator>
#include "game.h"
#include "Breakthrough.h"
#include "Ataxx.h"

using namespace std;

void commands();

/**
The computer plays for the player to move using the current difficulty level
and outputs the move it made as <from_col, from_row, to_col, to_row>
Displays the winner if a winnig state has been reached
*/
void go(GamePlay* game);

int mm(GamePlay* game, int depth, Moves* m );

int main()
{
    srand(time(NULL));
    GamePlay *game;
    int gameNr = 0;
    string line, command;
    bool start = false;
    cout << "Please type in a command from the list below" << endl;
    cout << "1.list - List of available games" << endl;
    cout << "2.game - Type in 'game' followed by the number of the game(seperate with space)" << endl;
    cout << "3.start - Once a game is selected, type start to play the game" << endl;
    cout << endl;
    do
    {
        getline(cin,line);
        stringstream ss(line);

        ss >> command;
        ss >> gameNr;

        if(gameNr > 2)
        {
            gameNr = 0;
        }

        if(command == "list")
        {
            game->listOfGames();
        }
        else if(command == "start")
        {
            if(gameNr == 1)
            {
                game->start();
                start = true;
            }
            else if(gameNr == 2)
            {
                game->start();
                start = true;
            }
            else
            {
                cout << "Please select a valid game using the game command." << '\n';
                cout << endl;
            }
        }
        else if(command == "game")
        {
            if(gameNr == 1)
            {
                cout << "-------------------------------------------------------" << endl;
                cout << "You have chosen Breakthough, go team!" << endl;
                cout << "Enter start when ever you are ready" << endl;
                cout << "-------------------------------------------------------" << endl;
                game = new Breakthrough();

            }
            else if(gameNr == 2)
            {
                cout << "-------------------------------------------------------" << endl;
                cout << "You have chosen Ataxx, go team!" << endl;
                cout << "Enter start when ever you are ready" << endl;
                cout << "-------------------------------------------------------" << endl;
                game = new Ataxx();
            }
            else
            {
                cout << "Please select a valid game. Use the 'list' command to view the available game." << '\n';
            }
        }
        else
        {
            cout << "Invalid input, please try again." << '\n';
        }

    }
    while(!start);

    cout << "Let the games begin!" << endl;
    cout << "-------------------------------------------------------" << endl;
    commands();

    int fromRow, fromCol, toRow, toCol;
    string level;

    do
    {
        getline(cin,line);
        stringstream ss(line);

        ss >> command;
        ss >> level;
        ss >> fromCol;
        ss >> toRow;
        ss >> toCol;

        if(command == "legal")
        {
            cout << "All legal moves: " << endl;
            //forlúppa í gegnum m_legalMoves gaurinn og skrifa hann út
            game->setLegalMoves();
            for(vector<Moves>::iterator it = game->getlegalMoves().begin(); it != game->getlegalMoves().end(); ++it){
                cout << "from: [" << it->from_row << "," << it->from_col << "] to: [" << it->to_row << "," << it->to_col << "]" << endl;
            }
            cout << endl;
        }
        else if(command == "make")
        {
            fromRow = atoi(level.c_str());

            game->make(fromRow, fromCol, toRow, toCol);
        }
        else if(command == "retract")
        {
            game->retract();
        }
        else if(command == "display")
        {
            game->display();
        }
        else if(command == "evaluate")
        {
            game->evaluate();
        }
        else if(command == "go")
        {
            go(game);
        }
        else if(command == "level")
        {
            game->level(level);
        }
        else if(command == "quit")
        {
            cout << "Dave, stop. Stop will you? Stop, Dave.";
            exit(0);
        }
        else if(command == "commands")
        {
            commands();
        }
        else
        {
            cout << "Invalid input, please try again." << endl;
        }
    }
    while(!game->getWinState());

}

void commands()
{
    cout << "The available commands are as follows:" << endl;
    cout << "1.legal - Lists all the legal moves for the current game state" << endl;
    cout << "2.make - type in the move you want to make byr inputting the row and column you want to move from"
         << "followed by the row and column you want to move to" << endl;
    cout << "3.retract - Retracts the last move played" << endl;
    cout << "4.display - Displays the current state of the game board" << endl;
    cout << "5.evaluate - Display the evaluation value of the current board state for the current difficulty level" << endl;
    cout << "6.go - The computer plays for the side-to-move using the current difficulty level." << endl;
    cout << "7.level - Type in level followed by random, easy, normal or hard to set the difficulty level." << endl;
    cout << "8.debug - Toggle debug mode on or off." << endl;
    cout << "9.quit - Quit the program." << endl << endl;
    cout << "10.commands - Display this list of commands" << endl;
}

void go(GamePlay* game){
    game->setLegalMoves();
    if(game->getlegalMoves().empty())
        game->incTurns();

    string difficulty = game->getDifficulty();
    if(difficulty == "random"){
        int rmove = rand() % game->getlegalMoves().size();
        Moves m = game->getlegalMoves()[rmove];
        game->make(m.from_row, m.from_col, m.to_row, m.to_col);
    }
    else if(difficulty == "easy"){
        Moves* m = NULL;
        mm(game, 1, m);
        game->make(m->from_row, m->from_col, m->to_row, m->to_col);
    }
    else if(difficulty == "medium"){
        Moves* m = NULL;
        mm(game, 3, m);
        game->make(m->from_row, m->from_col, m->to_row, m->to_col);
    }
    else if(difficulty == "hard"){

    }
}

int mm(GamePlay* game, int depth, Moves* m ){
    cout << "begin" << endl;
    int bestValue = -3000;
    int value = game->evaluate();
    if(depth <= 0)
        return game->evaluate();
    if(game->getWinState())
        return bestValue;
    game->setLegalMoves();
    cout << "after set legal moves" << endl;
    for(vector<Moves>::iterator it = game->getlegalMoves().begin(); it != game->getlegalMoves().end(); ++it){
        game->make(it->from_row, it->from_col, it->to_row, it->to_col);
        value = -mm(game, depth-1, NULL);
        cout << "before retract" << endl;
        game->retract();
        if(value > bestValue){
            bestValue = value;
            if(m != NULL)
                *m = *it;
        }
    }
}

