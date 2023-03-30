#include "vectorDocument.h"

vectorDocument::vectorDocument() { positionInit(); }

vectorDocument::vectorDocument(vectorDocument &v) {
  clear();
  for (auto it = v.document_.begin(); it != v.document_.end(); ++it)
    document_.push_back(*it);
  for (auto it = v.positionQuad_.begin(); it != v.positionQuad_.end(); ++it)
    positionQuad_.push_back(*it);
  for (auto it = v.positonCircle_.begin(); it != v.positonCircle_.end(); ++it)
    positonCircle_.push_back(*it);
}

vectorDocument::vectorDocument(vectorDocument &&v) {
  positionQuad_.swap(v.positionQuad_);
  positonCircle_.swap(v.positonCircle_);
  document_.swap(v.document_);
}

vectorDocument &vectorDocument::operator=(vectorDocument &&v) {
  if (this == &v)
    return *this;
  clear();
  positionQuad_.swap(v.positionQuad_);
  positonCircle_.swap(v.positonCircle_);
  document_.swap(v.document_);
  return *this;
}

vectorDocument::~vectorDocument() { clear(); }

void vectorDocument::clear() {
  positonCircle_.clear();
  positionQuad_.clear();
  document_.clear();
}

void vectorDocument::add(char figure) {
  vectorFigure *f;
  switch (figure) {
  case 'c':
    f = new circle;
    f->setPosition(positonCircle_);
    break;
  case 'q':
    f = new quadrangle;
    f->setPosition(positionQuad_);
  default:
    break;
  }
  f->initColor();
  f->init();
  document_.push_back(f);
  // delete f;
}

void vectorDocument::setData(std::string type, std::vector<coordinates> dots,
                             rgba colorFigure, double radius) {
  vectorFigure *f;
  char c = type == "circle" ? 'c' : 'q';
  switch (c) {
  case 'c':
    f = new circle;
    f->setPosition(dots);
    f->init(radius);
    break;
  case 'q':
    f = new quadrangle;
    f->setPosition(dots);
    f->init();
  default:
    break;
  }
  f->setColor(colorFigure.red, colorFigure.green, colorFigure.blue,
              colorFigure.alpha);
  document_.push_back(f);
  // delete f;
}

void vectorDocument::deleteLastFigure() { document_.pop_back(); }

void vectorDocument::deleteIndexFigure(int index) {
  if (index < document_.size())
    throw std::out_of_range("Error !");
  document_.erase(document_.begin() + index);
}

void vectorDocument::positionInit() {
  positonCircle_.push_back({randCoordinates(), randCoordinates()});
  for (int i = 0; i < 4; ++i) {
    positionQuad_.push_back({randCoordinates(), randCoordinates()});
  }
}

int vectorDocument::randCoordinates() { return 2 + rand() % (1000 - 1 + 2); }

void vectorDocument::printInfFigure() const {
  int countQ = 0;
  int countC = 0;
  for (int i = 0; i < document_.size(); ++i) {
    rgba clr = document_[i]->getColor();
    if (document_[i]->getType() == 'c') {
      std::cout << "CIRCLE #" << countC << std::endl;
      std::cout << " centr dots - "
                << "{" << positonCircle_[countC].first << ", "
                << positonCircle_[countC].second << "}" << std::endl;
      std::cout << "COLOR" << std::endl;
      std::cout << "\tred - " << clr.red << std::endl;
      std::cout << "\tgreen - " << clr.green << std::endl;
      std::cout << "\tblue - " << clr.blue << std::endl;
      std::cout << "\talpha - " << clr.alpha << std::endl;
      std::cout << "INF: " << std::endl;
      std::cout << "perimetr: " << document_[i]->perimetr() << std::endl;
      std::cout << "area: " << document_[i]->area() << std::endl;
      std::cout << " " << std::endl;
      ++countC;
    } else {
      std::cout << "QUSDRANGLE # " << countQ << std::endl;
      std::cout << "first dots - "
                << "{" << positionQuad_[countQ].first << ", "
                << positionQuad_[countQ].second << "}" << std::endl;
      std::cout << "second dots - "
                << "{" << positionQuad_[countQ + 1].first << ", "
                << positionQuad_[countQ + 1].second << "}" << std::endl;
      std::cout << "third dots - "
                << "{" << positionQuad_[countQ + 2].first << ", "
                << positionQuad_[countQ + 2].second << "}" << std::endl;
      std::cout << "four dots - "
                << "{" << positionQuad_[countQ + 3].first << ", "
                << positionQuad_[countQ + 3].second << "}" << std::endl;
      std::cout << "COLOR" << std::endl;
      std::cout << "\tred - " << clr.red << std::endl;
      std::cout << "\tgreen - " << clr.green << std::endl;
      std::cout << "\tblue - " << clr.blue << std::endl;
      std::cout << "\talpha - " << clr.alpha << std::endl;
      std::cout << " " << std::endl;
      std::cout << "INF: " << std::endl;
      std::cout << "perimetr: " << document_[i]->perimetr() << std::endl;
      std::cout << "area: " << document_[i]->area() << std::endl;
      std::cout << " " << std::endl;
      ++countQ;
    }
  }
}

void vectorDocument::isEqual(vectorDocument &v) {
  if (document_.size() == v.getDocument().size()) {
    for (int i = 0; i < document_.size() - 1; ++i) {
      if (document_[i]->getPosition().at(i) !=
          v.getDocument().at(i)->getPosition().at(i))
        throw std::logic_error("Error assert position");
      if (document_[i]->perimetr() != v.document_[i]->perimetr())
        throw std::logic_error("Error assert perimetr");
      if (document_[i]->getColor().red != v.document_[i]->getColor().red ||
          document_[i]->getColor().green != v.document_[i]->getColor().green ||
          document_[i]->getColor().blue != v.document_[i]->getColor().blue ||
          document_[i]->getColor().alpha != v.document_[i]->getColor().alpha)
        throw std::logic_error("Error assert color");
      if (document_[i]->getRadius() != v.document_[i]->getRadius())
        throw std::logic_error("Error assert radius");
      if (document_[i]->getPosition().at(i) !=
          v.document_.at(i)->getPosition().at(i))
        throw std::logic_error("Error assert color");
    }
  }
  std::cout << "Assertion success!" << std::endl;
}

void shift(int index, int value) {}