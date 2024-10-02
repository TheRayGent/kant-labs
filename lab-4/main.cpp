#include <iostream>
using namespace std;

int main1(){
    int n;
    cin >> n;
    switch (n){
        case 1: cout << "Январь";
        case 2: cout << "Февраль";
        case 3: cout << "Март";
        case 4: cout << "Апрель";
        case 5: cout << "Май";
        case 6: cout << "Июнь";
        case 7: cout << "Июль";
        case 8: cout << "Август";
        case 9: cout << "Сентябрь";
        case 10: cout << "Октябрь";
        case 11: cout << "Ноябрь";
        case 12: cout << "Декабрь";
        default: cout << "Error";
    }
}
int main2(){
    short x;
    cin >> x;
    cout << (x==-1 ? "Negative number" : "Positive number"); //Poyasnenye.txt
}

int main() {
    cout << "1.\n";
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b && b > c) cout << b+a-c;
    else if (b%c==0) cout << b/c-b;
    else cout << a*b-c;
    cout << "2.\n";
    main1();
    cout << "\n3.\n";
    main2();
}