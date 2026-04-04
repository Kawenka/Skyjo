#include "Game.hpp"
#include "Colors.hpp"
#include <cstddef>
#include <iostream>

Game::Game(int numberOfPlayers) : _currentPlayerIndex(0) {
  for (int i = 0; i < numberOfPlayers; i++) {
    std::string name = "Player" + std::to_string(i + 1);
    this->_players.push_back(Player(name));
  }
}

Game::Game(const Game& other) {
  (void)other;
}

Game &Game::operator=(const Game& other) {
  (void)other;
  return *this;
}

Game::~Game() {}

void Game::dealCards() {
  for (size_t i = 0; i < this->_players.size(); i++) {
    
    // Giving 12 cards per player.
    for (int j = 0; j < 12; j++) {
      Card card = this->_deck.drawFromDeck();
      this->_players[i].addCardToGrid(card);
    }
  }
  this->_deck.addToDiscard(this->_deck.drawFromDeck());
}

void Game::printState() const {
    std::cout << GREEN << "--- SKYJO GAME STATE ---" << RESET << std::endl;
    
    std::cout << "Discard Pile: [ " << _deck.getTopDiscard().getValue() << " ]" << std::endl;
    
    for (size_t i = 0; i < _players.size(); i++) {
        std::cout << "Player: " << " (Score: " << "0" << ")" << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

void Game::printAllPlayers() const {
  for (size_t i = 0; i < this->_players.size(); i++) {
    this->_players[i].display();
    std::cout << std::endl;
  }
}

void Game::initialReveal() {
  for (size_t i = 0; i < this->_players.size(); i++) {
    this->_players[i].display();

    std::cout << std::endl;
    std::cout << "--- Initial Reveal for Player " << i + 1 << " ---";
    std::cout << std::endl;

    for (int count = 0; count < 2; count++) {
      int choice;
      std::cout << "Choose card #" << count + 1 << " to reveal (0-11): ";
      std::cin >> choice;
      
      if (choice >= 0 && choice <= 11)
          this->_players[i].revealCard(choice);
    }
  }
  this->printAllPlayers();
}

void Game::determineFirstPlayer() {
  int maxScore = -5;
  int startingPlayer = 0;
  
  for (size_t i = 0; i < this->_players.size(); i++) {
    int currentScore = this->_players[i].getVisibleScore();

    if (currentScore > maxScore) {
      maxScore = currentScore;
      startingPlayer = i;
    }
  }
  
  this->_currentPlayerIndex = startingPlayer;
  std::cout << GREEN << "Player " << this->_currentPlayerIndex + 1 << " starts the game" << RESET << std::endl;
}
