# 🎮 Guess the Number Game 🎮

This project is an exciting number guessing game where you get to choose the difficulty level and try to guess a randomly generated number! 🧩

---

## 🔍 Project Description:

This program helps you guess a randomly selected number by the computer. You can choose from three different difficulty levels and try to find the correct number through multiple attempts! 🎯

Each time the game ends, the results are saved to a `game_results.txt` file. 📈

---

## 🧑‍💻 How It Works:

1. **Choose Difficulty Level:**  
   You can choose from three difficulty levels:
   - 🌟 **Easy (1-50)**
   - ⚡ **Medium (1-100)**
   - 🔥 **Hard (1-200)**

2. **Guess the Number:**  
   After selecting the difficulty, you try to guess the number the computer has chosen. You have **7 attempts** to get it right. 🔢

3. **Hint Messages:**  
   After each guess, the game gives you a hint: whether your guess was too low or too high. If you guess correctly, you’ll get congratulated! 🎉

4. **Saving Results:**  
   After the game ends, your number of attempts and the maximum number for each game are saved to a text file. 📄

---

## 📋 Code Breakdown:

### 1. **`generateRandomNumber(int min, int max)` function:**  
   This function generates a random number between the input `min` and `max` values. 📐

### 2. **`chooseDifficulty()` function:**  
   The user is prompted to select a difficulty level. If an invalid input is entered, they are asked to choose again. 💭

### 3. **`saveResultToFile(int attempts, int maxNumber)` function:**  
   After each game, the number of attempts and the maximum number are saved to a `game_results.txt` file. 📝

### 4. **`askToPlayAgain()` function:**  
   This function asks the user if they want to play again. If they choose yes, the game restarts. 🔄

### 5. **`playGuessTheNumber(int maxNumber)` function:**  
   This is where the main game happens. A random number is generated, and the player must guess it. 🕹️

---

## ⚙️ How to Use:

1. Download the code and run it in your C++ environment. 💻
2. Choose your difficulty level.
3. Guess the correct number! 😎
4. Save your results and either play again or exit the game! 🚀

---

## 🎉 Summary:

This game gives you the opportunity to challenge yourself with different difficulty levels of number guessing! Can you find the correct number with the least number of attempts? 👀

Feel free to reach out through **Issues** for any questions or suggestions! 💬

---
