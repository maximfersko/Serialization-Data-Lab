#include "serialization.h"

void converter::to_json(json &j, const vectorDocument &v) {
  std::cout << v.getDocument().at(1)->getPosition().at(0).first;
  for (int i = 0; i < v.getDocument().size(); ++i) {
    std::string t =
        (v.getDocument().at(i)->getType() == 99) ? "circle" : "quadrangle";
    if (t == "circle") {
      j.push_back(json{
          {"type figure", t},
          {"coordinates",
           {{"A",
             {{"first", v.getDocument().at(i)->getPosition().at(0).first},
              {"second", v.getDocument().at(i)->getPosition().at(0).second}}}

           }},
          {"color",
           {{"red", v.getDocument().at(i)->getColor().red},
            {"green", v.getDocument().at(i)->getColor().green},
            {"blue", v.getDocument().at(i)->getColor().blue},
            {"alpha", v.getDocument().at(i)->getColor().alpha}}},
          {"radius", v.getDocument().at(i)->getRadius()},
          {"perimetr", v.getDocument().at(i)->perimetr()},
          {"area:", v.getDocument().at(i)->area()}});
    } else {
      j.push_back(json{
          {"type figure", t},
          {"coordinates",
           {{"A",
             {{"first", v.getDocument().at(i)->getPosition().at(0).first},
              {"second", v.getDocument().at(i)->getPosition().at(0).second}}},
            {"B",
             {{"first", v.getDocument().at(i)->getPosition().at(1).first},
              {"second", v.getDocument().at(i)->getPosition().at(1).second}}},
            {"C",
             {{"first", v.getDocument().at(i)->getPosition().at(2).first},
              {"second", v.getDocument().at(i)->getPosition().at(2).second}}},
            {"D",
             {{"first", v.getDocument().at(i)->getPosition().at(3).first},
              {"second", v.getDocument().at(i)->getPosition().at(3).second}}}}},
          {"color",
           {{"red", v.getDocument().at(i)->getColor().red},
            {"green", v.getDocument().at(i)->getColor().green},
            {"blue", v.getDocument().at(i)->getColor().blue},
            {"alpha", v.getDocument().at(i)->getColor().alpha}}},
          {"perimetr", v.getDocument().at(i)->perimetr()},
          {"area:", v.getDocument().at(i)->area()}});
    }
  }
  output_ << std::setw(2) << j << std::endl;
  size_ = v.getDocument().size();
}

void converter::from_json(vectorDocument &v, const json &j) {
  std::vector<coordinates> tmp;
  for (int i = 0; i < size_; ++i) {
    std::string type = j.at(i).at("type figure").get<std::string>();
    rgba clr = {j.at(i).at("color").at("red").get<int>(),
                j.at(i).at("color").at("green").get<int>(),
                j.at(i).at("color").at("blue").get<int>(),
                j.at(i).at("color").at("alpha").get<int>()};
    if (type == "circle") {
      tmp.clear();
      tmp.push_back({j.at(i).at("coordinates").at("A").at("first"),
                     j.at(i).at("coordinates").at("A").at("second")});
      v.setData(type, tmp, clr, j.at(i).at("radius"));
    } else {
      tmp.clear();
      tmp.push_back({j.at(i).at("coordinates").at("A").at("first"),
                     j.at(i).at("coordinates").at("A").at("second")});
      tmp.push_back({j.at(i).at("coordinates").at("B").at("first"),
                     j.at(i).at("coordinates").at("B").at("second")});
      tmp.push_back({j.at(i).at("coordinates").at("C").at("first"),
                     j.at(i).at("coordinates").at("C").at("second")});
      tmp.push_back({j.at(i).at("coordinates").at("D").at("first"),
                     j.at(i).at("coordinates").at("D").at("second")});
      v.setData(type, tmp, clr, 0);
    }
  }
}