#include <iostream>
#include "list.h"
using namespace std;
int main() {
    List l;
    Node* a = new Node("a", "1");
    Node* b = new Node("b", "2");
    Node* c = new Node("c", "3");
    cout << "当前链表是否为空表" << l.empty() << endl;
    cout << "当前链表的大小为" << l.size() << endl;
    l.addToHead(c);
    l.addToHead(a);
    l.addToHead(b);
    for (Node* p = l.front();p != l.end();p = p->next()) {
        cout << p->key() << endl;
    }
    l.removeNode(b);
    delete b;
    for (Node* p = l.front();p != l.end();p = p->next()) {
        cout << p->key() << endl;
    }
    cout << "当前链表的大小为" << l.size() << endl;
    l.moveToHead(c);
    for (Node* p = l.front();p != l.end();p = p->next()) {
        cout << p->key() << endl;
    }
    cout << "当前链表的大小为" << l.size() << endl;
    while (!l.empty())
    {
        Node* p = l.front();
        l.removeNode(p);
        delete p;
    }
    cout << l.empty() << " " << l.size() << endl;
    return 0;
}
