#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>
#include <utility>
using namespace std;

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    if (min > max) {
        swap(min, max); // Ensure min <= max
    }
    return rand() % (max - min + 1) + min; // Generate a random number in the range [min, max]
}

// Function to allow the user to choose the difficulty level
int chooseDifficulty() {
    int difficulty;
    while (true) {
        cout << "\nChoose the difficulty level:" << endl;
        cout << "1. Easy (1-50)" << endl;
        cout << "2. Medium (1-100)" << endl;
        cout << "3. Hard (1-200)" << endl;
        cout << "0. Exit Game" << endl;
        cout << "Enter your choice (0/1/2/3): ";
        cin >> difficulty;

        if (cin.fail()) { // Handle invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid choice." << endl;
            continue;
        }

        if (difficulty == 0) {
            return 0; // Exit the game
        } else if (difficulty >= 1 && difficulty <= 3) {
            return (difficulty == 1) ? 50 : (difficulty == 2) ? 100 : 200;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}

// Function to save the game results to a file
void saveResultToFile(int attempts, int maxNumber) {
    ofstream file("game_results.txt", ios::app);
    if (file.is_open()) {
        file << "Max Number: " << maxNumber << ", Attempts: " << attempts << "\n";
        file.close();
    } else {
        cerr << "Error: Unable to save results to file." << endl;
    }
}

// Function to ask the user if they want to play again
bool askToPlayAgain() {
    char choice;
    while (true) {
        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            return true;
        } else if (choice == 'n' || choice == 'N') {
            return false;
        } else {
            cout << "Invalid input! Please enter 'y' or 'n'." << endl;
        }
    }
}

// Function to play the Guess the Number game
void playGuessTheNumber(int maxNumber) {
    int secretNumber = generateRandomNumber(1, maxNumber);
    int guess = 0;
    int attempts = 0;
    int maxAttempts = (maxNumber == 50) ? 7 : (maxNumber == 100) ? 10 : 15;
    bool guessedCorrectly = false;

    cout << "\nI have selected a number between 1 and " << maxNumber << "." << endl;
    cout << "You have " << maxAttempts << " attempts to guess it!" << endl;

    while (!guessedCorrectly && attempts < maxAttempts) {
        cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << ": Enter your guess (or 0 to exit): ";
        cin >> guess;

        if (cin.fail()) { // Handle invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number." << endl;
            continue;
        }

        if (guess == 0) {
            cout << "Exiting the game. Goodbye!" << endl;
            return;
        }

        attempts++;

        if (guess < 1 || guess > maxNumber) {
            cout << "Please enter a number between 1 and " << maxNumber << "." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            guessedCorrectly = true;
            cout << "\nCongratulations! You guessed the correct number in " << attempts << " attempts." << endl;
            saveResultToFile(attempts, maxNumber);
        }
    }

    if (!guessedCorrectly) {
        cout << "\nSorry, you've run out of attempts. The correct number was " << secretNumber << "." << endl;
    }
}

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0)));

    cout << "Welcome to the Guess the Number Game!" << endl;

    bool continueGame = true;
    while (continueGame) {
        int maxNumber = chooseDifficulty();
        if (maxNumber == 0) {
            cout << "Exiting the game. Goodbye!" << endl;
            break;
        }

        playGuessTheNumber(maxNumber);
        continueGame = askToPlayAgain();
    }

    cout << "\nThank you for playing! Goodbye!" << endl;
    return 0;
}