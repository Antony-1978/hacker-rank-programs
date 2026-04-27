#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    string s;
    cin >> s;
    stringstream ss(s);
    char ch;
    int a;
    
    while (true) {
        ch = '0';
        ss >> a >> ch;
        cout << a << endl;
        if (ch != ',') {
            break;
        }
    }
    
    return 0;
}
