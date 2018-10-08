#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "nlohmann/json.hpp"
#include "model_flat.hpp"
#include "model_struct.hpp"

using json = nlohmann::json;
using namespace std;
using namespace std::chrono;

string json_flat = "{"
  "  \"query\": [\"foo\", \"bar\"],"
  "  \"at\": [3.141, 3.281]"
  "}";
string json_struct = "{"
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
  cout<<fixed;
  cout<<setprecision(6);

  int num_samples = 100000;
  high_resolution_clock::time_point start;
  high_resolution_clock::time_point end;

  //
  // FLAT
  //
  cout << "starting deserializing " << num_samples << " times of " << endl;
  cout << json_flat << endl;
  cout << ".." << endl;
  start = high_resolution_clock::now();
  for(int i=0; i<num_samples; i++){
    model_flat::the_model model_flat = json::parse(json_flat);
  }
  end = high_resolution_clock::now();
  duration<double> flat_duration = ( end - start );
  cout << "FLAT: duration to deserialize " << num_samples << " flat objects: " << flat_duration.count() << " seconds" << endl;
  cout << endl;

  //
  // STRUCT
  //
  cout << "starting deserializing " << num_samples << " times of " << endl;
  cout << json_struct << endl;
  cout << ".." << endl;
  start = high_resolution_clock::now();
  for(int i=0; i<num_samples; i++){
    model_struct::the_model model_struct = json::parse(json_struct);
  }
  end = high_resolution_clock::now();
  duration<double> struct_duration = ( end - start );
  cout << "STRUCT: duration to deserialize " << num_samples << " structured objects: " << struct_duration.count() << " seconds" << endl;

  //
  // RESULTS
  //
  cout << endl;
  cout << "RESULTS: " << endl;
  cout << "  => deserialization of " << num_samples << " structured samples is " << abs((struct_duration.count() - flat_duration.count())) << " seconds slower than with flat samples" << endl;
  cout << "  => deserialization of structured samples are " << 100.0 - (100.0 / struct_duration.count() * flat_duration.count()) << " \% slower than the flat samples" << endl;
  cout << "  => deserialization of one structured sample is " << (struct_duration.count() * flat_duration.count()) / num_samples << " seconds slower than a flat sample" << endl;

  return 0;
}
