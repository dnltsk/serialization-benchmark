# serialization-benchmark
(de)serialization performance comparison

Playground project to check the performance difference of (de)serializing between

a) flat data model, e.g.

```
{  
  "query": ["foo", "bar"],  
  "at": [3.141, 3.281]
}
```

b) structured data model, e.g.

```
{  
  "query": {    
    "categoryId": "foo",   
    "value": "bar"  
  },   
  "at": {    
    "lat": 3.141,    
    "lon": 3.281  
  }
}
```

bye using the [_JSON for Modern C++_](https://github.com/nlohmann/json) library.
Which is not designed for high speed JSON mapping, see [parsing time benchmarks](https://github.com/miloyip/nativejson-benchmark#parsing-time), but
the aim of that playground project is just to get an idea about performance differences.

Snapshot of the project's output:

```
starting deserializing of
{  "query": ["foo", "bar"],  "at": [3.141, 3.281]}
..
ARRAY:  duration to deserialize 100000 objects: 1.200257 seconds

starting deserializing of
{  "query": {    "categoryId": "foo",    "value": "bar"  },   "at": {    "lat": 3.141,    "lon": 3.281  }}
..
OBJECT: duration to deserialize 100000 objects: 1.591508 seconds

difference:
  0.391251 seconds
  24.583677 % slower
  => 0.000019 seconds per deserialized object
```

Ergo: the array-based approach is **~19 microseconds** faster than the typesafe object-based approach.

## build

`c++ main.cpp -std=c++11`

## run

`./a.out`
