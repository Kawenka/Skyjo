#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <vector>
#include "AssetManager.hpp"

int main(void) {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Skyjo - Graphical Edition");
    window.setFramerateLimit(60);

    AssetManager assets;
    if (!assets.loadAll()) {
        std::cerr << "Erreur critique : Impossible de charger les assets !" << std::endl;
        return -1;
    }

    float startX = 150.f;
    float startY = 150.f;
    float offsetX = 180.f;
    float offsetY = 220.f;
    float cardScale = 0.18f;

    std::vector<sf::Sprite> gridSprites(12);
    for (int i = 0; i < 12; ++i) {
        int row = i / 4;
        int col = i % 4;

        gridSprites[i].setTexture(assets.getTexture(-3));
        gridSprites[i].setScale(cardScale, cardScale);
        
        gridSprites[i].setPosition(startX + col * offsetX, startY + row * offsetY);

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
            // Checking if inside the sprite.
            if (gridSprites[i].getGlobalBounds().contains(mousePos)) {
              std::cout << "Carte clique : index " << i << std::endl;

              gridSprites[i].setTexture(assets.getTexture(5));
            }
          }
        }
      }
      window.clear(sf::Color(30, 120, 30)); // Vert "Tapis de jeu"

      // Drawing the grid.
      for (const auto& sprite : gridSprites) {
          window.draw(sprite);
      }
      window.display();
    }

    return 0;
}
