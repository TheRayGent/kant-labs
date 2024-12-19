#include <iostream>

using namespace std;

// Тип данных, описывающий каждый отдельно взятый узел списка
struct Node
{
    int info;     // полезная информация, хранящаяся в этом узле
    Node * next;  // адрес следующего узла списка
                  // (nullptr, если данный элемент является последним)
};

// Распечатать список
void print_list(Node * top)
{
    Node * p = top;  // Адрес текущего элемента списка
    while (p != nullptr) {
        cout << p->info << " ";  // Печатаем полезную информацию текущего узла
        p = p->next;  // Адрес следующего узла становится текущим
    }
}

// Отсортировать список по убыванию (алгоритм сортировки обменами)
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
            Node * q = new Node;  // Создаём новый узел
            q->info = p->info;    // и заполняем содержимое,
            q->next = p->next;    // а также прописываем адреса.
            p->next = q;
            p = q->next;
        }
        else {
            p = p->next;  // Иначе адрес следующего узла становится текущим.
        }
    }
}

void remove_numbers(Node * &top)
{
    // Если удаляемое число расположено на вершине
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

// Удаление списка
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
    // Объявим переменную, в которой будет храниться адрес
    // первого узла списка (то есть адрес его вершины).
    // Изначально список пуст и узлов у него нет, даже вершины.
    // Поэтому top вначале равняется nullptr.
    Node * top = nullptr;

    int n;    // Количество элементов последовательности,
    cin >> n; // которое мы предварительно читаем с клавиатуры.

    // Первый элемент последовательности читаем отдельно, потому что
    // он разместится в вершине списка.
    int x;
    cin >> x;

    // Создаём вершину списка и размещаем в ней число `x`.
    top = new Node;
    top->info = x;
    top->next = nullptr;

    // Объявим вспомогательную переменную `pp`, в которой будем
    // хранить адрес последнего узла списка.
    // Пока что последний совпадает с первым.
    Node * pp = top;

    // Все остальные элементы последовательности читаем в цикле.
    for (int i = 1; i < n; i++) {
        cin >> x;
        Node * p = new Node;  // Создаём новый узел и получаем его адрес
        pp->next = p;  // Записываем адрес нового узла у предыдущего
        p->info = x;  // Записываем прочитанное число в новый узел
        p->next = nullptr;  // Пока что новый узел последний, и следующего у него нет.
        pp = p;  // на следующей итерации цикла новый узел станет предыдущим
    }

    cout << "Введённый список: ";
    print_list(top);

    cout << endl;

    
    


    
    //cout << have_duplicate_numbers(top);

    if(have_duplicate_numbers(top))
        sort_list(top);
    else{
        remove_numbers(top);
        duplicate_numbers(top);
    }
    cout << "Итоговый список: ";
    print_list(top);

    delete_list(top);

    return 0;
}
