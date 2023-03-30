#include "circle.h"

namespace figure {

circle::circle() : radius_(0), color_(zeroCollor), centr_(zero) {}

circle::circle(coordinates centr, double radius, rgba color)
    : centr_(centr), radius_(radius), color_(color) {}

circle::~circle() {
  centr_ = zero;
  radius_ = 0;
  color_ = zeroCollor;
}

void circle::setCentrXY(double X, double Y) {
  centr_.first = X;
  centr_.second = Y;
}

void circle::setColor(int red, int green, int blue, int alpha) {
  color_.red = red;
  color_.green = green;
  color_.blue = blue;
  color_.alpha = alpha;
}

double circle::perimetr() { return (2 * M_PI * radius_); }

double circle::area() { return (pow(radius_, 2) * M_PI); }

void circle::setPosition(const std::vector<coordinates> &dot) {
  for (auto it = dot.begin(); it != dot.end(); ++it)
    dot_.push_back(*it);
}

void circle::initColor() {
  setColor(randColor(), randColor(), randColor(), randColor());
}

int circle::randColor() { return 1 + rand() % (255 - 1 + 1); }

void circle::printType() { std::cout << "this is circle" << std::endl; }

char circle::getType() { return 'c'; }

}; // namespace figure