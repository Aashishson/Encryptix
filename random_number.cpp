#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

int main() {
    // Seed random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int guess = 0;
    char playagain;
    std::cout << "Welcome to the Random Number Guesser!" << std::endl;
    std::cout << "I have selected a number between 1 and 100. Can you guess it?" << std::endl;

    // Loop until the correct number is guessed
    
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess > randomNumber) {
            cout << "Too high! Try again." << std::endl;
        } else if (guess < randomNumber) {
            cout << "Too low! Try again." << std::endl;
        } else {
            cout << "Congratulations! You've guessed the right number!" << std::endl;
          
            break;
           
        }
    }  
    
 

    return 0;
}
