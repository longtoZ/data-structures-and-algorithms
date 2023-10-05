#include <iostream>
#include <cstring>
#include <set>
using namespace std;

void print50NaturalNumber(int n=1) {
    if (n==51) {
        return;
    } else {
        cout << n << " ";
        n++;
        print50NaturalNumber(n);
    }
}

int sumFromOneToN(int n) {
    if (n==1) {
        return 1;
    } else {
        return n + sumFromOneToN(n-1);
    }
}

int fibonacci(int n) {
    if (n==1 || n==2) {
        return 1;
    } else if (n>2) {
        return fibonacci(n-1) + fibonacci(n-2);
    } else {
        return 0;
    }
}

int countDigit(int n) {
    if (n>0) {
        n /= 10;
        return 1 + countDigit(n);
    }
}

int sumOfDigit(int n) {
    if (n>0) {
        int digit = n%10;
        n /= 10;
        return digit + sumOfDigit(n);
    }
}

int gcd(int a, int b) {
    if (a > b) {
        gcd(a-b, a);
    } else if (a < b) {
        gcd(a, b-a);
    } else {
        return a;
    }
}

void reverseString(char s[], int i=0) {
    if (i < strlen(s)-1-i) {

        char temp = s[i];
        s[i] = s[strlen(s)-1-i];
        s[strlen(s)-1-i] = temp;

        i++;
        reverseString(s,i);
    } else {
        cout << s;
    }
}

bool isPrime(int n, int i=2) {
    if (i<=n/2) {
        if (n%i==0) {
            return false;
        } else {
            isPrime(n, i+1);
        }
    } else {
        return true;
    }
}

void printAllEven(int n, int i=1) {
    if (i <= n) {
        if (i%2==0) {
            cout << i << " ";
        }
        printAllEven(n, i+1);
    }
}

bool isPalindrome(char s[], int i=1) {
    if (i < strlen(s)-1-i) {
        if (s[i] != s[strlen(s)-1-i]) {
            return false;
        } else {
            isPalindrome(s, i+1);
        }
    } else {
        return true;
    }
}

int powerOfN(int n, int p, int i=1) {
    if (i <= p) {
        return n*powerOfN(n, p, i+1);
    } else {
        return 1;
    }
}

void copyString(char old[], char s[], int i=0) {
    if (s[i] != '\0') {
        s[i] = old[i];
        copyString(old, s, i+1);
    } else {
        cout << s;
    }
}

void firstCapitalChar(char s[], int i=0) {
    set<char> capitals = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    if (s[i] != '\0') {
        if (capitals.count(s[i])) {
            cout << s[i];
        } else {
            firstCapitalChar(s, i+1);
        }
    } else {
        cout << "not found";
    }

}

int main() {

    char s[] = "testString";

    firstCapitalChar(s);

    return 0;
}