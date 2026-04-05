#ifndef ASSET_MANAGER_HPP
# define ASSET_MANAGER_HPP

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <map>
class AssetManager {
private:
  std::map<int, sf::Texture> _textures;
  sf::Font _font;

public:
  AssetManager();
  AssetManager( const AssetManager &other );
  AssetManager &operator=(const AssetManager &other );

  bool loadAll();

  // Getters
  const sf::Texture &getTexture( int value ) const;
  const sf::Font &getFont() const;
};

#endif
