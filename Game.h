#ifndef GAME_H
#define GAME_H
#include "Pieces.h"
#include "knight.h"
#include "king.h"
#include "Rook.h"
#include "Bishop.h"
#include "pawn.h"
#include "Queen.h"
#include "Map.h"



class Game
{

public:
    Game();
    ~Game();
    Game(const Game& g);  //copy constructor
    Game&operator=(const Game& g)
    {
        m=g.m;
        piece=g.piece;
        return *this;
    }

    void write(int n,int z,int t);
    void start();
    void load();
    void restart();
    bool WinOrLose(int t,int z);
    bool detected(int t);
    void revert(int ,string ,int);
private:
    Map m;
    Pieces **piece;
};

#endif // GAME_H
