#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

namespace model_array {
  struct the_model {
    vector<double> at;
    vector<string> query;
  };

  void to_json(json& j, const the_model& m) {
    j = json{{"at", m.at}, {"query", m.query}};
  }

  void from_json(const json& j, the_model& m) {
    j.at("at").get_to(m.at);
    j.at("query").get_to(m.query);
  }

}//ns model_array
