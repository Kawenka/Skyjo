#include <iostream>
#include <SFML/Graphics.hpp>

int main(void) {

  sf::RenderWindow window(sf::VideoMode(800, 600), "Skyjo");
  window.setFramerateLimit(60);

  sf::Texture cardBackTexture;
  if (!cardBackTexture.loadFromFile("assets/cards/card_back.png")) {
    std::cerr << "Error: Could not load card_back.png" << std::endl;
    return -1;
  }

  sf::Sprite cardSprite;
  cardSprite.setTexture(cardBackTexture);
  cardSprite.setScale(0.2f, 0.2f);

  cardSprite.setPosition(400.f, 300.f);

  sf::FloatRect bounds = cardSprite.getLocalBounds();
  cardSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear(sf::Color(0, 100, 0));
    window.draw(cardSprite);
    window.display();
  }

  // Game myGame(3);
  //
  // myGame.dealCards();
  // myGame.initialReveal();
  // myGame.determineFirstPlayer();
  //
  // while (!myGame.isGameOver()) {
  //   myGame.playTurn();
  // }
  //
  // std::cout << YELLOW;
  // std::cout << "Someone finished, last round !" << RESET << std::endl;
  // myGame.displayFinalScores();
  return 0;
}
