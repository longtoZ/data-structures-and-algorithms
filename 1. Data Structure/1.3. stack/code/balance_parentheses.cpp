#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int balanced(char s[]) {
    
    int length = strlen(s);
    stack<char> p;

    for (int i=0; i<length; i++) {
        
        // Push opening parentheses
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            p.push(s[i]);
        
        // Check for matching closing parentheses
        } else {
            if (!p.empty()) {
                if (s[i] == ')' && p.top() == '(') {
                    p.pop();
                } else if (s[i] == ']' && p.top() == '[') {
                    p.pop();
                } else if (s[i] == '}' && p.top() == '{') {
                    p.pop();
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        }
    }

    // Empty means all parentheses are valid
    if (p.empty()) {
        return 1;
    } else {
        return 0;
    }
    
}

int main() {

    char s[] = "(";
    char s2[] = "[(){}]";

    cout << balanced(s) << endl;
    cout << balanced(s2) << endl;

    return 0;
}