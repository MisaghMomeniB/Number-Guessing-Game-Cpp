#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

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

void playGuessTheNumber(int maxNumber) {
    int secretNumber = generateRandomNumber(1, maxNumber);
    int guess = 0;
    int attempts = 0;
    bool guessedCorrectly = false;

    cout << "I have selected a number between 1 and " << maxNumber << "." << endl;
    cout << "Try to guess it!" << endl;

    while (!guessedCorrectly) {
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
        }
    }
}
