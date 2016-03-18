#ifndef QUEEN_H
#define QUEEN_H


#include "Pieces.h"
#include "Map.h"
#include <iostream>
using namespace std;




class Queen : public Pieces
{
    public:
        Queen();
        bool Move(int to,Map m);
        Queen(string name, int pos);


};

#endif // QUEEN_H
