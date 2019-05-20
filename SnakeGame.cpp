#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>


/*
   Project Name :Snake game small light version
   Author :Fuad Ashraful Mehmet

   Bsc in CSE
   University of Asia Pacific
   gmail:fuadashraful16@gmail.com

   only code never beats you





*/




using namespace std;

const int height=20;
const int width=50;

const int N=100;

int xCor[N];
int yCor[N];

void  print_gameOVer();
int x,y,fruitx,fruity,score,Snake_last=1;

bool gameOver;

enum eDirection {Stop=0,LEFT,RIGHT,UP,DOWN};


eDirection dir;

void setUp()
{

    gameOver=false;
    dir=Stop;

    x=width/2;
    y=height/2;
    fruitx=rand()%width;
    fruity=rand()%height;
    score=0;
}  /// end function


void Draw()
{

    system("cls");

    cout<<" *********** MidNight Project BY Ashraful Mehmet    ***************************\n\n"<<endl;


    cout<<"Project : Snake game using RAW c++ \n\n"<<endl;


    cout<<"************  SCORE "<<score<<"SnakeLast "<<Snake_last<<"   ***************"<<endl;

    for(int i=0; i<width; ++i)
        cout<<"#";
    cout<<endl;

    for(int i=0; i<height; ++i)
    {

        for(int j=0; j<width; ++j)
        {





            //   cout<<"O";
            for(int k=0; k<Snake_last; ++k)
            {

                if(i==yCor[k]&&j==xCor[k])
                {
                    if(k%4==0)
                        cout<<"T";
                    else if(k%4==1)
                        cout<<"I";
                    else if(k%4==2)
                        cout<<"N";
                    else if(k%4==3)
                        cout<<"I";

                }
            }


            /// end loop

            if(j==0||j==width-1)
                cout<<"#";
            else if(i==fruity&&j==fruitx)
                cout<<"F";
            else
                cout<<" ";
        }

        cout<<endl;
    }

    for(int i=0; i<width; ++i)
        cout<<"#";
    cout<<endl;


}  /// end function


void input()
{

    if(_kbhit())
    {
        switch(_getch())
        {

        case 'u':
            dir=UP;
            break;
        case 'r':
            dir=RIGHT;
            break;
        case 'l':
            dir=LEFT;
            break;
        case 'd':
            dir=DOWN;
            break;
        case 'x':
            gameOver=true;
            break;
        default:
            break;
        }
    }


}  /// end function


void logic()
{

    switch(dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP :
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;

    }


    int tempx=x,tempy=y;

    for(int i=0; i<Snake_last; ++i)
    {
        int tx=xCor[i];
        int ty=yCor[i];
        xCor[i]=tempx;
        yCor[i]=tempy;
        tempx=tx;
        tempy=ty;


    }  ///    ....  this is swapintg loop





    if(x==fruitx&&y==fruity)
    {
        score+=10;

        Snake_last++;

        fruitx=rand()%width;
        fruity=rand()%height;

    }



    if(x<0||x>width||y<0||y>height)
    {

        gameOver=true;

        print_gameOVer();
    }






}   /// end function



void  print_gameOVer()
{

    cout<<"Your game is over \n"<<endl;
    cout<<"**********************"<<endl;
    cout<<"****            ******"<<endl;
    cout<<"****            ******"<<endl;
    cout<<"Your SCORE "<<score<<endl;
    cout<<"****            ******"<<endl;
    cout<<"****            ******"<<endl;
    cout<<"**********************"<<endl;


}  /// end function






int main()
{



    setUp();
    //Draw();

    xCor[0]=x;
    yCor[0]=y;



    while(!gameOver)
    {

        Draw();
        input();
        logic();
        _sleep(300);




    }

    return 0;
}



