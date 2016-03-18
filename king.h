#ifndef KING_H
#define KING_H
#include "Pieces.h"
#include "Map.h"


class king : public Pieces
{
     public:
        king();
        bool Move(int to,Map m);
        king(string name, int pos);


};

#endif // KING_H
