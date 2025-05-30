#include <iostream>
//#include <stdexcept>

template <typename T, size_t N, size_t M>
class Matrix
{
private:
    T data[N][M];

public:
    // Базовый конструктор
    Matrix()
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                data[i][j] = T(); // Инициализация значением по умолчанию для типа T
            }
        }
    }

    // Конструктор копирования
    Matrix(const Matrix &other)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Оператор присваивания копированием
    Matrix &operator=(const Matrix &other)
    {
        if (this != &other)
        {
            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < M; ++j)
                {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    // Оператор ввода
    friend std::istream &operator>>(std::istream &in, Matrix &matrix)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                in >> matrix.data[i][j];
            }
        }
        return in;
    }

    // Оператор вывода
    friend std::ostream &operator<<(std::ostream &out, const Matrix &matrix)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                out << matrix.data[i][j] << " ";
            }
            out << std::endl;
        }
        return out;
    }

    // Оператор +
    Matrix operator+(const Matrix &other) const
    {
        Matrix result;
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Оператор +=
    Matrix &operator+=(const Matrix &other)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    // Оператор * (умножение на скаляр)
    Matrix operator*(const T &scalar) const
    {
        Matrix result;
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    // Оператор *= (умножение на скаляр)
    Matrix &operator*=(const T &scalar)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                data[i][j] *= scalar;
            }
        }
        return *this;
    }

    // Оператор умножения матриц (для N=M=2 и N=M=3)
    template <size_t K> //  Размерность второго операнда
    Matrix<T, N, K> operator*(const Matrix<T, M, K> &other) const
    {
        if (N <= 3 && M <= 3 && K <= 3)
        {
            Matrix<T, N, K> result;
            for (size_t i = 0; i < N; i++)
            {
                for (size_t j = 0; j < K; j++)
                {
                    result(i,j) = 0;
                    for (size_t k = 0; k < M; k++)
                    {
                        result(i,j) += data[i][k] * other(k,j);
                    }
                }
            }
            return result;
        }
        else
        {
            throw std::invalid_argument("Matrix multiplication is only supported for N, M, K <= 3.");
        }
    }

    // Оператор ++ (префиксный)
    Matrix &operator++()
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                ++data[i][j];
            }
        }
        return *this;
    }

    // Оператор ++ (постфиксный)
    Matrix operator++(int)
    {
        Matrix temp = *this;
        ++(*this);
        return temp;
    }

    // // Метод вычисления определителя (только для квадратных матриц)
    T determinant() const
    {
        if (N == 1 && M == 1)
        {
            return data[0][0];
        }
        else if (N == 2 && M == 2)
        {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        }
        else if (N == 3 && M == 3)
        {
            return data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
                   data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
                   data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
        }
        else
        {
            throw std::invalid_argument("Determinant is only supported for 1x1, 2x2, and 3x3 square matrices.");
        }
    }

    // Оператор доступа к элементу матрицы
    T &operator()(size_t row, size_t col)
    {
        if (row >= N || col >= M)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[row][col];
    }

    const T &operator()(size_t row, size_t col) const
    {
        if (row >= N || col >= M)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[row][col];
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    // Пример использования
    Matrix<int, 2, 2> matrix1;
    Matrix<int, 2, 2> matrix2;

    std::cout << "Введите элементы первой матрицы 2x2:" << std::endl;
    std::cin >> matrix1;

    std::cout << "Введите элементы второй матрицы 2x2:" << std::endl;
    std::cin >> matrix2;

    std::cout << "Матрица 1:" << std::endl;
    std::cout << matrix1 << std::endl;

    std::cout << "Матрица 2:" << std::endl;
    std::cout << matrix2 << std::endl;

    Matrix<int, 2, 2> sum = matrix1 + matrix2;
    std::cout << "Сумма матриц:" << std::endl;
    std::cout << sum << std::endl;

    matrix1 += matrix2;
    std::cout << "matrix1 += matrix2:" << std::endl;
    std::cout << matrix1 << std::endl;

    Matrix<int, 2, 2> matrix3 = matrix1 * 2;
    std::cout << "matrix1 * 2:" << std::endl;
    std::cout << matrix3 << std::endl;

    ++matrix3;
    std::cout << "++matrix3:" << std::endl;
    std::cout << matrix3 << std::endl;

    std::cout << "Определитель matrix3:" << std::endl;
    std::cout << matrix3.determinant() << std::endl;

    std::cout << "Элемент matrix3[0][1]: " << matrix3(0, 1) << std::endl;
    matrix3(0, 1) = 100;
    std::cout << "Измененный элемент matrix3[0][1]: " << matrix3(0, 1) << std::endl;
    std::cout << "matrix3:" << std::endl;
    std::cout << matrix3 << std::endl;

    // Пример с матрицей 3x3
    Matrix<double, 3, 3> matrix4;
    std::cout << "\nВведите элементы матрицы 3x3:" << std::endl;
    std::cin >> matrix4;
    std::cout << "Матрица 4:" << std::endl;
    std::cout << matrix4 << std::endl;
    std::cout << "Определитель matrix4:" << std::endl;
    std::cout << matrix4.determinant() << std::endl;

    // Пример с умножением матриц
    Matrix<int, 2, 3> matrix5;
    Matrix<int, 3, 2> matrix6;

    std::cout << "\nВведите элементы матрицы 2x3:" << std::endl;
    std::cin >> matrix5;
    std::cout << "Введите элементы матрицы 3x2:" << std::endl;
    std::cin >> matrix6;

    Matrix<int, 2, 2> matrix7 = matrix5 * matrix6;
    std::cout << "matrix5 * matrix6:" << std::endl;
    std::cout << matrix7 << std::endl;

    return 0;
}