# 1. Introduction

- `Set` is a contaner which stores unique element in sorted order (ascending or descending).

# 2. Implementation

## a. Create a set

```cpp
#include <set>
```

- Then, we can add or remove elements to set. If you try to add a duplicate element to set, it will not add.

```cpp
set<int> s;

s.insert(1);
s.insert(2);
s.insert(3);
s.insert(1); // will not be added

s.erase(2);
```

- By default, set is sorted in ascending order. However, we have the option to change the sorting order.

```cpp
set<int, greater<int> > s1;

s1.insert(10);
s1.insert(5);
s1.insert(12);
s1.insert(4);

// {12, 10, 5, 4}
```

## b. Find element

- To check if an element exists in set, we have different approaches:

    - Use `find()` function.
    
    ```cpp
    int key = 3;

    if (s.find(key) != s.end()) {
        cout << "Element exists" << endl;
    } else {
        cout << "Element doesn't exist" << endl;
    }
    ```

    - Use `count()` function.

    ```cpp
    int key = 3;

    if (s.count(key)) {
        cout << "Element exists" << endl;
    } else {
        cout << "Element doesn't exist" << endl;
    }
    ```

    - Use `loop` (canonical method).

    ```cpp
    int key = 3;
 
    bool found = false;
    for (int e : s) {
        if (e == key) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Element exists" << endl;
    } else {
        cout << "Element doesn't exist" << endl;
    }
    ```