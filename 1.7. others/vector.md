# 1. Introduction

- `Vector` is a dynamic array which is more versatile than `array` because it can grow or shrink dynamically. 

| **Feature** | **Vector** | **Array** |
|---|---|---|
| **Type** | Dynamic array | Static array |
| **Size** | Can grow and shrink dynamically | Fixed size |
| **Memory allocation** | Automatic | Manual |
| **Access time** | Constant time | Constant time |
| **Insertion and deletion** | Efficient | Inefficient |
| **Sorting** | Efficient | Inefficient |
| **Searching** | Efficient | Inefficient |

- Some most common functions in vector are:

    - `size()`: return the number of existing elements (different from *capacity()*).
    - `empty()`
    - `front()` and `back()`: return the first and last elements.
    - `push_back()` and `pop_back()`: add and remove elements from the end.
    - `insert()` and `erase()`: insert and remove elements at any position.


# 2. Implementation

## a. Create vector

```cpp
#include <vector>
```

- Then, we can create a vector and print out the element.

```cpp
vector<int> v = {1,2,3};

cout << v[0] << endl; // 1
cout << v[1] << endl; // 2
cout << v[2] << endl; // 3
```

## b. Front and back element

```cpp
cout << v.front() << endl; // 1
cout << v.back() << endl; // 3
```

## c. Modify element

```cpp
v[0] = 4;
```

- Adding or removing element is very simple.

```cpp
v.push_back(5); // {1,2,3,5}
v.pop_back(); // {1,2,3}
```

- To insert an element to a specific position, for example, to 2nd position.

```cpp
v.insert(v.begin() + 1, 4); // {1,4,2,3}
v.erase(v.begin() + 1); // {1,2,3}
```

- We can even insert multiple elements into vector.

```cpp
v.insert(v.begin() + 1, {4,5}); // {1,4,5,2,3}
```

## d. Iterating through vector

- To iterate through a vector, we can use either `traditional loop` or `for-each loop`.

```cpp
// Traditional loop
for (int i=0; i<v.size(); i++) {
    cout << v[i] << " ";
}

// For-each loop
for (int element : v) {
    cout << element << " ";
}
```