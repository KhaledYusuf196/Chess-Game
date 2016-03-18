

#ifndef KNIGHT_H
#define KNIGHT_H

#include "Pieces.h"

class knight : public Pieces
{
    public:
        knight();
        bool Move(int to,Map m);
        knight(string name ,int pos );

};

#endif // KNIGHT_H
