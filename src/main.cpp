#include "Game.hpp"

int main(void) { 
  Game myGame(3);

  myGame.dealCards();
  myGame.initialReveal();

  return 0;
}
