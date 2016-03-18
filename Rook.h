#ifndef ROOK_H
#define ROOK_H

#include "Pieces.h"
#include <iostream>
using namespace std;




class Rook : public Pieces
{
    public:
        Rook();
        bool Move(int to,Map m);
        Rook(string name, int pos);


};

#endif // ROOK_H
