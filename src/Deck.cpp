#include "Deck.hpp"
#include <algorithm>
#include <random>
#include <chrono>

Deck::Deck() {
  for (int i = 0; i < 5; ++i) {
    this->_deck.push_back(Card(-2));
  }

  for (int i = 0; i < 10; ++i) {
    this->_deck.push_back(Card(-1));
  }

  for (int i = 0; i < 15; ++i) {
    this->_deck.push_back(Card(0));
  }

  for (int value = 1; value <= 12; ++value) {
    for (int i = 0; i < 10; ++i) {
      this->_deck.push_back(Card(value));
    }
  }

  // Shuffling the cards.
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine engine(seed);

  std::shuffle(_deck.begin(), _deck.end(), engine);
}
