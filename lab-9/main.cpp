#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "������� ����� ���� unsigned int: ";
    unsigned int a;
    cin >> a;
    cout << "����� �����, � ������� �������� ��� �����: " << &a << endl;
    cout << "������ � ������ ����� ���� ������: "<< sizeof(a) << endl;
    char* b = (char*)&a;
    cout << "������������ ��������� ���� unsigned int* � char*: " << b << endl;
    cout << "������ � ������ ���� ������ char: " << sizeof(char) << endl;
    cout << "��������� �����, ����� ����� �������� ������� ����� ����� " << a << ":" << endl;
    for (int i = 0; i< sizeof(a); i++){
        int c = *(b + i);
        cout << "�������� "<< i << "-��� ����: " << c << endl;
 }}