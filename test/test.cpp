#include <iostream>
#include <initializer_list>
#include <string>
using namespace std;

class MyList {
private:

    struct Node {
        int data;
        Node * next;
        Node * prev;
    };

    Node* sent;

public:

    MyList(initializer_list<int> list = {} ): sent(new Node) {
        sent->next = sent;
        sent->prev = sent;
        for(int value: list)
            append(value);   
    }

    ~MyList() {
        for(Node * i = sent->next; i != sent;) {
            i = i->next;
            delete i->prev;
        }
        delete sent;
    }

    //
    int len = 0;

    // Adding a node to the end of a list
    int append(int data) {
        Node * last = sent->prev;
        Node * p = new Node;
        p->data = data;
        p->prev = last;
        p->next = sent;
        sent->prev = p;
        last->next = p;
        len++;
        return p->data;
    }

    // Clearing the list of all elements (except the list sentinel)
    void clear() {
        for(Node * i = sent->next; i!=sent;) {
            i = i->next;
            delete i->prev;
        }
        sent->next = sent;
        sent->prev = sent;
        len = 0;
    }

    //
    string getListToString() {
        string list = "";
        list+="[";
        for(Node * i = sent->next; i != sent; i = i->next) {
            list += to_string(i->data);
            if(i->next != sent) 
                list += ", ";
        }
        list += "]";
        return list;
    }

    //
    operator string() {
        return getListToString();
    }

    //
    int operator[](int index) {
        Node * node = sent;

        if(index == 0)
            return node->next->data;

        if(index >= len || index < -len)
            index %= len;
            
        if(index < 0) 
            index = len+index;

        if(len/2 >= index+1){
            for(int i = 0; i <= index; i++)
                node = node->next;
        }

        else{
            for(int i = len-1; i >= index; i--)
                node = node->prev;
        }
        return node->data;
    }
};

int main() {
    
}