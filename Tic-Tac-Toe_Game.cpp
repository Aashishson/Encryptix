#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentmarker;
char currentplayer;
char player1;
char player2;

// Function to initialize the board
void initializeBoard() {
    char num = '1';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = num++;
        }
    }
}

//to draw the board or display it
void displayboard(){
    std::cout << "   |   |   " << endl;
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    std::cout << "___|___|___" << endl;
    std::cout << "   |   |   " << endl;
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    std::cout << "___|___|___" << endl;
    std::cout << "   |   |   " << endl;
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    std::cout << "   |   |   " << endl;
        }

 //to place the mark in the tic-tac-toe grid
bool placemark(){
    int choice;
    std::cout<<"enter your choice between (1 to 9):";
    std::cin>>choice;

    if(std::cin.fail()) { // Check if the input is valid
        std::cin.clear(); // Clear the error 
    }
    int rows = (choice - 1)/3;
    int columns = (choice -1)%3;
      if (choice > 0 && choice < 10) {
        if (board[rows][columns] != 'X' && board[rows][columns] != 'O') {
            board[rows][columns] = currentmarker;
            return true;
        } else {
            std::cout << "Slot already taken, choose another number!" << endl;
            return false;
        }
    } else {
        std::cout << "Invalid number!" << endl;
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
                return board[i][0];
            }
            //check winner in columns
            if(board[0][i]==board[1][i] && board[0][i]==board[2][i]){
                return board[0][i];
            }
            //diagonals
             if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
                return board[0][0];//diagonal 1
                } 
             if (board[0][2] == board[1][1] && board[0][2] == board[2][0]){
                return board[0][2];//diagonal 2
                } 
        }
      
    }
    return 0;
}

int main(){
    char playagain;
    char currentplayer = player1;
   
do {

    initializeBoard();
    std::cout<<"Tic-Tac-Toe game board"<<endl;
    displayboard();
    std::cout<<"player 1 choose your marker between 'X' or 'O' "<<endl;
    std::cin>>currentmarker;
    if(currentmarker == 'X'){
      player1 = 'X';
      player2 = 'O'; 
      }
    else{
      player1 = 'O';
      player2 = 'X';
      }
       int winner =0;
       int turns  =0;
    
   
    

 //Main game loop
  while(winner ==0 && turns<9){
   std::cout << currentmarker <<"'s turn"<<endl;

    if(!placemark()){
    continue;
    }
      displayboard();
      winner =checkwinner();
      if(winner==0){
        swapping();
      }
      turns++;
    }
 //to check the result
 if(winner ==0 && turns ==9){
    std::cout<<"it's a tie "<<endl;
 }else{
    std::cout<<"player"<<(winner==player1? "1":"2")<< "wins!"<<endl;
 }
 // Ask if players want to play again
        cout << "Do you want to play again? (Y/N): ";
        std::cin >> playagain;
} while (playagain == 'Y' || playagain == 'y');

        
    return 0;
    } 


