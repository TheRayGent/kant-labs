#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
    Node * prev;
};

void nodeappend(Node * sent, int data){
    Node * last = sent->prev;
    Node * p = new Node;
    p->data = data;
    p->prev = last;
    p->next = sent;
    sent->prev = p;
    last->next = p;
};

void nodeclear(Node * sent){
    for(Node * i = sent->next; i!=sent;){
        i = i->next;
        delete i->prev;
    }
    sent->next = sent;
    sent->prev = sent;
};

void nodeprint(Node * sent, string end = "\n"){
    cout << "[";
    for(Node * i = sent->next; i!=sent; i = i->next){
        cout << i->data;
        if(i->next != sent) cout << ", ";
    }
    cout << "]" << end;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Node * sent = new Node;
    sent->data = -1;
    sent->next = sent;
    sent->prev = sent;

    int n;
    cout << "¬ведите кол-во элементов последовательности: ";
    cin >> n;
    cout << "¬ведите последовательность (можно через пробел): ";

    for(int i = 0, data; i<n; i++){
        cin >> data;
        nodeappend(sent, data);
    }
    cout << "»значальна€ последовательность: ";
    nodeprint(sent);
    
    nodeclear(sent);
    delete sent;
}