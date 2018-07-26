#include <iostream>
#include <conio.h>
#include <windows.h>
#include<time.h>
using namespace std;


bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum eDirecton
{
    STOPSNAKE = 0,
    LEFTSNAKE,
    RIGHTSNAKE,
    UPSNAKE,
    DOWNSNAKE

};

eDirecton dir;

void SetUPSNAKE()
{
    gameOver = false;
    dir = STOPSNAKE;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls"); //system("clear");

    //top wall
    for (int i = 0; i < width+2; i++)
        cout << "\xDB";

    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //LEFTSNAKE wall
            if (j == 0)
                cout << "\xDB";

                //food
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "\xFE";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }


            //RIGHTSNAKE wall
            if (j == width - 1)
                cout << "\xDB";
        }
        cout << endl;
    }

    //bottom wall
    for (int i = 0; i < width+2; i++)
        cout << "\xDB";
    cout << endl;
    cout << "Score:" << score << endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFTSNAKE;
            break;
        case 'd':
            dir = RIGHTSNAKE;
            break;
        case 'w':
            dir = UPSNAKE;
            break;
        case 's':
            dir = DOWNSNAKE;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFTSNAKE:
        x--;
        break;
    case RIGHTSNAKE:
        x++;
        break;
    case UPSNAKE:
        y--;
        break;
    case DOWNSNAKE:
        y++;
        break;
    default:
        break;
    }
    //if (x > width || x < 0 || y > height || y < 0)
    //  gameOver = true;
    if (x >= width)
        x = 0;
    else if (x < 0)
        x = width - 1;
    if (y >= height)
        y = 0;
    else if (y < 0)
        y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

void RunSnakeGame()
{
    system("cls");
        int level;
        int n;
        cout<<"DIFFICULTY LEVEL"<<endl;
        cout<<"PRESS 1 FOR EASY"<<endl;
        cout<<"PRESS 2 FOR MEDIUM"<<endl;
        cout<<"PRESS 3 FOR HARD"<<endl;
        bool choice=true;
        do
        {
            cin>>level;

            if(level==1)
            {
                n=150;
                choice=true;
            }
            else if(level==2)
            {
                n=100;
                choice=true;
            }
            else if(level==3)
            {
                choice=true;
                n=50;
            }
            else
            {
                choice=false;
                cout<<"enter correct choice"<<endl;
            }
        }
        while(choice==false);



    SetUPSNAKE();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(n); //sleep(10);
    }
}

/*int main()
{
    RunSnakeGame();
    return 0;
}
*/
