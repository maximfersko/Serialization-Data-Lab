#pragma once

#include "include/single_include/nlohmann/json.hpp"
#include "src/vectorDocument.h"
#include <fstream>
#include <string>

const std::string input = "data.txt";
const std::string output = "data.json";

class converter {

public:
  using json = nlohmann::json;
  converter() : input_(input), output_(output) {}
  ~converter() {}
  void to_json(json &j, const vectorDocument &v);
  void from_json(vectorDocument &v, const json &j);

private:
  std::ifstream input_;
  std::ofstream output_;
  size_t size_;
};