#ifndef MAP_H

#define MAP_H

#include <iostream>

using namespace std;

class Map
{
private:
    string Map1 [8][8];
public:
    Map();
    void update(int o,int n);
    void draw();
    bool checkpos(int o,int n,int p);
    string getpos(int i,int j);
    void setpos(int i,int j,string p);
};


#endif // MAP_H
