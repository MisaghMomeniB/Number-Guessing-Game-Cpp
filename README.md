# 🎯 Number Guessing Game (C++)

A fun and interactive **console-based number guessing game** implemented in modern C++. Ideal for beginners to learn random number generation, loops, conditionals, input validation, and basic game logic.

---

## 📋 Table of Contents

1. [Overview](#overview)  
2. [Features](#features)  
3. [Tech Stack & Requirements](#tech-stack--requirements)  
4. [Installation & Build](#installation--build)  
5. [Usage Examples](#usage-examples)  
6. [Code Structure](#code-structure)  
7. [Extendability Ideas](#extendability-ideas)  
8. [Contributing](#contributing)  
9. [License](#license)

---

## 💡 Overview

This CLI game randomly selects a number (e.g., between 1–100) and challenges the player to guess it within a limited number of attempts. Feedback is provided after each guess ("too high"/"too low") to guide the player. A classic exercise to practice foundational C++ concepts. :contentReference[oaicite:1]{index=1}

---

## ✅ Features

- 🎲 Random number generation using `rand()` seeded with current time  
- ⏱‍♂️ Difficulty levels offering different attempt limits (e.g., Easy/Medium/Hard)  
- 🔁 Feedback loop: informs player if guess is too high or too low  
- 🧮 Input validation to handle non-numeric user entries  
- 👏 Win/lose messages, with option to replay  
- 🏅 Tracks and displays total wins and losses in a session

---

## 🛠️ Tech Stack & Requirements

- **C++11+** compatible compiler (`g++`, `clang++`, or MSVC)  
- Standard Headers:
  - `<iostream>` for I/O  
  - `<cstdlib>` and `<ctime>` for randomization  
  - `<limits>` for input validation

---

## ⚙️ Installation & Build

Clone the repository and compile:

```bash
git clone https://github.com/MisaghMomeniB/Number-Guessing-Game-Cpp.git
cd Number-Guessing-Game-Cpp
g++ -std=c++11 -o guess_game main.cpp
````

Or, if using CMake:

```bash
mkdir build && cd build
cmake ..
make
```

---

## 🚀 Usage Examples

Run the game with:

```bash
./guess_game
```

Typical session flow:

```
Welcome to the Number Guessing Game!
Choose difficulty (1=Easy, 2=Medium, 3=Hard): 2
I'm thinking of a number between 1 and 100. You have 7 guesses.

Enter your guess: 50
Too high! 6 guesses left.
...
Congratulations! You guessed the number in 5 attempts.
Play again? (y/n): y
```

Tracks and displays the session's win/loss record upon exit.

---

## 📁 Code Structure

```
Number-Guessing-Game-Cpp/
└── main.cpp        # Game logic, RNG, input loop, and scoring
```

Key components:

* RNG seeded with `time(0)`
* Difficulty-level selection setting guess limits
* Input validation using `cin.clear()` and `cin.ignore()`
* Loop controlling guesses with feedback and replay option

---

## 💡 Extendability Ideas

* 🔧 Add customizable range or difficulty command-line flags
* ⏳ Integrate timer to track completion time
* 🗃 Maintain user-specific high scores (file I/O)
* 🎨 Add ASCII art or colorful output to enhance UX
* 🧪 Add unit tests with frameworks like Catch2

---

## 🤝 Contributing

Contributions are welcome! To add features or enhancements:

1. Fork the repository
2. Create a feature branch (e.g., `feature/highscores`)
3. Document and comment your code
4. Submit a Pull Request for review

---

## 📄 License

Released under the **MIT License** — see `LICENSE` for full details.
