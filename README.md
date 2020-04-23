# better_containers
better containers for C++  
This library provides you with better containers, such as:
* dynamic_array
* linked_list
* doubly_linked_list
* vector
* string

## installation and usage
1. Clone
```
git clone --recurse-submodules https://github.com/fvbokov/better_containers
```
2. Build
```
conan install . -if build -e CONAN_RUN_TESTS=True -b outdated && conan build . -bf build
```
3. Install
```C++
#include <dynamic_array/dynamic_array.hpp>
#include <linked_list/linked_list.hpp>
#include <doubly_linked_list/doubly_linked_list.hpp>
#include <vector/vector.hpp>
#include <string/string.hpp>
```
4. Read documentaion or if there is no documentation try to guess. Enjoy!

