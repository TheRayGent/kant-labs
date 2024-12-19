#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const string glas = "aAeEiIoOuUyY";
const string soglas = "bBcCdDfFgGhHjJkKlLmMnNpPqQrRsStTvVwWxXzZ";

bool have_dubl(string mas[1000], int n){
    int k;
    for(int i = 0; i<n; i++){
        k=0;
        for(int j = 0; j<n; j++){
            if(mas[i] == mas[j]){
                k++;
                if(k>1) return true;
            }
        }
    }
    return false;
}

void del_glas(string mas[1000], int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<glas.length(); j++)
            while(mas[i].find(glas[j])!=-1)
                mas[i].erase(mas[i].find(glas[j]), 1);
    }
}

int cout_glas(string a){
    int k=0;
    for(int j = 0; j<glas.length(); j++)
        if(a.find(glas[j])!=-1){
            k++;
        }
    
    return k;
}

void dubl_sogl(string mas[1000], int n){
    
    for(int i = 0; i<n; i++){
        if(cout_glas(mas[i])<=3)
            for(int j = 0; j<mas[i].length(); j++)
                if (soglas.find(mas[i][j])!=-1){
                    string a = "";
                    a += mas[i][j];
                    a += mas[i][j];
                    mas[i].replace(j, 1, a);
                    j++;
                }
            
    }
}

void print_mas(string mas[1000], int n){
    sort(mas, mas+n);
    for(int i = 0; i<n; i++){
        cout << mas[i] << endl;
    }
}

int main() {
    string mas[10000];
    string a, b;
    int n = 0;
    ifstream fin("input.txt");
    while(!fin.eof())
    {
        fin >> mas[n];
        n+=1;
    }
    
    if(have_dubl(mas, n))
        del_glas(mas, n);
    else
        dubl_sogl(mas, n);
    
    print_mas(mas, n);
}