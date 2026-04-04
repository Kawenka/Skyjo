#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <string>
#include <vector>
#include "Card.hpp"

class Player {
private:
  std::vector<Card> _grid; // Player's Cards
  int _score;
  std::string _name;

  bool isvisible(const Card &Card) const; // checking if a Card is visible.

public:
  // occ
  Player();
  Player( std::string name );
  Player( const Player &other );
  Player &operator=( const Player &other );
  ~Player();

  void addCardtogrid( const Card &Card );
  Card swapCard( int index, const Card &newCard );

  void checkcolumn(); // checking if 3 identical Cards in a column should be disCarded .
  bool isgridrevealed() const; // checking if all Cards are revealed.
};

#endif
