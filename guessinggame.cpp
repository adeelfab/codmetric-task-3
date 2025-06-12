#include <iostream>
#include <cstdlib>   
#include <ctime>     
#include <limits>    

using namespace std;

int main() {
    int secretNumber, guess, attempts = 0;

    
    srand(time(0));
    secretNumber = rand() % 100 + 1;  // Generate number between 1 and 100

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have picked a number between 1 and 100. Try to guess it!" << endl;

    while (true) {
        cout << "\nEnter your guess: ";
        
        
        while (!(cin >> guess)) {
            cout << "Invalid input! Please enter a numeric value: ";
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again.";
        } else if (guess < secretNumber) {
            cout << "Too low! Try again.";
        } else {
            cout << "🎉 Congratulations! You guessed the number in " << attempts << " attempts.\n";
            break;
        }
    }

    return 0;
}
