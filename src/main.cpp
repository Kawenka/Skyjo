#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "AssetManager.hpp"
#include "Game.hpp"

void updateCardSprite(sf::Sprite& sprite, const Card& card, const AssetManager& assets) {
  if (card.isVisible()) {
    sprite.setTexture(assets.getTexture(card.getValue()));
  } else {
    sprite.setTexture(assets.getTexture(-3));
  }
}

int main(void) {
  Game myGame(1);
  myGame.dealCards();
  Player& p1 = myGame.getPlayer(0);

  sf::RenderWindow window(sf::VideoMode(1000, 800), "Skyjo - Game Connected");
  window.setFramerateLimit(60);

  AssetManager assets;
  if (!assets.loadAll()) {
    std::cerr << "Erreur : Impossible de charger les textures !" << std::endl;
    return -1;
  }

  float startX = 150.f, startY = 150.f;
  float offsetX = 180.f, offsetY = 220.f;
  float cardScale = 0.18f;

  std::vector<sf::Sprite> gridSprites(12);
  for (int i = 0; i < 12; ++i) {
    int row = i / 4;
    int col = i % 4;

    gridSprites[i].setScale(cardScale, cardScale);
    gridSprites[i].setPosition(startX + col * offsetX, startY + row * offsetY);
    
    updateCardSprite(gridSprites[i], p1.getGrid()[i], assets);

    sf::FloatRect bounds = gridSprites[i].getLocalBounds();
    gridSprites[i].setOrigin(bounds.width / 2.f, bounds.height / 2.f);
  }

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

        for (int i = 0; i < 12; ++i) {
          if (gridSprites[i].getGlobalBounds().contains(mousePos)) {
            p1.getGrid()[i].setVisible(true);
            
            updateCardSprite(gridSprites[i], p1.getGrid()[i], assets);
            
            std::cout << "Carte cliquee ! Index: " << i
              << " | Valeur: " << p1.getGrid()[i].getValue() << std::endl;
          }
        }
      }
    }

    window.clear(sf::Color(30, 120, 30));

    for (const auto& sprite : gridSprites) {
      window.draw(sprite);
    }

    window.display();
  }

  return 0;
}
