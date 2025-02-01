#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to choose difficulty level
int chooseDifficulty() {
    int difficulty;
    cout << "Choose the difficulty level:" << endl;
    cout << "1. Easy (1-50)" << endl;
    cout << "2. Medium (1-100)" << endl;
    cout << "3. Hard (1-200)" << endl;
    cout << "Enter your choice (1/2/3): ";
    cin >> difficulty;

    switch (difficulty) {
        case 1:
            return 50;
        case 2:
            return 100;
        case 3:
            return 200;
        default:
            cout << "Invalid choice! Choosing Medium difficulty by default." << endl;
            return 100;
    }
}

// Function to save results to a file
void saveResultToFile(int attempts, int maxNumber) {
    ofstream file("game_results.txt", ios::app);
    if (file.is_open()) {
        file << "Max Number: " << maxNumber << ", Attempts: " << attempts << "\n";
        file.close();
    } else {
        cout << "Unable to save results to file." << endl;
    }
}

// Function to ask the user if they want to play again
bool askToPlayAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

// Main game logic
void playGuessTheNumber(int maxNumber) {
    int secretNumber = generateRandomNumber(1, maxNumber);
    int guess = 0;
    int attempts = 0;
    const int maxAttempts = 7; // Maximum allowed attempts
    bool guessedCorrectly = false;

    cout << "I have selected a number between 1 and " << maxNumber << "." << endl;
    cout << "You have " << maxAttempts << " attempts to guess it!" << endl;

    while (!guessedCorrectly && attempts < maxAttempts) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < 1 || guess > maxNumber) {
            cout << "Please enter a number between 1 and " << maxNumber << "." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            guessedCorrectly = true;
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
            saveResultToFile(attempts, maxNumber); // Save the result to file
        }
    }

    if (!guessedCorrectly) {
        cout << "Sorry, you've run out of attempts. The correct number was " << secretNumber << "." << endl;
    }
}

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    do {
        int maxNumber = chooseDifficulty(); // Choose difficulty level
        playGuessTheNumber(maxNumber);     // Play the game
    } while (askToPlayAgain());            // Ask if the user wants to play again

    cout << "Thank you for playing! Goodbye!" << endl;
    return 0;
}