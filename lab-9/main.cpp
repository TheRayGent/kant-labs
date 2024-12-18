#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите число типа unsigned int: ";
    unsigned int a;
    cin >> a;
    cout << "Номер байта, в котором хранится это число: " << &a << endl;
    cout << "Размер в байтах этого типа данных: "<< sizeof(a) << endl;
    char* b = (char*)&a;
    cout << "Конвертируем указатель типа unsigned int* в char*: " << b << endl;
    cout << "Размер в байтах типа данных char: " << sizeof(char) << endl;
    cout << "Благодаря этому, можно найти значения каждого байта числа " << a << ":" << endl;
    for (int i = 0; i< sizeof(a); i++){
        int c = *(b + i);
        cout << "Значение "<< i << "-ого байт: " << c << endl;
 }}