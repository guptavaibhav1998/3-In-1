        #include <iostream>
        #include <string>
        #include <cstring>
        #include<stdlib.h>
        using namespace std;
        class tictactoe
        {
            public:
                tictactoe();

                void playGame();

            private:

                int getXCoord();
                int getYCoord();
                bool placeMarker(int x,int y,char currentPlayer);

            bool checkForVictory(char currentPlayer);
            //Empties the board
             void clearBoard();
             //Prints the board
             void printBoard();

             char board[3][3];
        };
        tictactoe::tictactoe()
        {

             clearBoard();
        }
        void tictactoe::playGame()
        {
              clearBoard();

             char player1='X';

             char player2='O';

            char currentPlayer=player1;
            bool isDone=false;

            int x,y;
            int turn=0;

            while(isDone==false)
            {
              printBoard();

              x=getXCoord();

              y=getYCoord();

              if(placeMarker(x,y,currentPlayer)==false){
                cout<<"That spot is occupied!\n";
              }
           else
           {
               turn++;
            if(checkForVictory(currentPlayer)==true)
            {
                cout<<"The game is over! Player "<< currentPlayer <<" has won!\n";
                isDone=true;
            }
            else if(turn==9)
            {
                cout<<"Its a tie game \n";
                isDone=true;
            }
            else{
            //switching players
            if(currentPlayer==player1){

                currentPlayer=player2;

            }
            else{

            currentPlayer=player1;

            }
            }
            }
        }
        }
         int tictactoe::getXCoord()
         {
             bool isInputBad=true;
             int x;
            while(isInputBad==true)
            {
             cout<<"Enter the X coordinate: ";
             cin>>x;

            if(x<1 || x>3){
                cout<<"Invalid Coordinate!\n";
            }
            else{
                isInputBad=false;
            }
            }
             return x-1;
         }

         int tictactoe::getYCoord()
         {
              bool isInputBad=true;
             int y;
            while(isInputBad==true)
            {
             cout<<"Enter the Y coordinate: ";
             cin>>y;

            if(y<1 || y>3){
                cout<<"Invalid Coordinate!\n";
            }
            else{
                isInputBad=false;
            }
            }
             return y-1;
         }

          bool tictactoe::placeMarker(int x,int y,char currentPlayer){

            if(board[y][x]!=*" " )
            {
                return false;
            }

            board[y][x]=currentPlayer;
            return true;

         }

         bool tictactoe::checkForVictory(char currentPlayer)
         {
             //check the rows
             for(int i=0;i<3;i++){
         if(board[i][0]==currentPlayer && board[i][0]==board[i][1] && board[i][1]==board[i][2])
         {
           return true;//won
           break;
         }
             }
        //Check the columns
           for(int i=0;i<3;i++){
         if(board[0][i]==currentPlayer && board[0][i]==board[1][i] && board[1][i]==board[2][i])
         {
           return true;//won
           break;
         }
        }
        //Check top left diagonal
        if(board[0][0]==currentPlayer && board[0][0]==board[1][1] && board[1][1]==board[2][2])
         {
           return true;//won
         }

          //Check top right diagonal
        if(board[2][0]==currentPlayer &&  board[0][2]==board[1][1] && board[1][1]==board[2][0])
         {
           return true;//won
         }

         return false;

         }

        void tictactoe::clearBoard()
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                   //had to put * before " " so as to avoid error of assigning integer to pointer
                    board[i][j]=*" ";
                }
            }
        }
      void tictactoe::printBoard()

        {
            system("cls");
            int i;
            cout<<endl;
            cout<<" |1 2 3|\n";
            for( i=0;i<3;i++)
                {
                    cout<<" -------\n";
                cout<<i+1<<"|" <<board[i][0]<<"|"<<board[i][1]<<"|"<<board[i][2]<<"|\n";
            }
             cout<<" -------\n";
        }


        void RunTicTacToe()
        {
            system("cls");
            char input;
           bool isDone=false;
           tictactoe game;
           while(isDone==false)
            {

               game.playGame();
               cout<<"Would you like to play again?(Y/N): ";
               cin>>input;
               if(input=='N' || input=='n')
               {
                   isDone=true;
               }

           }
        }

