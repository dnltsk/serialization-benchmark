#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "nlohmann/json.hpp"
#include "model_array.hpp"
#include "model_object.hpp"

using json = nlohmann::json;
using namespace std;
using namespace std::chrono;

std::string json_array = "{"
  "  \"query\": [\"foo\", \"bar\"],"
  "  \"at\": [3.141, 3.281]"
  "}";
std::string json_object = "{"
"  \"query\": {"
"    \"categoryId\": \"foo\","
"    \"value\": \"bar\""
"  }, "
"  \"at\": {"
"    \"lat\": 3.141,"
"    \"lon\": 3.281"
"  }"
"}";

int main()
{
  std::cout<<std::fixed;
  std::cout<<std::setprecision(6);

  int repeats = 100000;
  high_resolution_clock::time_point start;
  high_resolution_clock::time_point end;

  //
  // ARRAY
  //
  cout << "starting deserializing of " << endl;
  cout << json_array << endl;
  cout << ".." << endl;
  start = high_resolution_clock::now();
  for(int i=0; i<repeats; i++){
    json model_array_auto = json::parse(json_array);
    model_array::the_model model_array = model_array_auto;
    //cout << model_array_auto << endl;
    //assert(model_array_auto == model_array);
  }
  end = high_resolution_clock::now();
  duration<double> array_duration = ( end - start );
  cout << "ARRAY:  duration to deserialize " << repeats << " objects: " << array_duration.count() << " seconds" << endl;
  cout << endl;

  //
  // OBJECT
  //
  cout << "starting deserializing of " << endl;
  cout << json_object << endl;
  cout << ".." << endl;
  start = high_resolution_clock::now();
  for(int i=0; i<repeats; i++){
    json model_object_auto = json::parse(json_object);
    model_object::the_model model_object = model_object_auto;
    //cout << model_object_auto << endl;
    //assert(model_object_auto == model_object);
  }
  end = high_resolution_clock::now();
  duration<double> object_duration = ( end - start );
  cout << "OBJECT: duration to deserialize " << repeats << " objects: " << object_duration.count() << " seconds" << endl;

  //
  // RESULTS
  //
  cout << endl;
  cout << "difference: " << endl;
  cout << "  " << abs((object_duration.count() - array_duration.count())) << " seconds" << endl;
  cout << "  " << 100.0 - (100.0 / object_duration.count() * array_duration.count()) << " \% slower" << endl;
  cout << "  => " << (object_duration.count() * array_duration.count()) / repeats << " seconds per deserialized object" << endl;

  return 0;
}
