#include "Game.hpp"

int main(void) { 
  Game myGame(3);

  myGame.dealCards();
  myGame.initialReveal();
  myGame.determineFirstPlayer();

  return 0;
}
