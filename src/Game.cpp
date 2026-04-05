#include "Game.hpp"
#include "Colors.hpp"
#include "Player.hpp"
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
  std::cout << GREEN << "Player " << this->_currentPlayerIndex + 1
    << " starts the game." << RESET << std::endl;
}

#include <iostream>

void Game::playTurn() {
    Player& currentPlayer = _players[_currentPlayerIndex];
    
    std::cout << GREEN << "It's Player " << _currentPlayerIndex + 1 << "'s turn."
      << std::endl;
    currentPlayer.display();
    
    std::cout << std::endl;
    std::cout << "Top of discard pile: [ " << _deck.getTopDiscard().getValue() << " ]"
      << std::endl;

    char choice;
    std::cout << "Draw from Deck (d) or Take from Discard (s)? ";
    std::cin >> choice;

    if (choice == 's') {
        // Draw from discard
        Card drawn = _deck.drawFromDiscard();
        
        int index;
        std::cout << "You took [ " << drawn.getValue() << " ]. Choose index to swap (0-11): ";
        std::cin >> index;

        // Swap and send old card to discard
        _deck.addToDiscard(currentPlayer.swapCard(index, drawn));
    } 
    else {
        // Draw from deck
        Card drawn = _deck.drawFromDeck();
        std::cout << "You drew a [ " << drawn.getValue() << " ]." << std::endl;

        char action;
        std::cout << "Keep and swap (k) or Throw to discard (t)? ";
        std::cin >> action;

        if (action == 'k') {
            int index;
            std::cout << "Choose index to swap (0-11): ";
            std::cin >> index;
            _deck.addToDiscard(currentPlayer.swapCard(index, drawn));
        }
        else {
            // Throw drawn card away
            _deck.addToDiscard(drawn);
            
            // Reveal one hidden card from the grid
            int idx;
            std::cout << "Card discarded. Choose a hidden card to reveal (0-11): ";
            std::cin >> idx;
            currentPlayer.revealCard(idx);
        }
    }

    // End of turn
    // Check for identical columns
    currentPlayer.checkColumn();
    
    // Move to next player
    _currentPlayerIndex = (_currentPlayerIndex + 1) % _players.size();
    
    std::cout << "Turn finished!" << std::endl << std::endl;
}

bool Game::isGameOver() const {
  for (const auto &player : this->_players) {
    if (player.isGridRevealed()) {
      return true;
    }
  }
  return false;
}

void Game::displayFinalScores() {
  std::cout << YELLOW <<  std::endl;
  std::cout << "--- Final scores ---" << RESET << std::endl;

  for (size_t i = 0; i < this->_players.size(); i++) {
    int score = this->_players[i].getFinalScore();
    std::cout << "Player " << i + 1 << ": " << score << " points" << std::endl;
    this->_players[i].display();
  }
}

Player &Game::getPlayer(int index) { return this->_players[index]; }
