# 1. Introduction

- `Struct` lets you create a variable which stores different types of variables (string, float, double, boolean, function,...). For example,
```c
struct Student {
    string id;
    string name;
    double gpa;
    string address;

    void in() {
        cin >> id;
        cin >> name;
        cin >> gpa;
        cin >> address;
    }

    void out() {
        cout << id << " " << name << endl;
    }
};
```
- Then you can set the value for each variable
```cpp
Student x;

x.id = "012344";
x.name = "John";
x.gpa = 3.6;
x.address = "USA";

// or x{"012344", "John", 3.6, "USA"}
```
- You can even create a copy of a previous structer.
```cpp
Student y = x;
```
- In structure, you can set default values for variables using `constructor`.
```cpp
struct Student {
    // ...

    Student() {
        id = "01234";
        name = "John";
        gpa = 3.6;
        address = "USA";
    }

    // ...
}

Student y;
```
- Or you can pass `parameters` to the `constructor`.
```cpp
struct Student {
    // ...

    Student(string id, string name, double gpa, string address) {
        id = id;
        name = name;
        gpa = gpa;
        address = address;
    }

    // ...
}

Student z("01234", "John", 3.6, "USA");
```