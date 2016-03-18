#include "Bishop.h"
#include <cmath>
#include"Map.h"
#include  "Pieces.h"


Bishop::Bishop(string name,int pos)
{
    pieceName=name;
    piecePosition=pos;
}
bool Bishop::Move(int to, Map m)
{

    int io,jo,in,jn;
    io=piecePosition/10;
    jo=piecePosition%10;
    in=to/10;
    jn=to%10;
    if(abs(in-io)==abs(jn-jo))
    {
        while(in-1>io&& jn-1>jo) // down right
        {
            io++;
            jo++;
            if(m.getpos(io,jo)!="       ")
            {
                return 0;
            }
        }
        while(in+1<io&& jn+1<jo) // up left
        {
            io--;
            jo--;
            if(m.getpos(io,jo)!="       ")
            {
                return 0;
            }

        }
        while(in+1<io&& jn-1>jo)
        {
            io--;
            jo++;
            if(m.getpos(io,jo)!="       ")
            {
                return 0;
            }

        }

        while(in-1<io&& jn+1<jo)
        {
            io++;
            jo--;
            if(m.getpos(io,jo)!="       ")
            {
                return 0;
            }
        }
        return 1;
    }

}
