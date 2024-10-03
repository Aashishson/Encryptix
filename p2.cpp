#include <iostream>
#include <limits> // For input validation
using namespace std;

char board[3][3];
char currentmarker;
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

// Function to draw the board or display it
void displayboard() {
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

// Function to place the mark in the tic-tac-toe grid
bool placemark() {
    int choice;
    std::cout << "Enter your choice between (1 to 9): ";
    std::cin >> choice;

    if (std::cin.fail()) { // Check if the input is valid
        std::cin.clear(); // Clear the error 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
        return false; // Return false to prompt for input again
    }

    int rows = (choice - 1) / 3;
    int columns = (choice - 1) % 3;
    
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

// Function to swap the players
void swapping() {
    if (currentmarker == 'X') {
        currentmarker = 'O';
    } else {
        currentmarker = 'X';
    }
}

// Function to check the winner 
char checkwinner() {
    // Check for winner in rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0]; // Return the winning marker
        }
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i]; // Return the winning marker
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0]; // Diagonal 1
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2]; // Diagonal 2
    }
    return 0; // No winner
}

int main() {
    char playagain;

    do {
        initializeBoard(); // Reset the board for a new game
        int turns = 0; // Reset turns counter for each new game
        int winner = 0;
        
        std::cout << "Tic-Tac-Toe game board" << endl;
        displayboard();
        
        // Player marker selection
        std::cout << "Player 1, choose your marker between 'X' or 'O': ";
        std::cin >> currentmarker;
        if (currentmarker == 'X') {
            player1 = 'X';
            player2 = 'O'; 
        } else {
            player1 = 'O';
            player2 = 'X';
        }

        // Main game loop
        while (winner == 0 && turns < 9) {
            std::cout << "Player " << ((currentmarker == player1) ? 1 : 2) << "'s turn (" << currentmarker << ")" << endl;

            if (!placemark()) {
                continue; // If placemark fails, prompt for input again
            }

            displayboard();
            winner = checkwinner();

            if (winner == 0) { // Only swap if no winner
                swapping();
            }
            turns++;
        }

        // Check the result
        if (winner == 0 && turns == 9) {
            std::cout << "It's a tie!" << endl;
        } else {
            std::cout << "Player " << ((winner == player1) ? 1 : 2) << " wins!" << endl;
        }

        // Ask if players want to play again
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playagain;

    } while (playagain == 'Y' || playagain == 'y');

    return 0;
}
