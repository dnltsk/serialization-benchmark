#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

namespace model_object {

  struct query_model{
    string categoryId;
    string value;
  };

  struct coordinate_model{
    double lat;
    double lon;
  };

  struct the_model {
    coordinate_model at;
    query_model query;
  };

  void to_json(json& j, const query_model& m) {
    j = json{{"categoryId", m.categoryId}, {"value", m.value}};
  }

  void from_json(const json& j, query_model& m) {
    j.at("categoryId").get_to(m.categoryId);
    j.at("value").get_to(m.value);
  }

  void to_json(json& j, const coordinate_model& m) {
    j = json{{"lat", m.lat}, {"lon", m.lon}};
  }

  void from_json(const json& j, coordinate_model& m) {
    j.at("lat").get_to(m.lat);
    j.at("lon").get_to(m.lon);
  }

  void to_json(json& j, const the_model& m) {
    j = json{{"at", m.at}, {"query", m.query}};
  }

  void from_json(const json& j, the_model& m) {
    j.at("at").get_to(m.at);
    j.at("query").get_to(m.query);
  }

}//ns model_object
