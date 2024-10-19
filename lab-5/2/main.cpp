#include <iostream>
using namespace std;


int main() {
    int n, summ;
    summ = 1;
    cin >> n;
    summ*=n%10;
    while(n>9 && summ!=0){
        n /=10;
        summ*=n%10;
    }
    cout << summ;
}