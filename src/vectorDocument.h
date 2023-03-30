#include "circle.h"
#include "figure.h"
#include "quadrangle.h"
#include <fstream>
using namespace figure;

class vectorDocument {

private:
  std::vector<vectorFigure *> document_;
  std::vector<coordinates> positonCircle_;
  std::vector<coordinates> positionQuad_;

private:
  void clear();
  void swap();

public:
  using coord = std::pair<double, double>;

  vectorDocument();
  vectorDocument(vectorDocument &v);
  vectorDocument(vectorDocument &&v);
  vectorDocument &operator=(vectorDocument &&v);
  ~vectorDocument();

  void add(char figure);
  void positionInit();
  void shift(int index, int value);
  void deleteLastFigure();
  void deleteIndexFigure(int index);
  void printInfFigure() const;
  int randCoordinates();
  std::vector<vectorFigure *> getDocument() const { return document_; }
  std::pair<std::vector<coordinates>, std::vector<coordinates>>
  getPositionCQ() {
    return std::pair<std::vector<coordinates>, std::vector<coordinates>>(
        positonCircle_, positionQuad_);
  }
  void setData(std::string type, std::vector<coordinates> dots,
               rgba colorFigure, double radius);
  void isEqual(vectorDocument &v);
};