#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    int i = 0;
    Tree<int> tree;
    int a = 3, b = 4, c = 9, d = 12, e = 2, f = 27, g = 102;
    tree.addElement(a);
    tree.addElement(b);
    tree.addElement(c);
    tree.addElement(d);
    tree.addElement(e);
    tree.addElement(f);
    tree.addElement(g);
    list<int> mylist(tree.accessTree());
    while (!mylist.empty())
    {
        cout << mylist.front() << ",";
        mylist.pop_front();
    }
    return 1;
}
