#include <iostream>
using namespace std;

void write(int** Mas, int n)
{
    setlocale(LC_ALL, "Russian");
    
    for (int i = 0; i<n; i++){
        cout << "¬ведите элементы " << i+1 << "-ой строки: ";
        for (int j = 0; j<n; j++)
            cin >> Mas[i][j];
    }
}

bool ifmax(int* mas_string, int j, int n){
    for (int i = 0; i<n; i++)
        if  (mas_string[j] < mas_string[n]) return false;
    return true;
}

bool ifmaxall(int** Mas, int n){
    for (int i = 0; i<n; i++)
        if (ifmax(Mas[i], i, n) == false) return false;
    return true;
}

bool havezero(int a){
    if (a==0) return true;
    while (a>0){
        if (a%10 == 0) return true;
        a/=10;
    }
    return false;
}

void edit(int** Mas, int n, int prod){
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++){
            if (havezero(Mas[i][j])) {
                Mas[i][j] = prod;
                
        }}
}

void printMas(int** Mas, int n){
    setlocale(LC_ALL, "Russian");
    cout << "»тогова€ матрица: \n";
    for (int i = 0; i<n; i++){
        cout << "[";
        for (int j = 0; j<n; j++){
            cout << Mas[i][j];
            if (j!=n-1) cout << ", ";
        }
        cout << "]\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "¬ведите размер матрицы: ";
    int n;
    cin >> n;
    int** A = new int*[n];
    for (int i = 0; i<n; i++)
        A[i] = new int[n]{0};
    
    write(A, n);

    

    if (ifmaxall(A, n)){
        int prod = 1;
        for (int i = 0; i<n; i++)
            prod *= A[i][i];
        edit(A, n, prod);
    }
        
    printMas(A, n);
    
    for (int i = 0; i<n; i++)
        delete [] A[i];
    delete [] A;
    
}