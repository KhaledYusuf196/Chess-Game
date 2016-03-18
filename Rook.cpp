#include "Rook.h"
#include"Map.h"
#include  "Pieces.h"
#include <iostream>
using namespace std;
Rook::Rook()
{

}
Rook::Rook(string name,int pos)
{
    pieceName=name;
    piecePosition=pos;
}

bool Rook::Move(int to,Map x)
{
    int io,jo,in,jn;
    io=piecePosition/10;
    jo=piecePosition%10;
    in=to/10;
    jn=to%10;
    if(in-io==0 || jn-jo==0)
    {
        while(in-1>io)
        {
            io++;
            if(x.getpos(io,jo)!="       ")
            {
                return 0;
            }
        }
        while(in+1<io)
        {
            io--;
            if(x.getpos(io,jo)!="       ")
            {
                return 0;
            }
        }
        while(jn-1>jo)
        {
            jo++;
            if(x.getpos(io,jo)!="       ")
            {
                return 0;
            }
        }
        while(jn+1<jo)
        {
            jo--;
            if(x.getpos(io,jo)!="       ")
            {
                return 0;
            }
        }


        return 1;
    }
    return 0;

}
