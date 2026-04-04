#ifndef DECK_HPP
# define DECK_HPP

#include <vector>
#include "Card.hpp"

class Deck {
private:
  std::vector<Card> _drawPile;
  std::vector<Card> _discardPile;
public:
  Deck();
  Deck( const Deck &other );
  Deck &operator=( const Deck &other );
  ~Deck();
 
  Card drawFromDeck();  // Draws from _drawPile.
  Card drawFromDiscard(); // Draws the top card of _discardPile.
  void addToDiscard(Card card);  // Adds a card to the top of _discardPile.
  const Card &getTopDiscard() const; // To show the player what's available.
  bool isEmpty() const;
};

#endif
