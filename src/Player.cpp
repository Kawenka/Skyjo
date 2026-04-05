#include "Player.hpp"
#include "Card.hpp"
#include "Colors.hpp"
#include <iomanip>
#include <iostream>

Player::Player() : _score(0), _name("Player") {}

Player::Player(std::string name) { 
  this->_name = name;
  this->_score = 0;
}

Player::Player(const Player& other) : _grid(other._grid), _score(other._score),
  _name(other._name) {}

Player &Player::operator=(const Player& other) {
  if (this != &other) {
    this->_grid = other._grid;
    this->_score = other._score;
    this->_name = other._name;
  }
  return *this;
}

Player::~Player() {}

void Player::addCardToGrid(const Card &card) {
  this->_grid.push_back(card);
}

void Player::display() const {
  std::cout << GREEN << "Grid for " << this->_name << " :" << RESET << std::endl;
  
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 4; x++) {
      const Card &card = this->_grid[y * 4 + x];

      std::cout << "[ ";
      if (card.isVisible()) {
        std::cout << std::setw(2) << card.getValue();
      }
      else {
        std::cout << " ? ";
      }
      std::cout << " ] ";
    }
    std::cout << std::endl;
  }
}

void Player::revealCard(int index) {
  if (index >= 0 && index < (int)this->_grid.size()) {
    this->_grid[index].setVisible(true);
  }
}

int Player::getVisibleScore() const {
  int sum = 0;

  for (const auto &card: this->_grid) {
    if (card.isVisible()) {
      sum += card.getValue();
    }
  }
  return sum;
}

int Player::getFinalScore() {
  int sum = 0;

  for (auto &card : this->_grid) {
    // Last turn, we count hidden cards as well.
    card.setVisible(true);
    sum += card.getValue();
  }
  return sum;
}

const std::vector<Card> &Player::getGrid() const { return this->_grid; }
std::vector<Card> &Player::getGrid() { return this->_grid; }

Card Player::swapCard(int index, const Card &newCard) {
  if (index < 0 || index >= (int)this->_grid.size()) {
    return Card();
  }
  
  // Get the old card to return it to the game for discard.
  Card oldCard = this->_grid[index];

  // Replace with new card and make it visible.
  this->_grid[index] = newCard;
  this->_grid[index].setVisible(true);

  // The old card must be visible when in the discard pile.
  oldCard.setVisible(true);

  return oldCard;
}

void Player::checkColumn() {
  for (int col = 0; col < 4; col++) {
    int idx1 = col; // Top row.
    int idx2 = col + 4; // Middel row.
    int idx3 = col + 8; // Jacques row.

    // Check if all three cards are revealed.
    if (this->_grid[idx1].isVisible() && this->_grid[idx2].isVisible()
      && this->_grid[idx3].isVisible()) {

      // Check if they all have the same value.
      if (this->_grid[idx1].getValue() == this->_grid[idx2].getValue()
        && this->_grid[idx2].getValue() == this->_grid[idx3].getValue()) {
        std::cout << GREEN << "Column " << col << " cleared." << RESET << std::endl;
 
        this->_grid[idx1] = Card(0);
        this->_grid[idx2] = Card(0);
        this->_grid[idx3] = Card(0);
      }
    }
  }
}

bool Player::isGridRevealed() const {
  for (const auto &card : this->_grid) {
    if (!card.isVisible()) {
      return false;
    }
  }
  return true;
}

void updateGrid( std::vector<sf::Sprite> &sprites, Player &player, AssetManager &assets) {
  auto &cards = player.getGrid();

  for (int i = 0; i < 12; ++i) {
    if (cards[i].isVisible()) {
      sprites[i].setTexture(assets.getTexture(cards[i].getValue()));
    }
    else {
      sprites[i].setTexture(assets.getTexture(-3));
    }
  }
}
