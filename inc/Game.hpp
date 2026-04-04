#ifndef GAME_HPP
# define GAME_HPP

class Game {
public:
  Game();
  Game( const Game& other );
  Game &operator=( const Game& other );
  ~Game();

  void dealCards();
};

#endif
