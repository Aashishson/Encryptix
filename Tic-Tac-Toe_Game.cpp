#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentmarker;
char currentplayer;
char player1;
char player2;
//to draw the board or display it
void displayboard(){
    cout << "   |   |   " << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "   |   |   " << endl;
        }
 //to place the mark in the tic-tac-toe grid
bool placemark(){
    int choice;
    cout<<"enter your choice between (1 to 9):";
    cin>>choice;

    if(cin.fail()) { // Check if the input is valid
        cin.clear(); // Clear the error 
    }
    int rows = (choice - 1)/3;
    int columns = (choice -1)%3;
      if (choice > 0 && choice < 10) {
        if (board[rows][columns] != 'X' && board[rows][columns] != 'O') {
            board[rows][columns] = currentmarker;
            return true;
        } else {
            cout << "Slot already taken, choose another number!" << endl;
            return false;
        }
    } else {
        cout << "Invalid number!" << endl;
        return false;
    }
}

//to swap the players
void swapping(){
    if(currentmarker=='X'){
        currentplayer=player2;
        currentmarker='O';
    }
    else{
        currentplayer=player1;
        currentmarker='X';
    }
}
//to check the winner 
char checkwinner(){
    //checking the whole grid using loop first
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            //check winner in rows
            if(board[i][0]==board[i][1] && board[i][0]==board[i][2]){
                return currentmarker;
            }
            //check winner in columns
            if(board[0][i]==board[1][i] && board[0][i]==board[2][i]){
                return currentmarker;
            }
            //diagonals
             if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
                return currentmarker;//diagonal 1
                } 
             if (board[0][2] == board[1][1] && board[1][1] == board[2][0]){
                return currentmarker;//diagonal 2
                } 
        }
      
    }
    return 0;
}

int main(){
cout<<"Tic-Tac-Toe game board"<<endl;
displayboard();
cout<<"player 1 choose your marker between 'X' or 'O' "<<endl;
cin>>currentmarker;
if(currentmarker == 'X'){
   player1 = 'X';
   player2 = 'O';
}else{
    player1 = 'O';
    player2 = 'X';
}
char currentplayer = player1;
int winner =0;
int turns  =0;

//Main game loop
while(winner ==0 && turns<9){
cout << currentplayer <<"'s turn"<<endl;

if(!placemark()){
    continue;
}
displayboard();
winner =checkwinner();
if(winner == 0){
    swapping();
}
turns++;
}
//to check the result
if(winner ==0 && turns ==9){
    cout<<"it's a tie "<<endl;
}else{
    cout<<"player"<<(winner == 'X'? "1": "2")<< "wins!"<<endl;
}
    return 0;
}