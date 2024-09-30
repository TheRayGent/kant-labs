#include <iostream>
using namespace std;

int main() {
    int x, i;
    cin >> x >> i;
    cout << (x >> i & 1);
    return 0;
}