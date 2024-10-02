#include <iostream>
using namespace std;

int n2(){
    int n;
    cin >> n;
    switch (n){
        case 1: 
            cout << "January";
            break;
        case 2: 
            cout << "February";
            break;
        case 3: 
            cout << "March";
            break;
        case 4: 
            cout << "April";
            break;
        case 5: 
            cout << "May";
            break;
        case 6: 
            cout << "June";
            break;
        case 7: 
            cout << "July";
            break;
        case 8: 
            cout << "August";
            break;
        case 9: 
            cout << "September";
            break;
        case 10: 
            cout << "October";
            break;
        case 11: 
            cout << "November";
            break;
        case 12: 
            cout << "December";
            break;
        default: 
            cout << "Error";
    }
    return 0;
}

int n3(){
    short x;
    cin >> x;
    cout << (x==-1 ? "Negative number" : "Positive number"); //Poyasnenye.txt
    return 0;
}

int main() {
    cout << "1.\n";
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b && b > c) cout << b+a-c;
    else if (b%c==0) cout << b/c-b;
    else cout << a*b-c;
    cout << "\n2.\n";
    n2();
    cout << "\n3.\n";
    n3();
}
