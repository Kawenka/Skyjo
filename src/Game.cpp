#include "Game.hpp"

Game::Game(int numberOfPlayers) {
  (void)numberOfPlayers;
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

    }
  }
}
