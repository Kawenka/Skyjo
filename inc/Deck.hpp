#ifndef DECK_HPP
# define DECK_HPP

#include <vector>
#include "Card.hpp"

class Deck {
private:
  std::vector<Card> _deck;
public:
  Deck();
  Deck( const Deck &other );
  Deck &operator=( const Deck &other );
  ~Deck();
  
};

#endif
