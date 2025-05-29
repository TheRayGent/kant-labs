#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
    Node * prev;
};

// Adding a node to the end of a list
Node* nodeappend(Node * sent, int data){
    Node * last = sent->prev;
    Node * p = new Node;
    p->data = data;
    p->prev = last;
    p->next = sent;
    sent->prev = p;
    last->next = p;
    return p;
}

// Clearing the list of all elements (except the list sentinel)
void nodeclear(Node * sent){
    for(Node * i = sent->next; i!=sent;){
        i = i->next;
        delete i->prev;
    }
    sent->next = sent;
    sent->prev = sent;
}

// Printing a list to the console like in Python
void nodeprint(Node * sent, string end = "\n"){
    cout << "[";
    for(Node * i = sent->next; i!=sent; i = i->next){
        cout << i->data;
        if(i->next != sent) cout << ", ";
    }
    cout << "]" << end;
}

// Deleting a list node by pointer
void nodepop(Node * sent, Node * node){
    if(node == sent) return;

    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

Node* nodemax(Node * sent){
    Node * tmp = sent->next;
    Node * maxnode = tmp;
    for(Node * i = tmp->next; i!=sent; i = i->next)
        if(maxnode->data < i->data) maxnode = i;
    return maxnode;
}

Node* nodemax(Node * sent, Node * lastnode){
    Node * tmp = sent->next;
    Node * maxnode = tmp;
    for(Node * i = tmp->next; i!=lastnode; i = i->next)
        if(maxnode->data < i->data) maxnode = i;
    return maxnode;
}

int nodelen(Node* sent){
    int k=0;
    for(Node * i = sent->next; i!=sent; i = i->next)
        k++;
    return k;
}

void nodereverse(Node * sent){
    for(Node * i = sent->next; i!=sent; i = i->prev)
        swap(i->next, i->prev);
    swap(sent->next, sent->prev);
}

// Sort the list in ascending order
void nodesort(Node * sent, bool reverse = false){
    Node * maxnode = sent;
    Node * lastnode = sent;
    for(int i = 0; i<nodelen(sent)-1; i++){
        maxnode = nodemax(sent, lastnode);
        Node* tmp = nodeappend(lastnode, maxnode->data);
        nodepop(sent, maxnode);
        maxnode = tmp;
        lastnode = maxnode;
    }
    if(reverse) nodereverse(sent);
}

bool issortedleft(Node * sent){
    if (sent->next->next != sent)
        for(Node * i = sent->next; i->next != sent; i = i->next){
            int in = i->data;
            while(in>9){
                in /= 10;
            }
            int nextn = i->next->data;
            while(nextn>9){
                nextn /= 10;
            }
            if(in > nextn) return false;
        }
    return true;
}

bool issortedright(Node * sent){
    if (sent->next->next != sent)
        for(Node * i = sent->next; i->next != sent; i = i->next){
            int in = i->data %10;
            int nextn = i->next->data %10;
            if(in > nextn) return false;
        }
    return true;
}

bool haveonlynumbers(int number){
    while(number>0){
        switch (number%10){
            case 6:
            case 7:
            case 8:
            case 9:
            case 0:
                return false;
        }
        number /= 10;
    }
    return true;
}

void remover(Node* sent){
    for(Node* i = sent->next; i != sent; i = i->next)
        if(haveonlynumbers(i->data)){
            i = i->next;
            nodepop(sent, i->prev);
        }
}

void dublenodes(Node* sent){
    for(Node * node = sent->next; node != sent; node = node->next){
        int number = node->data;
        bool have68 = false;
        while(number>0){
            switch(number%10){
                case 6:
                case 8:
                    Node * p = new Node;
                    p->data = node->data;
                    p->next = node->next;
                    node->next = p;
                    p->prev = node;
                    p->next->prev = p;
                    have68 = true;
                    break;

            }
            if(have68) {
                node = node->next;
                break;
            }
            number/=10;
        }
    }
}

int main() {
    char *locale = setlocale(LC_ALL, "");

    Node * sent = new Node;
    sent->data = -1;
    sent->next = sent;
    sent->prev = sent;

    int n;
    cout << "Введите кол-во элементов последовательности: ";
    cin >> n;
    cout << "Введите последовательность (можно через пробел): ";

    for(int i = 0, data; i<n; i++){
        cin >> data;
        nodeappend(sent, data);
    }

    cout << "Изначальная последовательность: ";
    nodeprint(sent);

    if(issortedleft(sent) || issortedright(sent)){
        remover(sent);
        dublenodes(sent);
    }
    else 
        nodesort(sent, true);

    cout << "Итоговая последовательность: ";
    nodeprint(sent);

    nodeclear(sent);
    delete sent;
}