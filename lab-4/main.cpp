#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b && b > c) cout << b+a-c;
    else if (b%c==0) cout << b/c-b;
    else cout << a*b-c;
}