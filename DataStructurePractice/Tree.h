#include "TreeElement.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <list>

#ifndef TREE_H
#define TREE_H

template <class Type>
class Tree
{
  private:
    TreeElement<Type> *boot;
    int deep;
    int elementCount;
    std::list<Type> mylist;
    void access(TreeElement<Type> *boot);
    void deleteTree(TreeElement<Type> *boot);

  public:
    Tree();
    bool addElement(Type &data);
    bool removeElement(Type &data);
    int getDeep();
    int getElementCount();
    std::list<Type> accessTree();
    ~Tree();
};

template <class Type>
Tree<Type>::Tree()
{
    this->boot = NULL;
    this->deep = 0;
    this->elementCount = 0;
    std::list<Type> mylist;
}

template <class Type>
bool Tree<Type>::addElement(Type &data)
{
    TreeElement<Type> *current, *element;
    current = boot;
    element = new TreeElement<Type>(data);
    if (current == NULL)
    {
        boot = element;
        elementCount++;
        return true;
    }
    while (current != NULL)
    {
        srand((unsigned)time(NULL));
        if (rand() % 2 == 0)
        {
            if (current->getLeft() != NULL)
            {
                current = current->getLeft();
            }
            else
            {
                current->setLeft(element);
                elementCount++;
                return true;
            }
        }
        else
        {
            if (current->getRight() != NULL)
            {
                current = current->getRight();
            }
            else
            {
                current->setRight(element);
                elementCount++;
                return true;
            }
        }
    }
    return true;
}

template <class Type>
bool Tree<Type>::removeElement(Type &data)
{
    return true;
}

template <class Type>
int Tree<Type>::getDeep()
{
    return deep;
}

template <class Type>
int Tree<Type>::getElementCount()
{
    return elementCount;
}

template <class Type>
std::list<Type> Tree<Type>::accessTree()
{
    access(boot);
    return mylist;
}

template <class Type>
void Tree<Type>::access(TreeElement<Type> *curr)
{
    if (curr == NULL)
        return;
    access(curr->getLeft());
    mylist.push_back(curr->getElementData());
    access(curr->getRight());
}

template <class Type>
Tree<Type>::~Tree()
{
    deleteTree(boot);
}

template <class Type>
void Tree<Type>::deleteTree(TreeElement<Type> *curr)
{
    if (curr == NULL)
        return;
    deleteTree(curr->getLeft());
    deleteTree(curr->getRight());
    delete curr;
}
#endif
