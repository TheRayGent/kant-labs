#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "“ипы данных: \n";
    cout << "1. ÷елочисленные (знаковые):\n";
    cout << "   1. int: размер " << sizeof(int) << ", мин. значение " << INT_MIN << ", макс. значение " << INT_MAX << ";\n";
    cout << "   2. short: размер " << sizeof(short) << ", мин. значение " << SHRT_MIN << ", макс. значение " << SHRT_MAX << ";\n";
    cout << "   3. long: размер " << sizeof(long) << ", мин. значение " << LONG_MIN << ", макс. значение " << LONG_MAX << ";\n";
    cout << "   4. long long: размер " << sizeof(long long) << ", мин. значение " << LLONG_MIN << ", макс. значение " << LLONG_MAX << ";\n";

    cout << "2. ÷елочисленные (беззнаковые):\n";
    cout << "   1. unsigned int: размер " << sizeof(unsigned int) << ", мин. значение " << 0 << ", макс. значение " << UINT_MAX << ";\n";
    cout << "   2. unsigned short: размер " << sizeof(unsigned short) << ", мин. значение " << 0 << ", макс. значение " << USHRT_MAX << ";\n";
    cout << "   3. unsigned long: размер " << sizeof(unsigned long) << ", мин. значение " << 0 << ", макс. значение " << ULONG_MAX << ";\n";
    cout << "   4. unsigned long long: размер " << sizeof(unsigned long long) << ", мин. значение " << 0 << ", макс. значение " << ULLONG_MAX << ";\n";

    cout << "3. ¬ещественные:\n";
    cout << "   1. float: размер " << sizeof(float) << ", мин. значение " << FLT_MIN << ", макс. значение " << FLT_MAX << ";\n";
    cout << "   2. double: размер " << sizeof(double) << ", мин. значение " << DBL_MIN << ", макс. значение " << DBL_MAX << ";\n";
    cout << "   3. long double: размер " << sizeof(long double) << ", мин. значение " << LDBL_MIN << ", макс. значение " << LDBL_MAX << ";\n";

    cout << "4. —имвольные:\n";
    cout << "   char: размер " << sizeof(char) << ", мин. значение " << CHAR_MIN << ", макс. значение " << CHAR_MAX << ";\n";

    cout << "5. Ћогические:\n";
    cout << "   bool: размер " << sizeof(bool) << ", мин. значение " << 0 << " (false), макс. значение " << 1 << " (true);\n";

    cout << "\nѕримеры арифметических операций:\n";

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