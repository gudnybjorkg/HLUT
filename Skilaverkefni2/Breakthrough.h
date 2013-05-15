#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H
#include "game.h"

class Breakthrough : GamePlay
{
    public:
        Breakthrough();
        virtual bool legalMove(Piece p, std::pair<int, int> destination);
        virtual ~Breakthrough();
    protected:
    private:
};

#endif // BREAKTHROUGH_H
