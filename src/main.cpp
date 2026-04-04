#include "Colors.hpp"
#include "Game.hpp"
#include <iostream>

int main(void) { 
  Game myGame(3);

  myGame.dealCards();
  myGame.initialReveal();
  myGame.determineFirstPlayer();

  while (!myGame.isGameOver()) {
    myGame.playTurn();
  }

  std::cout << YELLOW;
  std::cout << "Someone finished, last round !" << RESET << std::endl;
  myGame.displayFinalScores();
  return 0;
}
