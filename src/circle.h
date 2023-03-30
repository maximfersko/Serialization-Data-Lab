#pragma once
#include "figure.h"
#include <cmath>
#include <iostream>

namespace figure {

class circle : public vectorFigure {

private:
  std::vector<coordinates> dot_;
  coordinates centr_;
  double radius_;
  rgba color_;

public:
  circle();
  ~circle();
  circle(coordinates centr, double radius, rgba color);
  coordinates getCentrXY() { return centr_; }
  rgba getColor() { return color_; }
  double getRadius() { return radius_; }
  void setCentrXY(double X, double Y);
  void setColor(int red, int green, int blue, int alpha);
  double perimetr();
  double area();
  void setPosition(const std::vector<coordinates> &dot);
  void setCentr() { centr_ = dot_.back(); }
  void printType();
  char getType();
  int randColor();
  void initColor();
  void init() {
    setCentr();
    radius_ = 1 + rand() % (100 - 1 + 1);
  }
  void init(double radius) {
    setCentr();
    radius_ = radius;
  }
  std::vector<coordinates> getPosition() { return dot_; }
};

}; // namespace figure