# 1. Introduction

- `HashMap` is a collection of key-value pairs, where each key is unique, and it maps to a corresponding value.

| | HashMap | Array |
| --- | --- | --- |
| **Look-up/ Delete** | Using unique key -> O(1) | Using index -> O(n) |
| **Size** | Dynamic | Static |
| **Data type flexibility** | Keys and values can be of any type | Elements must be of the same type |

# 2. Implementation

## a. Create a Hashmap

```cpp
#include <unordered_map>
```

- Then, we can create a hashmap whose `key` is string and `value` is integer.

```cpp
unordered_map<std::string, int> hashMap;
```

## b. Insert key-value pairs

```cpp
hashMap["Alice"] = 25;
hashMap["Bob"] = 30;
hashMap["Charlie"] = 22;

/// hashMap.insert({"Alice", 25})

// {{"Alice", 25}, {"Bob", 30}, {"Charlie", 22}}
```

> - Another way to add a new pair is using `insert()` function.
>
> ```cpp
> hashMap.insert({"Alice", 25})
> ```

## c. Modify key and value

- We can access a key using `[]` operator.

```cpp
int aliceAge = hashMap["Alice"];

// hashMap["John"]; --> 0
```

> If the key doesn't exist in hashmap, it will return `0`.

- To update, we simply assign new value to the key.

```cpp
hashMap["Alice"] = 26;

hashMap.erase("Charlie");
```

## d. Find key
- To check if a key exists, we can use `find()` (the same as `set`).

```cpp
if (hashMap.find("Bob") != hashMap.end()) {
    cout << "Bob is in the HashMap." << endl;
}
```

## e. Iterating through HashMap

- To iterate through a hashmap, we use a range-based for loop.

```cpp
// `entry.first` is key, `entry.second` is value
for (const auto& entry : hashMap) {
    cout << entry.first << " is " << entry.second << " years old." << endl;
}

// Specified key and value
for (const auto& [key, value] : hashMap) {
    cout << key << "is " << value << " years old." << endl;
}
```