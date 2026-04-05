#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <vector>
#include "AssetManager.hpp"
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

  // Swapping cards and returns the old one.
  Card swapCard( int index, const Card &newCard );
  void addCardToGrid( const Card &card );
  void updateGrid( std::vector<sf::Sprite> &sprites, Player &player, AssetManager &assets);

  void checkColumn(); // Checking if 3 identical Cards in a column should be disCarded.
  bool isGridRevealed() const; // Checking if all Cards are revealed.

  // Getters 
  int getVisibleScore() const;
  int getFinalScore();
  std::vector<Card> &getGrid();
  const std::vector<Card> &getGrid() const;

  // DEBUG
  void display() const;
  void revealCard( int index );
};

#endif
