#ifndef GAME_HPP
# define GAME_HPP

#include <vector>
#include "Player.hpp"
#include "Deck.hpp"

class Game {
private:
  std::vector<Player> _players;
  Deck _deck;
  int _currentPlayerIndex;
public:
  Game( int numberOfPlayers );
  Game( const Game& other );
  Game &operator=( const Game& other );
  ~Game();

  void dealCards();
  void playTurn();

  // DEBUG
  void printState() const;
  void printAllPlayers() const;
  void initialReveal();
};

#endif
