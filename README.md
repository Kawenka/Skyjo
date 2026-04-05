# Skyjo CPP - SFML Edition

A C++ implementation of the famous card game **Skyjo**, using the **SFML**
library for the graphical interface.

> **Status: Work In Progress** > Transitioning from a functional
Terminal/Console engine to a fully Graphical User Interface.

## Current Features

- [x] **Core Game Logic**: Deck shuffling, card dealing, and player turn rotations.
- [x] **Game Rules**: Implementation of the "Triple Column" bonus (discarding
      3 identical cards).
- [x] **Scoring**: Automated score calculation and end-game detection.
- [x] **Graphics**: Asset management system (Textures & Fonts) and basic sprite 
      rendering.

## Assets

- **Custom Art**: All card textures were hand-drawn on **Procreate**.
- **Typography**: Using the *Slingday* font for a playful, handcrafted feel.

## Tech Stack

- **Language**: C++17
- **Graphics**: SFML 2.6+
- **Environment**: Linux / WSL2
- **Editor**: LazyVim (Neovim)

## Installation & Run

```bash
# Clone the repo
git clone <your-repo-link>

# Compile the project
# Make sure SFML is installed on your system
make re

# Run the game
./Skyjo
```
Created with C++
