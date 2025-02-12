#include <iostream>
#include <initializer_list>
#include <string>
#include <crtdbg.h>
using namespace std;

class MyList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
    };

    Node *sent;

    void deleteNode(Node *node)
    {
        if (node == sent)
            return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        len--;
    }

    void addNodesFromList(const MyList &list)
    {
        for (int i = 0; i < list.len; i++)
            append(list[i]);
    }

public:
    //
    int len = 0;

    MyList(initializer_list<int> list = {}) : sent(new Node)
    {
        sent->next = sent;
        sent->prev = sent;
        for (int value : list)
            append(value);
    }

    MyList(const MyList &list) : sent(new Node)
    {
        sent->next = sent;
        sent->prev = sent;
        addNodesFromList(list);
    }

    MyList &operator=(const MyList &list)
    {
        clear();
        addNodesFromList(list);
        return *this;
    }

    MyList &operator+=(const MyList &list)
    {
        addNodesFromList(list);
        return *this;
    }

    MyList operator+(const MyList &list)
    {
        MyList tmp = *this;
        tmp += list;
        return tmp;
    }

    MyList operator*=(const unsigned int factor)
    {
        if (factor == 0)
        {
            clear();
            return *this;
        }
        MyList tmp = *this;
        if (factor > 1)
            for (int i = 0; i < factor - 1; i++)
                addNodesFromList(tmp);
        return *this;
    }

    MyList operator*(const unsigned int factor)
    {
        MyList tmp = *this;
        tmp *= factor;
        return tmp;
    }

    ~MyList()
    {
        for (Node *i = sent->next; i != sent;)
        {
            i = i->next;
            delete i->prev;
        }
        delete sent;
    }

    // Adding a node to the end of a list
    int &append(int data)
    {
        Node *last = sent->prev;
        Node *p = new Node;
        p->data = data;
        p->prev = last;
        p->next = sent;
        sent->prev = p;
        last->next = p;
        len++;
        return p->data;
    }

    int &insert(int index, int data)
    {
        _ASSERT_EXPR(!(index >= len || index < -len), L"index out of range");
        if (index < 0)
            index = len + index;

        Node *prev = sent;
        for (int i = 0; i < index; i++)
            prev = prev->next;
        Node *p = new Node;
        p->data = data;
        p->prev = prev;
        p->next = prev->next;
        prev->next->prev = p;
        prev->next = p;
        len++;
        return p->data;
    }

    // Clearing the list of all elements (except the list sentinel)
    void clear()
    {
        for (Node *i = sent->next; i != sent;)
        {
            i = i->next;
            delete i->prev;
        }
        sent->next = sent;
        sent->prev = sent;
        len = 0;
    }

    //
    string toString() const
    {
        string strlist = "";
        strlist += "[";
        for (Node *i = sent->next; i != sent; i = i->next)
        {
            strlist += to_string(i->data);
            if (i->next != sent)
                strlist += ", ";
        }
        strlist += "]";
        return strlist;
    }

    operator string()
    {
        return toString();
    }

    friend std::ostream &operator<<(std::ostream &os, const MyList &list);

    //
    int &operator[](int index) const
    {
        Node *node = sent;
        _ASSERT_EXPR(!(index >= len || index < -len), L"index out of range");
        if (index < 0)
            index = len + index;
        if (index == 0)
            return node->next->data;
        if (len / 2 >= index + 1)
            for (int i = 0; i <= index; i++)
                node = node->next;
        else
            for (int i = len - 1; i >= index; i--)
                node = node->prev;
        return node->data;
    }
};

std::ostream &operator<<(std::ostream &os, const MyList &list)
{
    os << list.toString();
    return os;
}

int main()
{
    MyList a = {1, 2, 3};
    
    cout << a[-4] << endl;
}