#include "Player.hpp"

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

