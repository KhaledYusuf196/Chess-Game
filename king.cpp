#include "king.h"

#include <cmath>
#include "Map.h"
#include "Pieces.h"
#include <iostream>
using namespace std;
king::king()
{

}

king::king(string name,int pos)
{
    pieceName=name;
    piecePosition=pos;
}

bool king::Move(int to,Map x)
{
    int io,jo,in,jn;
    io=piecePosition/10;
    jo=piecePosition%10;
    in=to/10;
    jn=to%10;

       if(io-in==1 && jo-jn==0)
    {


        while(in<io)
        {
            io--;

        }

    return 1;


    }
if( jo-jn==1 &&io-in==0)
    {


        while(jn<jo)
        {
            jo--;

        }

    return 1;


    }


     if(io-in==-1 && jn-jo==0)
    {


        while(in>io)
        {
            io++;

        }

    return 1;
}


if(jn-jo==1 && io-in==0)
    {


        while(jn>jo)
        {
            jo++;

        }

    return 1;
}



    if(io-in==1&&jo-jn==-1)
    {
        while(in<io&&jn>jo){
            io--;
            jo++;

        }
    return 1;}
        if(io-in==1&&jo-jn==1){

        while(in<io&&jn<jo){
            io--;
            jo--;

        }
    return 1;
}


if(in-io==1&&jn-jo==1)
{
        while(in>io&&jn>jo){
            io++;
            jo++;

        }
    return 1;}
        if(in-io==1&&jn-jo==-1){
        while(in>io&&jn<jo){
            io++;
            jo--;

 }
    return 1;
}
return 0;
}


