#include "Game.hpp"

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
