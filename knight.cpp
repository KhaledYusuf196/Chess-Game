#include "knight.h"
#include "Pieces.h"
#include <cmath>

knight::knight()
{

}


knight::knight(string name ,int pos)
{

    pieceName=name;
    piecePosition=pos;
}

bool knight::Move(int to,Map m)
{
    int io,jo,in,jn;
    io=piecePosition/10;
    jo=piecePosition%10;
    in=to/10;
    jn=to%10;
    if(pow(io-in,2)+pow(jo-jn,2)==5)
    {
        return true;
    }
    return false;
}
