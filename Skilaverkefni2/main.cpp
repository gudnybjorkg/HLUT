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

    int from_row;
    int to_row;
    int from_col;
    int to_col;
    do
    {
        cout << "enter a movement: (from row, from col, to row, to col)";
        cin  >> from_row;
        cin >> from_col;
        cin >> to_row;
        cin >> to_col;
        game->legal();
        game->make(from_row, from_col, to_row, to_col);

        game->display();
    }
    while(true);
}
