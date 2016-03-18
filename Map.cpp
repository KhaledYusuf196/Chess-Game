#include "Map.h"
#include "knight.h"

#include <iostream>

using namespace std;

Map::Map()
{
    string M [8][8] {      " Rook2 ","Knight2","Bishop2"," Queen2"," King2 ","Bishop2","Knight2"," Rook2 ",
                           " Pawn2 "," Pawn2 "," Pawn2 "," Pawn2 "," Pawn2 "," Pawn2 "," Pawn2 "," Pawn2 ",
                           "       ","       ","       ","       ","       ","       ","       ","       ",
                           "       ","       ","       ","       ","       ","       ","       ","       ",
                           "       ","       ","       ","       ","       ","       ","       ","       ",
                           "       ","       ","       ","       ","       ","       ","       ","       ",
                           " Pawn1 "," Pawn1 "," Pawn1 "," Pawn1 "," Pawn1 "," Pawn1 "," Pawn1 "," Pawn1 ",
                           " Rook1 ","Knight1","Bishop1"," Queen1"," King1 ","Bishop1","Knight1"," Rook1 "
                    };
        for(int i= 0; i<8; i++)
        {
            for(int j= 0; j<8; j++)
            {
                Map1[i][j] = M[i][j];
            }
    }
}

void Map::update(int o,int n)
    {
        int io=o/10;
        int jo=o%10;
        int in=n/10;
        int jn=n%10;
        if(io<0 || io>7)
        {
            throw 0;
        }
        if(jo<0||jo>7){
            throw 0;
        }
        if(jn<0||jn>7){
            throw 0;
        }
        if(in<0||in>7){
            throw 0;
        }
        Map1[in][jn]=Map1[io][jo];
        Map1[io][jo]="       ";

    }
   bool Map::checkpos(int o,int n,int p)
    {
        int io=o/10;
        int jo=o%10;
        int in=n/10;
        int jn=n%10;

        if(io<0 || io>7 ){
            throw 0;
        }
        if(jo<0||jo>7){
            throw 0;
        }
        if(jn<0||jn>7){
            throw 0;
        }
        if(in<0||in>7){
            throw 0;
        }

        if(Map1[io][jo]=="       "){
            return 0;
        }
        bool checker;
        string comp = Map1[io][jo];
        if(p==1){
             checker = (comp.find('1')==-1)? 0 : 1 ;   // Turn part
        }
        else{
             checker = (comp.find('2')==-1)? 0 : 1 ;
        }
        if(checker==0){
            return 0;
        }
        comp = Map1[in][jn];
        if(p==1){
             checker = (comp.find('1')==-1)? 1 : 0 ; // replace Part
        }
        else{
             checker = (comp.find('2')==-1)? 1 : 0 ;
        }

            return checker ;
    }

    void Map::draw()
    {
        cout<<"\n"<<    " ----1-------2-------3-------4-------5-------6-------7-------8----";
        for(int i =0; i<8; i++)
        {
            cout<<"\n"<<" |       |       |       |       |       |       |       |       |"<<'\n';
            cout<<i+1;
            for(int j=0; j<8; j++)
            {
                cout<<'|'<<Map1[i][j];
            }
            cout<<"|\n"<<" |       |       |       |       |       |       |       |       |";
            cout<<"\n"<<" -----------------------------------------------------------------";
        }
    }

string Map::getpos(int i,int j)
{
    return Map1[i][j];
}
void Map::setpos(int i,int j,string p)
{
    Map1[i][j]=p;
}
