#ifndef PIECES_H
#define PIECES_H
#include <iostream>
#include"Map.h"

using namespace std;

class Pieces
{
    public:
        Pieces();
        Pieces(string n,int pos);
        void setposition(int);
        void setname(string);
        string getpieceName()const;
        int getposition()const;
        bool checkpiece(int o);
        virtual bool Move(int to,Map m)=0;
        void setdeath();
        int getdeath();


    protected:
        string pieceName;
        int piecePosition;
        bool isdead;
};

#endif // PIECES_H
