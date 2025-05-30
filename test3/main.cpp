#include <iostream>
//#include <stdexcept>

template <typename T, size_t N, size_t M>
class Matrix
{
private:
    T data[N][M];

public:
    // ������� �����������
    Matrix()
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                data[i][j] = T(); // ������������� ��������� �� ��������� ��� ���� T
            }
        }
    }

    // ����������� �����������
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

    // �������� ������������ ������������
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

    // �������� �����
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

    // �������� ������
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

    // �������� +
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

    // �������� +=
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

    // �������� * (��������� �� ������)
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

    // �������� *= (��������� �� ������)
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

    // �������� ��������� ������ (��� N=M=2 � N=M=3)
    template <size_t K> //  ����������� ������� ��������
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

    // �������� ++ (����������)
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

    // �������� ++ (�����������)
    Matrix operator++(int)
    {
        Matrix temp = *this;
        ++(*this);
        return temp;
    }

    // // ����� ���������� ������������ (������ ��� ���������� ������)
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

    // �������� ������� � �������� �������
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
    // ������ �������������
    Matrix<int, 2, 2> matrix1;
    Matrix<int, 2, 2> matrix2;

    std::cout << "������� �������� ������ ������� 2x2:" << std::endl;
    std::cin >> matrix1;

    std::cout << "������� �������� ������ ������� 2x2:" << std::endl;
    std::cin >> matrix2;

    std::cout << "������� 1:" << std::endl;
    std::cout << matrix1 << std::endl;

    std::cout << "������� 2:" << std::endl;
    std::cout << matrix2 << std::endl;

    Matrix<int, 2, 2> sum = matrix1 + matrix2;
    std::cout << "����� ������:" << std::endl;
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

    std::cout << "������������ matrix3:" << std::endl;
    std::cout << matrix3.determinant() << std::endl;

    std::cout << "������� matrix3[0][1]: " << matrix3(0, 1) << std::endl;
    matrix3(0, 1) = 100;
    std::cout << "���������� ������� matrix3[0][1]: " << matrix3(0, 1) << std::endl;
    std::cout << "matrix3:" << std::endl;
    std::cout << matrix3 << std::endl;

    // ������ � �������� 3x3
    Matrix<double, 3, 3> matrix4;
    std::cout << "\n������� �������� ������� 3x3:" << std::endl;
    std::cin >> matrix4;
    std::cout << "������� 4:" << std::endl;
    std::cout << matrix4 << std::endl;
    std::cout << "������������ matrix4:" << std::endl;
    std::cout << matrix4.determinant() << std::endl;

    // ������ � ���������� ������
    Matrix<int, 2, 3> matrix5;
    Matrix<int, 3, 2> matrix6;

    std::cout << "\n������� �������� ������� 2x3:" << std::endl;
    std::cin >> matrix5;
    std::cout << "������� �������� ������� 3x2:" << std::endl;
    std::cin >> matrix6;

    Matrix<int, 2, 2> matrix7 = matrix5 * matrix6;
    std::cout << "matrix5 * matrix6:" << std::endl;
    std::cout << matrix7 << std::endl;

    return 0;
}