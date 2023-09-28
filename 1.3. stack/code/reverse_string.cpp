#include <iostream>
#include <stack>
#include <cstring> // for using strlen()
using namespace std;

void Reverse(char s[]) {

    int length = strlen(s);

    // Create empty stack
    stack<char> charStack;

    // Push each character into the stack
    for (int i=0; i<length; i++) {
        charStack.push(s[i]);
    }

    // Pop each character and overwrite it to the initial string
    for (int i=0; i<length; i++) {
        s[i] = charStack.top();
        charStack.pop();
    }
}

void ReverseSwap(char s[]) {

    int length = strlen(s);
    int start = 0;
    int end = length-1;

    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char s[] = "hello";
    
    cout << "Initial string: " << s << endl;

    Reverse(s);

    cout << "Reversed string: " << s << endl;

    return 0;
}