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

    int _len = 0;

    void deleteNode(Node *node)
    {
        if (node == sent)
            return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        _len--;
    }

    void addNodesFromList(const MyList &list)
    {
        for (int i = 0; i < list._len; i++)
            append(list[i]);
    }

public:
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

    int len() { return _len; }

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
        _len++;
        return p->data;
    }

    int &insert(int index, int data)
    {
        _ASSERT_EXPR(!(index >= _len || index < -_len), L"index out of range");
        if (index < 0)
            index = _len + index;

        Node *prev = sent;
        for (int i = 0; i < index; i++)
            prev = prev->next;
        Node *p = new Node;
        p->data = data;
        p->prev = prev;
        p->next = prev->next;
        prev->next->prev = p;
        prev->next = p;
        _len++;
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
        _len = 0;
    }

    int pop(int index = -1)
    {
        _ASSERT_EXPR(!(index >= _len || index < -_len), L"index out of range");
        if (index < 0)
            index = _len + index;
        Node *node = sent->next;
        for (int i = 0; i < index; i++)
            node = node->next;
        int data = node->data;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        return data;
    }

    void erase(int index)
    {
        pop(index);
    }

    void erase(int index_begin, int index_end)
    {
        _ASSERT_EXPR(!(index_begin >= _len || index_begin < -_len), L"index out of range");
        _ASSERT_EXPR(!(index_end >= _len || index_end < -_len), L"index out of range");
        if (index_begin < 0)
            index_begin = _len + index_begin;
        if (index_end < 0)
            index_end = _len + index_end;
        if (index_begin == index_end)
            return erase(index_begin);
        if (index_begin > index_end)
            swap(index_begin, index_end);
        Node *node_begin = sent;
        for (int i = 0; i < index_begin; i++)
            node_begin = node_begin->next;
        Node *node_end = sent->next;
        for (int i = 0; i < index_end; i++)
            node_end = node_end->next;
        for (Node *i = node_begin->next; i != node_end;)
        {
            i = i->next;
            delete i->prev;
        }
        node_begin->next = node_end;
        node_end->prev = node_begin;
    }

    void resize(unsigned int newsize)
    {
        if (newsize == 0)
        {
            clear();
            return;
        }
        if (newsize == _len)
            return;
        if (newsize < _len)
        {
            erase(newsize, _len);
            return;
        }
        int a =  newsize - _len;
        for (int i = 0; i < a; i++)
        {
            cout << i << endl;
            append(0);
        }
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
        _ASSERT_EXPR(!(index >= _len || index < -_len), L"index out of range");
        if (index < 0)
            index = _len + index;
        if (index == 0)
            return node->next->data;
        if (_len / 2 >= index + 1)
            for (int i = 0; i <= index; i++)
                node = node->next;
        else
            for (int i = _len - 1; i >= index; i--)
                node = node->prev;
        return node->data;
    }

    // Temporary Methods

    int size() { return _len; }

    int capacity() { return _len; }

    bool empty()
    {
        if (sent->next == sent)
            return true;
        return false;
    }

    int &front() { return sent->next->data; }

    int &back() { return sent->prev->data; }

    int &push_back(int data) { return append(data); }
};

std::ostream &operator<<(std::ostream &os, const MyList &list)
{
    os << list.toString();
    return os;
}

int main()
{
    MyList a = {0, 1, 2, 3, 4, 5, 6, 7};
    cout << a << endl;
    a.append(8);
    cout << a << endl;
    a.insert(5, 9);
    cout << a << endl;
    a.resize(15);
    cout << a << endl;
    a.erase(1, 5);
    cout << a << endl;
}
