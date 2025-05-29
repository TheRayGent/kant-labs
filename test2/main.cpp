#include <iostream>
#include <vector>
using namespace std;

class VectorBool{
    vector<unsigned char> vectorbool;
    size_t v_size;
public:
    VectorBool(size_t n): v_size(n), vectorbool((n+7)/8,0){}

    bool get(size_t n){
        _ASSERT_EXPR(!(n>=v_size), L"index out of range");
        // return vectorbool[n/8];
        return (vectorbool[n/8]>>(7-(n%8)))&1;
    }
    
    void set(size_t n, bool value){
        _ASSERT_EXPR(!(n>=v_size), L"index out of range");
        if (value)
            vectorbool[n/8] |= 1<<(7-(n%8));
        else
            vectorbool[n/8] &= ~(1<<(7-(n%8)));
    }

    

    void insert(size_t n, bool value){
        _ASSERT_EXPR(!(n>v_size), L"index out of range");
        if (v_size%8==0) vectorbool.resize(vectorbool.size()+1);
        v_size++;
        if (v_size-1 == n) {
            set(n, value);
            return;
        }
        for (size_t i = v_size-1; i>n+1; i--){
            set(i, get(i-1));
        }
        set(n, value);
    }

    void push_back(bool value){
        insert(v_size, value);
    }

    size_t size() {return v_size;}

    void erase(size_t n){
        _ASSERT_EXPR(!(n>=v_size), L"index out of range");
        if (n==(v_size-1)) {
            set(n, 0);
            v_size--;
            return;
        }
        for (size_t i = n; i<(v_size-1); i++){
            set(i, get(i+1));
        }
        set(n, 0);
        v_size--;
    }


};

int main(){
    VectorBool a(8);
    for (int i = 0; i<a.size(); i++)
        cout << a.get(i) << " ";
    cout << endl;
    cout << a.size() << endl;

    a.set(7,1);

    for (int i = 0; i<a.size(); i++)
        cout << a.get(i) << " ";
    cout << endl;
    cout << a.size() << endl;

    a.insert(5, 1);

    for (int i = 0; i<a.size(); i++)
        cout << a.get(i) << " ";
    cout << endl;
    cout << a.size() << endl;

    a.erase(5);

    for (int i = 0; i<a.size(); i++)
        cout << a.get(i) << " ";
    cout << endl;
    cout << a.size() << endl;

    a.push_back(true);

    for (int i = 0; i<a.size(); i++)
        cout << a.get(i) << " ";
    cout << endl;
    cout << a.size() << endl;
    
    a.erase(8);

    for (int i = 0; i<a.size(); i++)
        cout << a.get(i) << " ";
    cout << endl;
    cout << a.size() << endl;
}