#include<iostream>
#include"pingpong.cpp"
#include"snakegame.cpp"
#include"ticktacktoe1.cpp"
using namespace std;

int main()
{
    int choice;
    bool correct=true;
    cout<<"                                                  "<<"MAIN MENU"<<endl;
    cout<<"                                             PRESS 1 FOR PINGPONG GAME "<<endl;
    cout<<"                                             PRESS 2 FOR SNAKE GAME"<<endl;
    cout<<"                                             PRESS 3 FOR TICTACTOE GAME"<<endl;

    do
    {
        cin>>choice;

        if(choice==1)
        {
            cGameManger pong(40,20);
            pong.Run();
            choice=true;
        }
        else if(choice==2)
        {
            RunSnakeGame();
            choice=true;
        }
        else if(choice==3)
        {
                RunTicTacToe();
                choice=true;
        }
        else
        {
            correct=false;
            cout<<"ENTER CORRECT CHOICE"<<endl;
        }
    }
    while(correct==false);

    return 0;
}
