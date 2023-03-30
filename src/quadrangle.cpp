
#include "quadrangle.h"

namespace figure {

quadrangle::quadrangle() : side1_(0), side2_(0), side3_(0), side4_(0) {}

quadrangle::~quadrangle() {
  for (size_t i = 0; i < dot_.size(); ++i)
    dot_[i] = zero;
  side1_ = 0, side2_ = 0;
  side3_ = 0, side4_ = 0;
}

void quadrangle::setColor(int red, int green, int blue, int alpha) {
  color_.red = red;
  color_.green = green;
  color_.blue = blue;
  color_.alpha = alpha;
}

void quadrangle::side() {
  side1_ = sqrt(pow(dot_[A].first - dot_[B].first, 2) +
                pow(dot_[B].second - dot_[B].second, 2));
  side2_ = sqrt(pow(dot_[B].first - dot_[C].first, 2) +
                pow(dot_[B].second - dot_[C].second, 2));
  side1_ = sqrt(pow(dot_[C].first - dot_[D].first, 2) +
                pow(dot_[C].second - dot_[C].second, 2));
  side1_ = sqrt(pow(dot_[D].first - dot_[A].first, 2) +
                pow(dot_[A].second - dot_[A].second, 2));
}

double quadrangle::perimetr() { return side1_ + side2_ + side3_ + side4_; }

double quadrangle::area() {
  double p = this->perimetr() / 2;
  return sqrt(p - side1_ * p - side2_ * p - side3_ * p - side4_);
}

void quadrangle::setPosition(const std::vector<coordinates> &dot) {
  for (auto it = dot.begin(); it != dot.end(); ++it)
    dot_.push_back(*it);
  // for (auto item : dot_) std::cout << item.first;
}

void quadrangle::printType() { std::cout << "this is quadrangle" << std::endl; }

char quadrangle::getType() { return 'q'; }

int quadrangle::randColor() { return 1 + rand() % (255 - 1 + 1); }

void quadrangle::initColor() {
  setColor(randColor(), randColor(), randColor(), randColor());
}

}; // namespace figure