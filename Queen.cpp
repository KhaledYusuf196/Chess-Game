#include "Queen.h"
#include "Map.h"
#include "Pieces.h"
#include <iostream>
using namespace std;
Queen::Queen()
{

}
Queen::Queen(string name,int pos)
{
    pieceName=name;
    piecePosition=pos;
}

bool Queen::Move(int to,Map x)
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
            if(x.getpos(io,jo)!="       "){
                return 0;
            }
        }
        while(in+1<io)
        {
            io--;
            if(x.getpos(io,jo)!="       "){
                return 0;
            }
        }
        while(jn-1>jo)
        {
            jo++;
            if(x.getpos(io,jo)!="       "){
                return 0;
            }
        }
        while(jn+1<jo)
        {
            jo--;
            if(x.getpos(io,jo)!="       "){
                return 0;
            }
        }
        return 1;
    }
    if(((in-io)*(in-io))==((jn-jo)*(jn-jo)))
    {
        while(in+1<io&&jn-1>jo){
            io--;
            jo++;
            if(x.getpos(io,jo)!="       "){
                return 0;
        }
        }
        while(in+1<io&&jn+1<jo){
            io--;
            jo--;
            if(x.getpos(io,jo)!="       "){
                return 0;
        }
        }
        while(in-1>io&&jn-1>jo){
            io++;
            jo++;
            if(x.getpos(io,jo)!="       "){
                return 0;
        }
        }
        while(in-1>io&&jn+1<jo){
            io++;
            jo--;
            if(x.getpos(io,jo)!="       "){
                return 0;
        }
    }
    return 1;
    }
    return 0;

}
