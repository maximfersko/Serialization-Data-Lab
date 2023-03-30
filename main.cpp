#include "serialization.h"

int main() {
  vectorDocument A;
  converter cnv;
  nlohmann::json j;
  A.add('c');
  A.add('q');
  A.add('c');
  A.printInfFigure();
  cnv.to_json(j, A);
  vectorDocument tmp;
  cnv.from_json(tmp, j);
  tmp.printInfFigure();
  // assert object
  try {
    A.isEqual(tmp);
  } catch (std::logic_error &e) {
    std::cout << e.what() << std::endl;
  }
}