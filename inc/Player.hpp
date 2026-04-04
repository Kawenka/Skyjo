#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <string>
#include <vector>
#include "Card.hpp"

class Player {
private:
  std::vector<Card> _grid; // Player's cards
  int _score;
  std::string _name;

  bool isVisible(const Card &card) const; // Checking if a card is visible.

public:
  // OCC
  Player();
  Player( std::string name );
  Player( const Player &other );
  Player &operator=( const Player &other );
  ~Player();

  void checkColumn(); // Checking if 3 identical cards in a column should be discarded .
  bool isGridRevealed() const; // Checking if all cards are revealed.
};

#endif
