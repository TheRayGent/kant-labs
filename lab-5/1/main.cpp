#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a; // kol-vo int chisel
    int b;
    int imax, maxim, summ;
    imax = -1; maxim = INT_MIN; summ = 0;
    for(int j = 0; j<a; j++){
        cin >> b;
        if (b<0 && b%7==0){
            summ += b;
            if (maxim <= b){
                maxim = b;
                imax = j;
            }
        }
    }
    cout << summ <<"\n"<< maxim <<"\n"<< imax;
}