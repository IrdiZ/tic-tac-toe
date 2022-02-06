#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
char board[3][3]={{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
bool win = false;
void winCheck(){
    for (int i=0;i<3;i++){
    if ((board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') || (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
    || (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
    {
        cout << "You have won!\n";
        win = true;
        break;
    }
    }
    for (int i=0;i<3;i++){
    if ((board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') || (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
    || (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')){
        cout << "Bot has won!\n";
        win = true;
        break;
    }
    }
}

void botTurn(){
    cout << "-Turn of the Bot-\n";
    bool unav = false;
    while (unav != true){
    srand(time(NULL));
    int randnum = rand() % 9 + 1;
    int calcnum = randnum - 1; 
    int row = calcnum / 3;
    int col = calcnum % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O'){
            cout << "";
    }else{
        board[row][col] = 'O';
        unav = true; 
    }
    }
}

void drawBoard()
{
    for (int i = 0; i < 3; i++){
        for(int j=0;j<3;j++){
            if (j!=2){
                cout << board[i][j] << " | ";
            }else{
                cout << board[i][j] << " " ;
            }
        }
        cout << endl << "----------" << endl;

    }
}
void playerTurn(int num){
    bool unav = false;
    while (unav != true){
    cout << "Enter your number: ";
    cin >> num;
    int calcnum = num - 1;
    int row = calcnum / 3;
    int col = calcnum % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O'){
        cout << "This is occupied.\n";
    }else{
        board[row][col] = 'X';
        unav = true;
    }
    }
}


int main()
{
    int Enterednum = 0;
    cout << "Hello world!" << endl;
    drawBoard();
    while (win!=true)
    {
        if (win != true)
    { 
            playerTurn(Enterednum); //player-turn
            drawBoard(); //board
            winCheck(); //checkwin
    }
        if (win != true){
            botTurn();  //bot-turn
            drawBoard(); //board
            winCheck();   //checkwin
    }

    }
    
    
}