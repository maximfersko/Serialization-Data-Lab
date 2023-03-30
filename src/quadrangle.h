#pragma once
#include "figure.h"

namespace figure {

class quadrangle : public vectorFigure {

private:
  std::vector<coordinates> dot_;
  double side1_, side2_;
  double side3_, side4_;
  rgba color_;
  void side();

public:
  quadrangle();
  ~quadrangle();
  void setColor(int red, int green, int blue, int alpha);
  rgba getColor() { return color_; }
  double perimetr();
  double area();
  void setPosition(const std::vector<coordinates> &dot);
  void printType();
  char getType();
  int randColor();
  void initColor();
  void init() { side(); }
  void init(double radius) {}
  double getRadius() { return 5; }
  std::vector<coordinates> getPosition() { return dot_; }
};

}; // namespace figure