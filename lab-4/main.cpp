#include <iostream>
using namespace std;

int main1(){
    int n;
    cin >> n;
    switch (n){
        case 1: cout << "������";
        case 2: cout << "�������";
        case 3: cout << "����";
        case 4: cout << "������";
        case 5: cout << "���";
        case 6: cout << "����";
        case 7: cout << "����";
        case 8: cout << "������";
        case 9: cout << "��������";
        case 10: cout << "�������";
        case 11: cout << "������";
        case 12: cout << "�������";
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