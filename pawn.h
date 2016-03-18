#ifndef PAWN_H
#define PAWN_H
#include "Pieces.h"
#include "Map.h"
#include <iostream>
using namespace std;





class pawn : public Pieces
{
    public:
        pawn();
        bool Move(int to,Map m);
        pawn(string name, int pos,int turn);
    private:
        int turn;

};


#endif // PAWN_H
