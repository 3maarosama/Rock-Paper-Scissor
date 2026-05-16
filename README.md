# 🪨 📄 ✂️ Rock, Paper, Scissors Game

A classic Rock, Paper, Scissors game built using modern C++ concepts. The project focuses on clean code practices, modular design, and interactive user experience.

## ✨ Features
* Customizable Rounds: Play from 1 up to 10 rounds per game.
* Random computer Opponent: Random choice generation for the computer.
* Color-Coded Feedback: Interface colors change dynamically based on the round results (Green for Win, Red for Loss, Yellow for Draw).
* Input Validation: Built-in protection against invalid user choices to prevent crashes.
* Detailed Game Summary: Full statistics (Player wins, Computer wins, Draws, Final Winner) shown at the game over screen.
* Replay Option: Easily restart a new game without exiting the application.

## 🛠️ Concepts Used
* Object-Oriented/Structured thinking using struct and enum.
* Passing parameters by reference (&) to modify original variables directly.
* Code modularity with clean, single-responsibility functions.
* Random number generation using <cstdlib> and <ctime>.

## 🚀 How to Run
Simply compile and run the main.cpp file using any C++ compiler (like GCC or Visual Studio):
`bash
g++ main.cpp -o game
./game
