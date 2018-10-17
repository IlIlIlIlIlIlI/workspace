#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    LinkList p, r = L;
    string line, word;
    getline(cin, line);
    stringstream stream(line);
    while(stream >> word && i < MAXSIZE)
    {
       p = new LNode;
       p->data = stoi(word);
       p->next = NULL;
       r->next = p;
       r = p;
    }
    return 0;
}
