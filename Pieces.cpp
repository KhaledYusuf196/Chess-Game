#include "Pieces.h"
#include "Map.h"

#include <iostream>

using namespace std;

Pieces::Pieces()
{
    isdead=false;
}

void Pieces::setdeath()
{
    isdead=!isdead;
}

int Pieces::getdeath()
{
    return isdead;
}

Pieces::Pieces(string n,int pos)
{
    pieceName=n;
    piecePosition=pos;
}

string Pieces::getpieceName() const
{
    return pieceName;
}

int Pieces::getposition() const
{
    return piecePosition;
}

void Pieces::setposition(int p)
{
    piecePosition=p;

}

void Pieces::setname(string n)
{
    pieceName=n;
}
bool Pieces::checkpiece(int o)
{
    if(o==piecePosition)return 1;
    return 0;
}
