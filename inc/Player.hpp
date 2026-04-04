#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <string>
#include <vector>
#include "Card.hpp"

class Player {
private:
  std::vector<Card> _grid; // Player's Cards.
  int _score;
  std::string _name;

  bool isvisible(const Card &Card) const; // Checking if a Card is visible.

public:
  // OCC
  Player();
  Player( std::string name );
  Player( const Player &other );
  Player &operator=( const Player &other );
  ~Player();

  Card swapCard( int index, const Card &newCard );
  void addCardToGrid( const Card &card );

  void checkcolumn(); // Checking if 3 identical Cards in a column should be disCarded.
  bool isgridrevealed() const; // Checking if all Cards are revealed.
};

#endif
