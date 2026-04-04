#include "Player.hpp"
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
