#include "pawn.h"
#include <cmath>
#include "Map.h"
#include "Pieces.h"
#include <iostream>
using namespace std;
pawn::pawn()
{

}
pawn::pawn(string name,int pos,int t)
{
    pieceName=name;
    piecePosition=pos;
    turn=t;
}

bool pawn::Move(int to,Map x)
{
    int io,jo,in,jn;
    io=piecePosition/10;
    jo=piecePosition%10;
    in=to/10;
    jn=to%10;
    if(turn==1)
    {
        if(io==6)
        {
            if((io-in==1 && jo-jn==0)||(io-in==2&&jo-jn==0))
            {


                while(in<io)
                {
                    io--;
                    if(x.getpos(io,jo)!="       ")
                    {
                        return 0;
                    }
                }
                return 1;
            }
        }



        if(io-in==1 && jo-jn==0)
        {


            while(in<io)
            {
                io--;
                if(x.getpos(io,jo)!="       ")
                {
                    return 0;
                }
            }

            return 1;
        }



        if(io-in==1&&jo-jn==-1)
        {
            while(in<io&&jn>jo)
            {
                io--;
                jo++;
                if(x.getpos(io,jo)=="       ")
                {
                    return 0;
                }
            }

            return 1;
        }
        if(io-in==1&&jo-jn==1)
        {

            while(in<io&&jn<jo)
            {
                io--;
                jo--;
                if(x.getpos(io,jo)=="       ")
                {
                    return 0;
                }
            }

            return 1;

        }
    }
    if(turn==2)
    {
        if(io==1)
        {

            if((io-in==-1 && jn-jo==0)||(io-in==-2&&jn-jo==0))
            {


                while(in>io)
                {
                    io++;
                    if(x.getpos(io,jo)!="       ")
                    {
                        return 0;
                    }
                }

                return 1;
            }
        }


        if(io-in==-1 && jn-jo==0)
        {


            while(in>io)
            {
                io++;
                if(x.getpos(io,jo)!="       ")
                {
                    return 0;
                }
            }

            return 1;
        }

        if(in-io==1&&jn-jo==1)
        {
            while(in>io&&jn>jo)
            {
                io++;
                jo++;
                if(x.getpos(io,jo)=="       ")
                {
                    return 0;
                }
            }
            return 1;
        }
        if(in-io==1&&jn-jo==-1)
        {
            while(in>io&&jn<jo)
            {
                io++;
                jo--;
                if(x.getpos(io,jo)=="       ")
                {
                    return 0;
                }

            }

            return 1;

        }
    }
    return 0;
}


