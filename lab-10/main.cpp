#include <iostream>

using namespace std;

// ��� ������, ����������� ������ �������� ������ ���� ������
struct Node
{
    int info;     // �������� ����������, ���������� � ���� ����
    Node * next;  // ����� ���������� ���� ������
                  // (nullptr, ���� ������ ������� �������� ���������)
};

// ����������� ������
void print_list(Node * top)
{
    Node * p = top;  // ����� �������� �������� ������
    while (p != nullptr) {
        cout << p->info << " ";  // �������� �������� ���������� �������� ����
        p = p->next;  // ����� ���������� ���� ���������� �������
    }
}

// ������������� ������ �� �������� (�������� ���������� ��������)
void sort_list(Node * top)
{
    for (Node * a = top; a->next != nullptr; a = a->next){
        for (Node * b = a->next; ; ){
            if (a->info < b->info) swap(a->info, b->info);
            if(b->next == nullptr) break;
            b = b->next;
        }
    }
}


bool have_duplicate_numbers(Node * top)
{
    Node * p = top;
    while (p != nullptr) {
        int q = p->info;
        
        while(q>0){
            int q1 = q/10;
            while(q1>0){
                if(q%10==q1%10) return true;
                q1/=10;
            }
            q/=10;
        }
        
        p = p->next;
    }
    return false;
}

bool start_chet(int a)
{
    while(a/10>0) a/=10;
    if(a%2==0) return true;
    return false;
}

void duplicate_numbers(Node * top)
{
    Node * p = top;
    while (p != nullptr) {
        if (start_chet(p->info)==false) {
            Node * q = new Node;  // ������ ����� ����
            q->info = p->info;    // � ��������� ����������,
            q->next = p->next;    // � ����� ����������� ������.
            p->next = q;
            p = q->next;
        }
        else {
            p = p->next;  // ����� ����� ���������� ���� ���������� �������.
        }
    }
}

void remove_numbers(Node * &top)
{
    // ���� ��������� ����� ����������� �� �������
    while (top != nullptr && start_chet(top->info)) {
        Node * temp = top->next;
        delete top;
        top = temp;
    }

    Node * p = top;
    while (p != nullptr && p->next != nullptr) {
        Node * temp = p->next;
        if (start_chet(temp->info)) {
            p->next = temp->next;
            delete temp;
        }
        else {
            p = temp;
        }
    }
}

// �������� ������
void delete_list(Node * top)
{
    Node * p = top;
    while (p != nullptr) {
        Node * temp = p->next;
        delete p;
        p = temp;
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    // ������� ����������, � ������� ����� ��������� �����
    // ������� ���� ������ (�� ���� ����� ��� �������).
    // ���������� ������ ���� � ����� � ���� ���, ���� �������.
    // ������� top ������� ��������� nullptr.
    Node * top = nullptr;

    int n;    // ���������� ��������� ������������������,
    cin >> n; // ������� �� �������������� ������ � ����������.

    // ������ ������� ������������������ ������ ��������, ������ ���
    // �� ����������� � ������� ������.
    int x;
    cin >> x;

    // ������ ������� ������ � ��������� � ��� ����� `x`.
    top = new Node;
    top->info = x;
    top->next = nullptr;

    // ������� ��������������� ���������� `pp`, � ������� �����
    // ������� ����� ���������� ���� ������.
    // ���� ��� ��������� ��������� � ������.
    Node * pp = top;

    // ��� ��������� �������� ������������������ ������ � �����.
    for (int i = 1; i < n; i++) {
        cin >> x;
        Node * p = new Node;  // ������ ����� ���� � �������� ��� �����
        pp->next = p;  // ���������� ����� ������ ���� � �����������
        p->info = x;  // ���������� ����������� ����� � ����� ����
        p->next = nullptr;  // ���� ��� ����� ���� ���������, � ���������� � ���� ���.
        pp = p;  // �� ��������� �������� ����� ����� ���� ������ ����������
    }

    cout << "�������� ������: ";
    print_list(top);

    cout << endl;

    
    


    
    //cout << have_duplicate_numbers(top);

    if(have_duplicate_numbers(top))
        sort_list(top);
    else{
        remove_numbers(top);
        duplicate_numbers(top);
    }
    cout << "�������� ������: ";
    print_list(top);

    delete_list(top);

    return 0;
}
