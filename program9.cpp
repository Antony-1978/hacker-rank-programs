include <iostream>
#include <string>
#include<utility>
using namespace std;

int main() {
    // Complete the program
  string a;
  cin >> a;
  
  string b;
  cin >> b;
  
  cout << a.size() << " " << b.size() << endl;
  cout << a + b << endl;
  
  swap(a[0], b[0]);
  cout << a << " " << b << endl;
  
    return 0;
}
