#include "Card.hpp"

Card::Card() : _value(0), _isVisible(false) {}

Card::Card(int value) : _value(value), _isVisible(false) {}

Card::Card(const Card &other) : _value(other._value), _isVisible(other._isVisible) {}

Card &Card::operator=(const Card &other)
{
  if (this != &other) {
    this->_value = other._value;
    this->_isVisible = other._isVisible;
  }
  return *this;
}

Card::~Card() {}

void Card::setVisible(bool value) {
  this->_isVisible = value;
}

int Card::getValue() const { return this->_value; }
bool Card::isVisible() const { return this->_isVisible; }
