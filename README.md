# serialization-benchmark
(de)serialization performance comparison

Playground project to check the performance difference of (de)serializing.

Array-based objects, e.g.
```
{  
  "query": ["foo", "bar"],  
  "at": [3.141, 3.281]
}
```

and object-based, e.g.

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

Bye using the [_JSON for Modern C++_](https://github.com/nlohmann/json).
Which is -btw- not designed for high speed JSON mapping, see [parsing time benchmarks](https://github.com/miloyip/nativejson-benchmark#parsing-time).
The aim of the playground is just to get an idea about performance differences.

Snapshot of the projects output:

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
