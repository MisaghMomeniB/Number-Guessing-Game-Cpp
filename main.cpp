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