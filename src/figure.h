#pragma once

#include <array>
#include <cmath>
#include <iostream>
#include <vector>

namespace figure {

typedef struct color {
  int red = 0;
  int green = 0;
  int blue = 0;
  int alpha = 0;
} rgba;

typedef enum { A, B, C, D, centr } nameDots;

using coordinates = std::pair<double, double>;
const std::pair<double, double> zero = {0, 0};
const rgba zeroCollor = {0, 0, 0, 0};

class vectorFigure {

public:
  vectorFigure() {}
  virtual ~vectorFigure() {}
  virtual rgba getColor() = 0;
  virtual void setColor(int red, int green, int blue, int alpha) = 0;
  virtual double perimetr() = 0;
  virtual double area() = 0;
  virtual void setPosition(const std::vector<coordinates> &dot) = 0;
  virtual std::vector<coordinates> getPosition() = 0;
  virtual void printType() = 0;
  virtual char getType() = 0;
  virtual void initColor() = 0;
  virtual void init() = 0;
  virtual void init(double radius) = 0;
  virtual double getRadius() = 0;
};

}; // namespace figure