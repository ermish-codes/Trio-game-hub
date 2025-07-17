# Trio-game-hub
Three classic games in one console-based C++ project.

Welcome to **Trio-game-hub** – a C++ console application featuring three classic games: **Tic Tac Toe**, **Rock Paper Scissors**, and **Hangman**. This project demonstrates the use of C++ fundamentals, including functions, file I/O, and dynamic memory handling, all wrapped in a simple text-driven menu interface.

---

## 🎮 Games Included

- **Tic Tac Toe**: Play against a basic bot on a 3x3 board.
- **Rock Paper Scissors**: Challenge the bot in 3 or 5 round matches.
- **Hangman**: Guess randomly chosen words from a text file, with a visual hangman display.

---

## 🛠️ Features

- **Menu-driven interface** for smooth navigation between games.
- **File I/O**: Hangman reads a word list from a file (`wordlist.txt`).
- **Dynamic memory**: Utilized in Hangman for word storage and display.
- **Randomness**: Bot moves and word selection use C++'s random utilities.
- **Input validation**: Ensures a robust user experience.

---

## 🚀 Getting Started

### Prerequisites

- C++ compiler (e.g., g++, clang++)
- Standard C++ libraries

### How to Run

1. **Clone the Repository**
    ```bash
    git clone https://github.com/your-username/game-trio-console.git
    cd game-trio-console
    ```

2. **Ensure `wordlist.txt` is present**  
   The Hangman game requires a `wordlist.txt` file with 50 words (one word per line).

3. **Compile**
    ```bash
    g++ -o game_trio main.cpp
    ```

4. **Run**
    ```bash
    ./game_trio
    ```

---

## 📝 Future Plans

- **Smarter Bots:** Upgrade the game bots with more intelligent and strategic decision-making.
- **User vs User Mode:** Enable multiplayer for all games.
- **Enhanced UI:** Transition to a graphical or web-based interface for a more interactive experience.

---

## 📂 File Structure

```
/game-trio-console
|-- main.cpp         # Main source code
|-- wordlist.txt     # Word list for Hangman (50 words, one per line)
|-- README.md        # Project documentation
```

---

## 💡 Why This Project?

This project is a demonstration of my C++ programming skills, focusing on:
- Modular code organization
- File handling and dynamic memory management
- Implementing classic game logic
- Laying the foundation for more advanced features in the future

---

## 📃 License

MIT License

---

**Enjoy playing!**
