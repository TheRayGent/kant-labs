#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "���� ������: \n";
    cout << "1. ������������� (��������):\n";
    cout << "   1. int: ������ " << sizeof(int) << ", ���. �������� " << INT_MIN << ", ����. �������� " << INT_MAX << ";\n";
    cout << "   2. short: ������ " << sizeof(short) << ", ���. �������� " << SHRT_MIN << ", ����. �������� " << SHRT_MAX << ";\n";
    cout << "   3. long: ������ " << sizeof(long) << ", ���. �������� " << LONG_MIN << ", ����. �������� " << LONG_MAX << ";\n";
    cout << "   4. long long: ������ " << sizeof(long long) << ", ���. �������� " << LLONG_MIN << ", ����. �������� " << LLONG_MAX << ";\n";

    cout << "2. ������������� (�����������):\n";
    cout << "   1. unsigned int: ������ " << sizeof(unsigned int) << ", ���. �������� " << 0 << ", ����. �������� " << UINT_MAX << ";\n";
    cout << "   2. unsigned short: ������ " << sizeof(unsigned short) << ", ���. �������� " << 0 << ", ����. �������� " << USHRT_MAX << ";\n";
    cout << "   3. unsigned long: ������ " << sizeof(unsigned long) << ", ���. �������� " << 0 << ", ����. �������� " << ULONG_MAX << ";\n";
    cout << "   4. unsigned long long: ������ " << sizeof(unsigned long long) << ", ���. �������� " << 0 << ", ����. �������� " << ULLONG_MAX << ";\n";

    cout << "3. ������������:\n";
    cout << "   1. float: ������ " << sizeof(float) << ", ���. �������� " << FLT_MIN << ", ����. �������� " << FLT_MAX << ";\n";
    cout << "   2. double: ������ " << sizeof(double) << ", ���. �������� " << DBL_MIN << ", ����. �������� " << DBL_MAX << ";\n";
    cout << "   3. long double: ������ " << sizeof(long double) << ", ���. �������� " << LDBL_MIN << ", ����. �������� " << LDBL_MAX << ";\n";

    cout << "4. ����������:\n";
    cout << "   char: ������ " << sizeof(char) << ", ���. �������� " << CHAR_MIN << ", ����. �������� " << CHAR_MAX << ";\n";

    cout << "5. ����������:\n";
    cout << "   bool: ������ " << sizeof(bool) << ", ���. �������� " << 0 << " (false), ����. �������� " << 1 << " (true);\n";

    cout << "\n������� �������������� ��������:\n";

    int int_val = 10;
    int int_result = int_val + 5;
    cout << "   1. int: " << int_val << " + 5 = " << int_result << ";\n";

    float float_val = 3.14;
    float float_result = float_val * 2.0;
    cout << "   2. float: " << float_val << " * 2.0 = " << float_result << ";\n";

    char char_val = 'A';
    char char_result = char_val + 2;
    cout << "   3. char: " << char_val << " + 2 = " << char_result << ";\n";

    bool bool_val = true;
    cout << "   4. bool: !" << bool_val << " (!true) = " << !bool_val << " (false).";
}