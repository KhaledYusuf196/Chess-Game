#include "Game.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include "Pieces.h"
#include "knight.h"
#include "king.h"
#include "Rook.h"
#include "Bishop.h"
#include "pawn.h"
#include "Queen.h"
#include "Map.h"
#include <fstream>
#include <bits/stdc++.h>

fstream file ;

Game::Game()
{
    piece=new Pieces *[32];
}


Game::Game(const Game& g)  //copy constructor
{
   m=g.m;
   piece=g.piece;
}




void Game::load()
{
    file.open("code.txt",ios::in);
    string s ;
    int n1 , z1 , t1 , cnt = 0 ;
    vector<int> a(0),b(0),_c(0);
    while(getline(file,s)) // read from file
    {
        n1 = atoi((s.substr(0,2)).c_str()); // string to int
        z1 = atoi((s.substr(3,2)).c_str());
        t1 = atoi((s.substr(6,1)).c_str());
        a.push_back(n1);
        b.push_back(z1);
        _c.push_back(t1);
        ++cnt ;   // count numbers of rows in the file
    }
    file.close();
    piece[8]=new knight("Knight1",71);
    piece[9]=new knight("Knight1",76);
    piece[24]=new knight("Knight2",1);
    piece[25]=new knight("Knight2",6);
    piece[10]=new Rook(" Rook1 ",70);
    piece[11]=new Rook(" Rook1 ",77);
    piece[26]=new Rook(" Rook2 ",0);
    piece[27]=new Rook(" Rook2 ",7);
    piece[12]=new Bishop("Bishop1",72);
    piece[13]=new Bishop("Bishop1",75);
    piece[28]=new Bishop("Bishop2",2);
    piece[29]=new Bishop("Bishop2",5);
    piece[14]=new Queen(" Queen1",73);
    piece[30]=new Queen(" Queen2",3);
    piece[0]=new pawn(" pawn1",60,1);
    piece[1]=new pawn(" pawn1",61,1);
    piece[2]=new pawn(" pawn1",62,1);
    piece[3]=new pawn(" pawn1",63,1);
    piece[4]=new pawn(" pawn1",64,1);
    piece[5]=new pawn(" pawn1",65,1);
    piece[6]=new pawn(" pawn1",66,1);
    piece[7]=new pawn(" pawn1",67,1);
    piece[16]=new pawn(" pawn2",10,2);
    piece[17]=new pawn(" pawn2",11,2);
    piece[18]=new pawn(" pawn2",12,2);
    piece[19]=new pawn(" pawn2",13,2);
    piece[20]=new pawn(" pawn2",14,2);
    piece[21]=new pawn(" pawn2",15,2);
    piece[22]=new pawn(" pawn2",16,2);
    piece[23]=new pawn(" pawn2",17,2);
    piece[15]=new king(" king1",74);
    piece[31]=new king(" king2",4);
    int n,z,t=1;

    string p;


    m.draw();

    for(int i = 0 ; i<cnt; i++)
    {
        n = a[i];
        z = b[i];
        t = _c[i];

        cout<< "\n" ;
hello:
        cout<<"******************************************************************\n\t\t\t\tTurn "<< t<<
            "\n******************************************************************\n";
        //    cin>>n>>z;

        n-=11;
        z-=11;

        try
        {
            if(m.checkpos(n,z,t))
            {

                if(t==1)
                {

                for (int i=0; i<15; i++)
                {

                        if(piece[i]->checkpiece(n)&&piece[i]->Move(z,m)&&!(piece[i]->getdeath()))
                        {
                            p=m.getpos(z/10,z%10);
                            revert(z,p,t);
                            m.update(n,z);
                            if(detected(t))
                            {
                                m.update(z,n);
                                m.setpos(z/10,z%10,p);
                                revert(z,p,t);


                                cout<<"Invalid move King detected\n";
                                goto hell;
                            }
                            piece[i]->setposition(z);

                            t = (t==1)? 2 : 1 ;
                        }
                }

                if(piece[15]->checkpiece(n)&&piece[15]->Move(z,m))
                    {
                        p=m.getpos(z/10,z%10);
                        revert(z,p,t);
                        m.update(n,z);
                        piece[15]->setposition(z);
                        if(detected(t))
                        {
                            m.update(z,n);
                            m.setpos(z/10,z%10,p);
                            revert(z,p,t);
                            piece[15]->setposition(n);
                            cout<<"Invalid move King detected\n";
                            goto hell;
                        }
                        t = (t==1)? 2 : 1 ;
                    }
            }


            else if(t==2)
            {

                for (int i=16; i<31; i++)
                {

                        if(piece[i]->checkpiece(n)&&piece[i]->Move(z,m)&&!(piece[i]->getdeath()))
                        {
                            p=m.getpos(z/10,z%10);
                            revert(z,p,t);
                            m.update(n,z);
                            if(detected(t))
                            {
                                m.update(z,n);
                                m.setpos(z/10,z%10,p);
                                revert(z,p,t);


                                cout<<"Invalid move King detected\n";
                                goto hell;
                            }
                            piece[i]->setposition(z);

                            t = (t==1)? 2 : 1 ;
                        }
                }

                    if(piece[31]->checkpiece(n)&&piece[31]->Move(z,m))
                    {
                        p=m.getpos(z/10,z%10);
                        revert(z,p,t);
                        m.update(n,z);
                        piece[31]->setposition(z);
                        if(detected(t))
                        {
                            m.update(z,n);
                            m.setpos(z/10,z%10,p);
                            revert(z,p,t);
                            piece[31]->setposition(n);
                            cout<<"Invalid move King detected\n";
                            goto hell;
                        }
                        t = (t==1)? 2 : 1 ;
                    }
            }
            }
            else
                goto hello ;
        }

        catch(int x)
        {
            cout<<"Out of scope"<<endl;
            goto hello ;
        }

        Sleep(1000);

        system("cls");


        m.draw();

        if(WinOrLose(t,z))
        {
            cout<<"PLayer "<<t<<" lose";
        }

    }

    // start after load

    while(!WinOrLose(t,z))
    {

        cout<<endl;
hell:
        cout<<"******************************************************************\n\t\t\t\tTurn "<< t<<
            "\n******************************************************************\n";
        cin>>n>>z;
        n-=11;
        z-=11;

        try
        {
            if(m.checkpos(n,z,t))
            {
                if(t==1){
                for (int i=0; i<15; i++)
                {

                        if(piece[i]->checkpiece(n)&&piece[i]->Move(z,m)&&!(piece[i]->getdeath()))
                        {
                            p=m.getpos(z/10,z%10);
                            revert(z,p,t);
                            m.update(n,z);
                            if(detected(t))
                            {
                                m.update(z,n);
                                m.setpos(z/10,z%10,p);
                                revert(z,p,t);


                                cout<<"Invalid move King detected\n";
                                goto hell;
                            }
                            piece[i]->setposition(z);
                            write(n+11,z+11,t);

                            t = (t==1)? 2 : 1 ;
                        }
                }


                if(piece[15]->checkpiece(n)&&piece[15]->Move(z,m))
                    {
                        p=m.getpos(z/10,z%10);
                        revert(z,p,t);
                        m.update(n,z);
                        piece[15]->setposition(z);
                        if(detected(t))
                        {
                            m.update(z,n);
                            m.setpos(z/10,z%10,p);
                            revert(z,p,t);
                            piece[15]->setposition(n);
                            cout<<"Invalid move King detected\n";
                            goto hell;
                        }
                        write(n+11,z+11,t);
                        t = (t==1)? 2 : 1 ;
                    }


                }

                else if(t==2){


                for (int i=16; i<31; i++)
                {

                        if(piece[i]->checkpiece(n)&&piece[i]->Move(z,m)&&!(piece[i]->getdeath()))
                        {
                            p=m.getpos(z/10,z%10);
                            revert(z,p,t);
                            m.update(n,z);
                            if(detected(t))
                            {
                                m.update(z,n);
                                m.setpos(z/10,z%10,p);
                                revert(z,p,t);


                                cout<<"Invalid move King detected\n";
                                goto hell;
                            }
                            piece[i]->setposition(z);
                            write(n+11,z+11,t);

                            t = (t==1)? 2 : 1 ;
                        }
                }

                    if(piece[31]->checkpiece(n)&&piece[31]->Move(z,m))
                    {
                        p=m.getpos(z/10,z%10);
                        revert(z,p,t);
                        m.update(n,z);
                        piece[31]->setposition(z);
                        if(detected(t))
                        {
                            m.update(z,n);
                            m.setpos(z/10,z%10,p);
                            revert(z,p,t);
                            piece[31]->setposition(n);
                            cout<<"Invalid move King detected\n";
                            goto hell;
                        }
                        write(n+11,z+11,t);
                        t = (t==1)? 2 : 1 ;
                    }

                }

            }
            else
                goto hell ;

        }

        catch(int x)
        {
            cout<<"Out of scope"<<endl;
            goto hell;
        }

        system("cls");
        m.draw();

        if(WinOrLose(t,z)){
            cout<<"\n Player "<<t<<" lose\n";
        }

    }





}





void Game::revert(int z,string p,int t)
{
    if(t==2)
    {

        for(int i=0; i<15; i++)
        {
            if(piece[i]->checkpiece(z)&&piece[i]->getpieceName()==p)
                piece[i]->setdeath();
        }
    }

    if(t==1)
    {
        for(int i=16; i<31; i++)
        {
            if(piece[i]->checkpiece(z)&&piece[i]->getpieceName()==p)
                piece[i]->setdeath();
        }
    }

}


bool Game::WinOrLose(int t,int z)
{

        if(detected(1))
        {

            try
            {
                if(m.checkpos(piece[15]->getposition(),(piece[15]->getposition()+1),t))
                {
                    piece[15]->setposition(piece[15]->getposition()+1);
                    if(!detected(1))
                    {
                        piece[15]->setposition(piece[15]->getposition()-1);
                        return 0;
                    }
                    piece[15]->setposition(piece[15]->getposition()-1);

                }
            }
            catch(int x)
            {

            }
            try
            {
                if (m.checkpos(piece[15]->getposition(),(piece[15]->getposition()-1),t))
                {
                    piece[15]->setposition(piece[15]->getposition()-1);
                    if(!detected(1))
                    {
                        piece[15]->setposition(piece[15]->getposition()+1);
                        return 0;
                    }
                    piece[15]->setposition(piece[15]->getposition()+1);

                }
            }
            catch(int x)
            {

            }
            try
            {
                if (m.checkpos(piece[15]->getposition(),(piece[15]->getposition()+9),t))
                {
                    piece[15]->setposition(piece[15]->getposition()+9);
                    if(!detected(1))
                    {
                        piece[15]->setposition(piece[15]->getposition()-9);
                        return 0;
                    }
                    piece[15]->setposition(piece[15]->getposition()-9);

                }
            }
            catch(int x)
            {

            }

            try
            {
                if (m.checkpos(piece[15]->getposition(),(piece[15]->getposition()-9),t))
                {
                    piece[15]->setposition(piece[15]->getposition()-9);
                    if(!detected(1))
                    {
                        piece[15]->setposition(piece[15]->getposition()+9);
                        return 0;
                    }
                    piece[15]->setposition(piece[15]->getposition()+9);

                }
            }
            catch(int x)
            {

            }

            try
            {
                if (m.checkpos(piece[15]->getposition(),(piece[15]->getposition()-11),t))
                {
                    piece[15]->setposition(piece[15]->getposition()-11);
                    if(!detected(1))
                    {
                        piece[15]->setposition(piece[15]->getposition()+11);
                        return 0;
                    }
                    piece[15]->setposition(piece[15]->getposition()+11);
                }
            }
            catch(int x)
            {

            }
            try
            {
                if (m.checkpos(piece[15]->getposition(),(piece[15]->getposition()+11),t))
                {
                    piece[15]->setposition(piece[15]->getposition()+11);
                    if(!detected(1))
                    {
                        piece[15]->setposition(piece[15]->getposition()-11);
                        return 0;
                    }
                    piece[15]->setposition(piece[15]->getposition()-11);
                }
            }
            catch(int x)
            {

            }

            try
            {
                if (m.checkpos(piece[15]->getposition(),(piece[15]->getposition()+10),t))
                {
                    piece[15]->setposition(piece[15]->getposition()+10);
                    if(!detected(1))
                    {
                        piece[15]->setposition(piece[15]->getposition()-10);
                        return 0;
                    }
                    piece[15]->setposition(piece[15]->getposition()-10);
                }
            }
            catch(int x)
            {

            }

            try
            {

                if (m.checkpos(piece[15]->getposition(),(piece[15]->getposition()-10),t))
                {
                    piece[15]->setposition(piece[15]->getposition()-10);
                    if(!detected(1))
                    {
                        piece[15]->setposition(piece[15]->getposition()+10);
                        return 0;
                    }
                    piece[15]->setposition(piece[15]->getposition()+10);
                }
            }
            catch(int x)
            {

            }

            int k=piece[15]->getposition();
            int xk=k/10;
            int yk=k%10;
            int xz=z/10;
            int yz=z%10;
            while(!(xz==xk&&yz==yk))
            {
                if(xz>xk)
                {
                    xk++;
                }
                if(xz<xk)
                {
                    xk--;
                }
                if(yz>yk)
                {
                    yk++;
                }
                if(yz<yk)
                {
                    yk--;
                }
                for(int i=0; i<15; i++)
                {
                    if(piece[i]->Move(xk*10+yk,m)&& !(piece[i]->getdeath()))
                    {
                        return 0;
                    }
                }

            }

            return 1;
        }


        if(detected(2))
        {
            try
            {
                if(m.checkpos(piece[31]->getposition(),(piece[31]->getposition()+1),t))
                {
                    piece[31]->setposition(piece[31]->getposition()+1);
                    if(!detected(2))
                    {
                        piece[31]->setposition(piece[31]->getposition()-1);
                        return 0;
                    }
                    piece[31]->setposition(piece[31]->getposition()-1);

                }
            }
            catch(int x)
            {

            }

            try
            {
                if (m.checkpos(piece[31]->getposition(),(piece[31]->getposition()-1),t))
                {
                    piece[31]->setposition(piece[31]->getposition()-1);
                    if(!detected(2))
                    {
                        piece[31]->setposition(piece[31]->getposition()+1);
                        return 0;
                    }
                    piece[31]->setposition(piece[31]->getposition()+1);

                }
            }
            catch(int x)
            {

            }
            try
            {

                if (m.checkpos(piece[31]->getposition(),(piece[31]->getposition()+9),t))
                {
                    piece[31]->setposition(piece[31]->getposition()+9);
                    if(!detected(2))
                    {
                        piece[31]->setposition(piece[31]->getposition()-9);
                        return 0;
                    }
                    piece[31]->setposition(piece[31]->getposition()-9);

                }
            }
            catch(int x)
            {

            }

            try
            {

                if (m.checkpos(piece[31]->getposition(),(piece[31]->getposition()-9),t))
                {
                    piece[31]->setposition(piece[31]->getposition()-9);
                    if(!detected(2))
                    {
                        piece[31]->setposition(piece[31]->getposition()+9);
                        return 0;
                    }
                    piece[31]->setposition(piece[31]->getposition()+9);

                }
            }
            catch(int x)
            {

            }
            try
            {

                if (m.checkpos(piece[31]->getposition(),(piece[31]->getposition()-11),t))
                {
                    piece[31]->setposition(piece[31]->getposition()-11);
                    if(!detected(2))
                    {
                        piece[31]->setposition(piece[31]->getposition()+11);
                        return 0;
                    }
                    piece[31]->setposition(piece[31]->getposition()+11);
                }
            }
            catch(int x)
            {

            }

            try
            {

                if (m.checkpos(piece[31]->getposition(),(piece[31]->getposition()+11),t))
                {
                    piece[31]->setposition(piece[31]->getposition()+11);
                    if(!detected(2))
                    {
                        piece[31]->setposition(piece[31]->getposition()-11);
                        return 0;
                    }
                    piece[31]->setposition(piece[31]->getposition()-11);
                }
            }
            catch(int x)
            {

            }

            try
            {
                if (m.checkpos(piece[31]->getposition(),(piece[31]->getposition()+10),t))
                {
                    piece[31]->setposition(piece[31]->getposition()+10);
                    if(!detected(2))
                    {
                        piece[31]->setposition(piece[31]->getposition()-10);
                        return 0;
                    }
                    piece[31]->setposition(piece[31]->getposition()-10);
                }
            }
            catch(int x)
            {

            }

            try
            {
                if (m.checkpos(piece[31]->getposition(),(piece[31]->getposition()-10),t))
                {
                    piece[31]->setposition(piece[31]->getposition()-10);
                    if(!detected(2))
                    {
                        piece[31]->setposition(piece[31]->getposition()+10);
                        return 0;
                    }
                    piece[31]->setposition(piece[31]->getposition()+10);
                }
            }
            catch(int x)
            {

            }
            int k=piece[31]->getposition();
            int xk=k/10;
            int yk=k%10;
            int xz=z/10;
            int yz=z%10;
            while(xz!=xk&&yz!=yk)
            {
                if(xz>xk)
                {
                    xk++;
                }
                if(xz<xk)
                {
                    xk--;
                }
                if(yz>yk)
                {
                    yk--;
                }
                if(yz<yk)
                {
                    yk--;
                }
                for(int i=16; i<31; i++)
                {
                    if(piece[i]->Move(xk*10+yk,m)&& !(piece[i]->getdeath()))
                    {
                        return 0;
                    }
                }

            }



            return 1;
        }

        return 0;


}
bool Game::detected(int t)
{
    if(t==1)
    {
        for(int i=16; i<31; i++)
        {
            if(piece[i]->Move(piece[15]->getposition(),m)&& !(piece[i]->getdeath()))
            {
                return 1;
            }
        }
        return 0;
    }
    else if(t==2)
    {
        for(int i=0; i<15; i++)
        {
            if(piece[i]->Move(piece[31]->getposition(),m)&& !(piece[i]->getdeath()))
            {
                return 1;
            }
        }
        return 0;
    }
}


void Game::start()
{
    piece[8]=new knight("Knight1",71);
    piece[9]=new knight("Knight1",76);
    piece[24]=new knight("Knight2",1);
    piece[25]=new knight("Knight2",6);
    piece[10]=new Rook(" Rook1 ",70);
    piece[11]=new Rook(" Rook1 ",77);
    piece[26]=new Rook(" Rook2 ",0);
    piece[27]=new Rook(" Rook2 ",7);
    piece[12]=new Bishop("Bishop1",72);
    piece[13]=new Bishop("Bishop1",75);
    piece[28]=new Bishop("Bishop2",2);
    piece[29]=new Bishop("Bishop2",5);
    piece[14]=new Queen(" Queen1",73);
    piece[30]=new Queen(" Queen2",3);
    piece[0]=new pawn(" pawn1",60,1);
    piece[1]=new pawn(" pawn1",61,1);
    piece[2]=new pawn(" pawn1",62,1);
    piece[3]=new pawn(" pawn1",63,1);
    piece[4]=new pawn(" pawn1",64,1);
    piece[5]=new pawn(" pawn1",65,1);
    piece[6]=new pawn(" pawn1",66,1);
    piece[7]=new pawn(" pawn1",67,1);
    piece[16]=new pawn(" pawn2",10,2);
    piece[17]=new pawn(" pawn2",11,2);
    piece[18]=new pawn(" pawn2",12,2);
    piece[19]=new pawn(" pawn2",13,2);
    piece[20]=new pawn(" pawn2",14,2);
    piece[21]=new pawn(" pawn2",15,2);
    piece[22]=new pawn(" pawn2",16,2);
    piece[23]=new pawn(" pawn2",17,2);
    piece[15]=new king(" king1",74);
    piece[31]=new king(" king2",4);
    int n,z,t=1;
    string p;
    m.draw();



    while(!WinOrLose(t,z))
    {

        cout<<endl;
hell:
        cout<<"******************************************************************\n\t\t\t\tTurn "<< t<<
            "\n******************************************************************\n";
        cin>>n>>z;
        n-=11;
        z-=11;

        try
        {
            if(m.checkpos(n,z,t))
            {
                if(t==1)
                {
                for (int i=0; i<15; i++)
                {

                        if(piece[i]->checkpiece(n)&&piece[i]->Move(z,m)&&!(piece[i]->getdeath()))
                        {
                            p=m.getpos(z/10,z%10);
                            revert(z,p,t);
                            m.update(n,z);
                            if(detected(t))
                            {
                                m.update(z,n);
                                m.setpos(z/10,z%10,p);
                                revert(z,p,t);


                                cout<<"Invalid move King detected\n";
                                goto hell;
                            }
                            piece[i]->setposition(z);
                            write(n+11,z+11,t);

                            t = (t==1)? 2 : 1 ;
                        }
                }

                if(piece[15]->checkpiece(n)&&piece[15]->Move(z,m))
                    {
                        p=m.getpos(z/10,z%10);
                        revert(z,p,t);
                        m.update(n,z);
                        piece[15]->setposition(z);
                        if(detected(t))
                        {
                            m.update(z,n);
                            m.setpos(z/10,z%10,p);
                            revert(z,p,t);
                            piece[15]->setposition(n);
                            cout<<"Invalid move King detected\n";
                            goto hell;
                        }
                        write(n+11,z+11,t);
                        t = (t==1)? 2 : 1 ;
                    }
            }
                else if(t==2) {
                for (int i=16; i<31; i++)
                {

                        if(piece[i]->checkpiece(n)&&piece[i]->Move(z,m)&&!(piece[i]->getdeath()))
                        {
                            p=m.getpos(z/10,z%10);
                            revert(z,p,t);
                            m.update(n,z);
                            if(detected(t))
                            {
                                m.update(z,n);
                                m.setpos(z/10,z%10,p);
                                revert(z,p,t);


                                cout<<"Invalid move King detected\n";
                                goto hell;
                            }
                            piece[i]->setposition(z);
                            write(n+11,z+11,t);

                            t = (t==1)? 2 : 1 ;
                        }
                }

                    if(piece[31]->checkpiece(n)&&piece[31]->Move(z,m))
                    {
                        p=m.getpos(z/10,z%10);
                        revert(z,p,t);
                        m.update(n,z);
                        piece[31]->setposition(z);
                        if(detected(t))
                        {
                            m.update(z,n);
                            m.setpos(z/10,z%10,p);
                            revert(z,p,t);
                            piece[31]->setposition(n);
                            cout<<"Invalid move King detected\n";
                            goto hell;
                        }
                        write(n+11,z+11,t);
                        t = (t==1)? 2 : 1 ;
                    }
                }

            }
            else
                goto hell ;

        }

        catch(int x)
        {
            cout<<"Out of scope"<<endl;
            goto hell;
        }

        system("cls");
        m.draw();

        if(WinOrLose(t,z))
        {
            cout<<"PLayer "<<t<<" lose";
        }
    }
}

void Game::write(int n , int z ,int t)// Write data to file
{
    file.open("code.txt",ios::out | ios::app) ;
    file << n << ' ' <<  z  << ' ' << t <<  "\n" ;
    file.close();
}



Game::~Game()
{
    delete [] piece;

}
