#include <iostream>
#include <cstdlib>
#include <stdexcept>
#define INIT_SIZE 100
#define INCREMENT_SIZE 10

template <class T>
class arrayList
{
private:
    T *base;
    int length;
    int listSize;

public:
    void init();
    bool is_empty();
    T at(int const&);
    void push_back(T const&);
    void insert(int const&,T const&);
    T pop();
    void Delete(int const&);
    int remove(T const&);
    int find(T const&);
    void resize();
};

template <class T>
bool arrayList<T>::is_empty()
{
    if(this.length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void arrayList<T>::init()
{
    this.base = (T*)malloc(INIT_SIZE*sizeof(T));
    if(!this.base)
        return;
    this.length = 1;
    this.listSize = INIT_SIZE;
}

template <class T>
T arrayList<T>::at(int const& index)
{
    if(index < this.listSize)
    {
        return this.base[index];
    }
    else
    {
        //throw out_of_range("arrayList<>::at():out of arrayIndexRange");
        return 0xffffffff;
    }
}

template <class T>
void arrayList<T>::push_back(T const& elem)
{
    if(this.length >= this.listSize)
    {
        T *newBase = (T*)realloc(this.base,INCREMENT_SIZE*sizeof(T));
        this.base = newBase;
        this.listSize += INCREMENT_SIZE;
    }
    this.base[this.length++] = elem;
}

template <class T>
void arrayList<T>::insert(int const& index,T const& elem)
{
    if(index < 1 || index > this.length)
    {
        return;
    }
    if(this.length >= this.listSize)
    {
        T *newBase = (T*)realloc(this.base,INCREMENT_SIZE*sizeof(T));
        this.base = newBase;
        this.listSize += INCREMENT_SIZE;
    }
    for(int i = this.length;i>index;i--)
    {
        this.base[i] = this.base[i-1];
    }
    this.base[index] = elem;
    this.length++;
}

template <class T>
T arrayList<T>::pop()
{
    T elem = this.base[this.length-1];
    this.base[this.length-1] = this.base[this.length];
    this.length--;
    return elem;
}

template <class T>
void arrayList<T>::delete(int const& index)
{
    if(index < 1 || index > this.length)
    {
        return;
    }
    this.base[index] = this.base[this.length];
    for(int i = index;i<this.length;i++)
    {
        this.base[i] = this.base[i+1];
    }
    this.length--;
}

template <class T>
int arrayList<T>::remove(T const& elem)
{
    int j = 0;
    for(int i = 0;i<this.length;i++)
    {
        if(this.base[i] == elem)
        {
            j++;
            this.base[i] = this.base[this.length];
            for(int k = i;i<this.length;i++)
            {
                this.base[k] = this.base[k+1];
            }
            this.length--;
        }
    }
    return j;
}

template <class T>
int arrayList<T>::find(T const& elem)
{
    int j;
    for(int i = 0;i<this.length;i++)
    {
        if(this.base[i] == elem)
        {
            j = i;
            break;
        }
    }
    return j;
}

template <class T>
void arrayList<T>::resize()
{
    if(this.length >= this.listSize)
    {
        T *newBase = (T*)realloc(this.base,INCREMENT_SIZE*sizeof(T));
        this.base = newBase;
        this.listSize += INCREMENT_SIZE;
    }
    if(this.listSize == 4*this.length)
    {
        T *newBase = (T*)realloc(this.base,(this.listSize/2)*sizeof(T));
        this.base = newBase;
        this.listSize /= 2;
    }
}

/**
*    void init();
*    bool is_empty();
*    T at(int const&);
*    void push(T const&);
*    void insert(int const&,T const&);
*    T pop();
*    void Delete(int const&);
*    int* remove(T const&);
*    int find(T const&);
*    void resize();
*/
