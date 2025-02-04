#include <iostream>  // For input/output operations (e.g., cout, cin)
#include <fstream>   // For file handling (e.g., reading/writing to files)
#include <cstdlib>   // For system-related functions (e.g., rand(), exit())
#include <ctime>     // For time-related functions (e.g., time() for seeding random numbers)
#include <limits>    // For numeric_limits (used to handle invalid input)
#include <algorithm> // For max() function (not used here but included for future use)
#include <utility>   // For swap function (used to ensure min <= max)

using namespace std; // Using the standard namespace to avoid prefixing with "std::"

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    if (min > max) { // Ensure that min is less than or equal to max
        swap(min, max); // Swap values if min > max
    }
    return rand() % (max - min + 1) + min; // Generate a random number in the range [min, max]
}

// Function to allow the user to choose the difficulty level
int chooseDifficulty() {
    int difficulty; // Variable to store the user's choice
    while (true) { // Infinite loop until a valid choice is made
        cout << "Choose the difficulty level:" << endl; // Display difficulty options
        cout << "1. Easy (1-50)" << endl;
        cout << "2. Medium (1-100)" << endl;
        cout << "3. Hard (1-200)" << endl;
        cout << "0. Exit Game" << endl;
        cout << "Enter your choice (0/1/2/3): ";
        cin >> difficulty; // Read user input

        if (cin.fail()) { // If the input is invalid (e.g., non-integer)
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a valid choice." << endl;
            continue; // Restart the loop
        }

        if (difficulty == 0) { // If the user chooses to exit
            return 0; // Return 0 to indicate the game should exit
        }

        if (difficulty >= 1 && difficulty <= 3) { // If the choice is valid (1, 2, or 3)
            return (difficulty == 1) ? 50 : (difficulty == 2) ? 100 : 200; // Return the corresponding max number
        }

        cout << "Invalid choice! Please try again." << endl; // Prompt the user to try again
    }
}

// Function to save the game results to a file
void saveResultToFile(int attempts, int maxNumber) {
    ofstream file("game_results.txt", ios::app); // Open the file in append mode
    if (file.is_open()) { // Check if the file was successfully opened
        file << "Max Number: " << maxNumber << ", Attempts: " << attempts << "\n"; // Write the result to the file
        file.close(); // Close the file
    } else {
        cerr << "Error: Unable to save results to file." << endl; // Handle file opening error
    }
}

// Function to ask the user if they want to play again
bool askToPlayAgain() {
    char choice; // Variable to store the user's choice
    while (true) { // Infinite loop until a valid choice is made
        cout << "Do you want to play again? (y/n): ";
        cin >> choice; // Read user input

        if (choice == 'y' || choice == 'Y') { // If the user chooses 'yes'
            return true; // Return true to continue the game
        } else if (choice == 'n' || choice == 'N') { // If the user chooses 'no'
            return false; // Return false to exit the game
        }

        cout << "Invalid input! Please enter 'y' or 'n'." << endl; // Prompt the user to try again
    }
}

// Function to play the Guess the Number game
void playGuessTheNumber(int maxNumber) {
    int secretNumber = generateRandomNumber(1, maxNumber); // Generate a random number within the specified range
    int guess = 0; // Variable to store the user's guess
    int attempts = 0; // Counter for the number of attempts
    int maxAttempts = (maxNumber == 50) ? 7 : (maxNumber == 100) ? 10 : 15; // Set max attempts based on difficulty
    bool guessedCorrectly = false; // Flag to track if the user has guessed correctly

    cout << "I have selected a number between 1 and " << maxNumber << "." << endl; // Inform the user about the range
    cout << "You have " << maxAttempts << " attempts to guess it!" << endl; // Inform the user about the number of attempts

    while (!guessedCorrectly && attempts < maxAttempts) { // Loop until the user guesses correctly or runs out of attempts
        cout << "Enter your guess (or 0 to exit): ";
        cin >> guess; // Read the user's guess

        if (cin.fail()) { // If the input is invalid (e.g., non-integer)
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a valid number." << endl;
            continue; // Restart the loop
        }

        if (guess == 0) { // If the user chooses to exit
            cout << "Exiting the game. Goodbye!" << endl;
            return; // Exit the function
        }

        attempts++; // Increment the attempt counter

        if (guess < 1 || guess > maxNumber) { // If the guess is out of range
            cout << "Please enter a number between 1 and " << maxNumber << "." << endl;
        } else if (guess < secretNumber) { // If the guess is too low
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) { // If the guess is too high
            cout << "Too high! Try again." << endl;
        } else { // If the guess is correct
            guessedCorrectly = true; // Set the flag to true
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
            saveResultToFile(attempts, maxNumber); // Save the result to the file
        }
    }

    if (!guessedCorrectly) { // If the user runs out of attempts
        cout << "Sorry, you've run out of attempts. The correct number was " << secretNumber << "." << endl;
    }
}

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator with the current time
    cout << "Welcome to the Guess the Number Game!" << endl; // Welcome message

    bool continueGame = true; // Flag to control the game loop
    while (continueGame) { // Loop until the user decides to exit
        int maxNumber = chooseDifficulty(); // Let the user choose the difficulty level
        if (maxNumber == 0) { // If the user chooses to exit
            cout << "Exiting the game. Goodbye!" << endl;
            break; // Exit the loop
        }
        playGuessTheNumber(maxNumber); // Start the game with the chosen difficulty
        continueGame = askToPlayAgain(); // Ask the user if they want to play again
    }

    cout << "Thank you for playing! Goodbye!" << endl; // Farewell message
    return 0; // End the program
}