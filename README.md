# Cost_Hash 
Cost_Hash is a hash system for hash data in runtime by class `Hash`

## How to use
1. include library 
```cpp
#include "Cost_Hash/Cost_Hash.hpp"
```
1. create `Hash`
```cpp 
Hash h;
```

1. seed generator 
```cpp
h.seed();
```

1. place data inside
```cpp
h.data("example");
```

1. hash the data 
```cpp
std::string hashedString = h.hash();
```

1. rehash data
```cpp
std::string  rehashedString = h.rehash(hashedString);
```
### Rules
1. Seed generator BEFORE using the hash and rehash methods
1. Do NOT using this library to hash important data (aka passwords);


### Warning 
This library using the set hash method, It is not cryptographically generated and it is not for important parts like passwords 


### status
Cost_Hash is on-going hobby C++ project targeted to be useful in small systems 