#ifndef BISHOP_H
#define BISHOP_H
#include"Map.h"
#include  "Pieces.h"


class Bishop :public Pieces
{
    public:
        Bishop();
        bool Move(int to,Map m);
        Bishop(string name,int pos);

};

#endif // BISHOP_H
