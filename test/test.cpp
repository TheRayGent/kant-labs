#include <iostream>
#include <initializer_list>
#include <string>
using namespace std;

class MyList{
private:
    struct Node{
        int data;
        Node * next;
        Node * prev;
    };
public:
    Node * sent;

    // Adding a node to the end of a list
    int append(int data){
        Node * last = sent->prev;
        Node * p = new Node;
        p->data = data;
        p->prev = last;
        p->next = sent;
        sent->prev = p;
        last->next = p;
        return p->data;
    }

    MyList(initializer_list<int> list = {}){
        sent = new Node;
        sent->next = sent;
        sent->prev = sent;
        if(list.size() != 0)
            for(int value: list)
                append(value);
            
    }

    ~MyList(){
        for(Node * i = sent->next; i!=sent;){
            i = i->next;
            delete i->prev;
        }
        delete sent;
    } 

    // Clearing the list of all elements (except the list sentinel)
    void clear(){
        for(Node * i = sent->next; i!=sent;){
            i = i->next;
            delete i->prev;
        }
        sent->next = sent;
        sent->prev = sent;
    }


    string getList(){
        string list = "";
        list+="[";
        for(Node * i = sent->next; i!=sent; i = i->next){
            list+=to_string(i->data);
            if(i->next != sent) 
                list+=", ";
        }
        list+="]";
        return list;
    }

    
};

int main(){
    MyList a = {1, 2, 3};
    cout << a.getList();
}