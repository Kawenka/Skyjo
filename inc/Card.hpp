#ifndef CARD_HPP
# define CARD_HPP

class Card{
private:
  int _value;
  bool _isVisible;
public:
  Card();
  Card( int value );
  Card( const Card &other );
  Card &operator=( const Card &other );
  ~Card();

  void setVisible(bool value);

  // Getters
  int getValue() const;
  bool isVisible() const;
};

#endif
