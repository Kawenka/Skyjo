#include "Game.hpp"

int main(void) { 
  Game myGame(3);

  myGame.dealCards();
  myGame.initialReveal();
  myGame.determineFirstPlayer();

  while (true) {
    myGame.playTurn();
  }
  return 0;
}
