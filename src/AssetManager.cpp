#include "AssetManager.hpp"
#include <SFML/Graphics/Texture.hpp>

AssetManager::AssetManager() {}

AssetManager::AssetManager(const AssetManager &other) {
  (void)other;
}

AssetManager &AssetManager::operator=(const AssetManager &other) {
  (void)other;

  return *this;
}

bool AssetManager::loadAll() {

  // Loading card_back.png.
  // ID -3
  if (!this->_textures[-3].loadFromFile("assets/cards/card_back.png")) {
    return false;
  }

  // Loading the other cards.
  for (int i = -2; i <= 12; ++i) {
    if (!this->_textures[i].loadFromFile("assets/cards/card_" + std::to_string(i) + ".png")) {
      return false;
    }
  }
  return this->_font.loadFromFile("assets/fonts/Slingday.otf");
}

const sf::Texture &AssetManager::getTexture(int value) const {
  return this->_textures.at(value);
}

const sf::Font &AssetManager::getFont() const {
  return this->_font;
}
