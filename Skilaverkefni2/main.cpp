#include <iostream>
#include <cstring>
#include <sstream>
#include <istream>
#include <ostream>
#include "stdlib.h"
#include <iterator>
#include "game.h"
#include "Breakthrough.h"
#include "Ataxx.h"

using namespace std;

void commands();

int main()
{
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
            game->legal();
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
            game->go();
        }
        else if(command == "level")
        {
            game->level(level);
        }
        else if(command == "debug")
        {
            game->debug();
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




/*
#include <iostream>
#include "game.h"
#include "Breakthrough.h"
#include "Ataxx.h"

using namespace std;

int main()
{
    GamePlay *game;
    int gameNr;
    cout << "Please select the number of the game from the list below" << endl;
    game->listOfGames();
    cin >> gameNr;
    if(gameNr == 1)
        game = new Breakthrough();
    else if(gameNr == 2)
        game = new Ataxx();
    else
        cout << "Invalid game, please try again" << endl;
    game->start();
    game->display();
    //game->legal();

    int from_row;
    int to_row;
    int from_col;
    int to_col;
    char bla;
    char go;
    do
    {
        cout << "enter a movement: (from row, from col, to row, to col)";
        cin  >> from_row;
        cin >> from_col;
        cin >> to_row;
        cin >> to_col;
        //game->legal();
        game->make(from_row, from_col, to_row, to_col);
        game->display();
        cout << "Retract? ";
        cin >> bla;
        if(bla == 'y' || bla == 'Y'){
            game->retract();
            continue;
        }
        cout << "Go? ";
        cin >> go;
        if(go == 'y' || go == 'Y')
            game->go();
    }while(true);
}
*/
