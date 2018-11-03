#ifndef TREEELEMENT_H
#define TREEELEMENT_H

template <class Type>
class TreeElement
{
  private:
    Type &elementData;
    TreeElement *leftElement;
    TreeElement *rightElement;

  public:
    TreeElement(Type &elementData);
    TreeElement *getLeft();
    TreeElement *getRight();
    Type &getElementData();
    bool setLeft(TreeElement *);
    bool setRight(TreeElement *);
    bool setElementData(Type &elementData);
};

template <class Type>
TreeElement<Type>::TreeElement(Type &elementData) : elementData(elementData)
{
    this->leftElement = NULL;
    this->rightElement = NULL;
}

template <class Type>
TreeElement<Type> *TreeElement<Type>::getLeft()
{
    return leftElement;
}

template <class Type>
TreeElement<Type> *TreeElement<Type>::getRight()
{
    return rightElement;
}

template<class Type>
    Type &TreeElement<Type>::getElementData()
{
    return elementData;
}

template <class Type>
bool TreeElement<Type>::setLeft(TreeElement<Type> *left)
{
    if (left == NULL)
        return false;
    this->leftElement = left;
    return true;
}

template <class Type>
bool TreeElement<Type>::setRight(TreeElement<Type> *right)
{
    if (right == NULL)
        return false;
    this->rightElement = right;
    return true;
}

template <class Type>
bool TreeElement<Type>::setElementData(Type &elementData)
{
    this->elementData = elementData;
    return true;
}

#endif
