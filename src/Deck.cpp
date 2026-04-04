#include "Deck.hpp"
#include <algorithm>
#include <random>
#include <chrono>

Deck::Deck() {
  for (int i = 0; i < 5; ++i) {
    this->_drawPile.push_back(Card(-2));
  }

  for (int i = 0; i < 10; ++i) {
    this->_drawPile.push_back(Card(-1));
  }

  for (int i = 0; i < 15; ++i) {
    this->_drawPile.push_back(Card(0));
  }

  for (int value = 1; value <= 12; ++value) {
    for (int i = 0; i < 10; ++i) {
      this->_drawPile.push_back(Card(value));
    }
  }

  // Shuffling the cards.
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine engine(seed);

  std::shuffle(_drawPile.begin(), _drawPile.end(), engine);
}

Deck::Deck(const Deck &other) : _drawPile(other._drawPile), _discardPile(other._discardPile) {}

Deck &Deck::operator=(const Deck &other) {
  if (this != &other) {
    this->_drawPile = other._drawPile;
    this->_discardPile = other._discardPile;
  }
  
  return *this;
}

Deck::~Deck() {}

Card Deck::drawFromDeck() {
  if (this->_drawPile.empty()) {
    return Card();
  }

  Card card = this->_drawPile.back();
  this->_drawPile.pop_back();
  return card;
}

Card Deck::drawFromDiscard() {
  if (this->_discardPile.empty()) {
    return Card();
  }

  Card card = this->_discardPile.back();
  this->_discardPile.pop_back();
  return card;
}

void Deck::addToDiscard(Card card) {
  // A card in the discard pile must always be visible.
  // card.setVisible(true);
  this->_discardPile.push_back(card);
}

const Card &Deck::getTopDiscard() const {
  return this->_discardPile.back();
}
