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

## result

the flat-model approach is **~18 - 21 microseconds** faster than the structured-model approach.

## sample output:

```
starting deserializing 100000 times of
{  "query": ["foo", "bar"],  "at": [3.141, 3.281]}
..
FLAT: duration to deserialize 100000 flat objects: 1.205422 seconds

starting deserializing 100000 times of
{  "query": {    "categoryId": "foo",    "value": "bar"  },   "at": {    "lat": 3.141,    "lon": 3.281  }}
..
STRUCT: duration to deserialize 100000 structured objects: 1.592470 seconds

RESULTS:
  => deserialization of 100000 structured samples is 0.387048 seconds slower than with flat samples
  => deserialization of structured samples are 24.304886 % slower than the flat samples
  => deserialization of one structured sample is 0.000019 seconds slower than a flat sample
```

## build

`c++ main.cpp -std=c++11`

## run

`./a.out`
