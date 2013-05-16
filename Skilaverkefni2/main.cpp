#include <iostream>
#include "game.h"
#include "Breakthrough.h"
#include "Ataxx.h"

using namespace std;

int main()
{
    GamePlay *game;
    int gameNr;
    do
    {
        cout << "Please select the number of the game from the list below" << endl;
        game->listOfGames();
        cin >> gameNr;
        if(gameNr == 1)
            game = new Breakthrough();
        else if(gameNr == 2)
            game = new Ataxx();
        else
            cout << "Invalid game, please try again" << endl;
    }
    while(gameNr != 1);
    game->start();
    game->display();
}
