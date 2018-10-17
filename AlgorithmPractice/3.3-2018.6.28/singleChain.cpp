#include<stdio.h>
#include<stdlib.h>
//!因为链表中存放的不是基本数据类型，故需要使用结构体实现自定义
typedef struct Link//!结构体类型名
{
    char elem1;
    int elem2;
    int Array[1024];
    struct Link *next;//!代表指针域，指向直接后继元素
}link;//!结构体变量名

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//!初始化一个链表
link * initLink()
{
    link* p = (link*)malloc(sizeof(link));//!生成头节点
    link* temp = p;//!声明一个指针指向头节点，用于遍历链表

    //!生成链表
    for(int i = 0;i<1024;i++)
    {
        link* a = (link*)malloc(sizeof(link));

        //!其实就是每生成一个链表单元，
        a->elem2 = i;
        a->next = NULL;
        temp->next = a;//!每创建一个链表单元就把它赋给temp，然后再把前一个元素的指针指向当前元素
        temp = temp->next;

        /*
            a.elem2 = i ;
            a.next = NULL;
            temp.next = a;
            temp = temp.next;
        */

    }
    return p;//!将头节点返回，可通过头节点遍历链表
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//!查找链表中的元素
int SearchElem(link* p,int elem)
{
    //!创建一个临时变量temp = 头节点p用于遍历链表
    link* temp = p;
    int i = 0;
    while(temp->next)//!当没有遍历完整个链表时，循环(即元素的next指针不为空NULL)
    {
        temp = temp->next;//!实现遍历
        if(temp->elem2 == i)
        {
            return i;//!若相等即查找到了元素
        }
        i++;
    }
    return -1;//!跳出while循环的条件是遍历了整个链表，没找到查询值
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//!修改某一结点的数据域
link* changeElem(link* p,int position,int newValue)
{
    link* temp = p;
    temp = temp->next;
    for(int i = 0;i<position;i++)
    {
        temp = temp->next;
    }
    temp->elem2 = newValue;
    return p;//!返回新的链表
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//!向链表中插入新节点
link* insertElem(link* p,int position,int newElem)
{
    link* temp = p;
    for(int i = 0;i<position;i++)
    {
        if(temp == NULL)
            return p;
    }
    //!跳出循环的条件是这个位置是有效的
    //!若已经验证此位置有效，则可以将准备插入的节点插入

    temp = temp->next;//!此时temp即为将要插入的点的位置，后期插入只需将temp赋给新创建的结点

    //!创建新的节点
    link* newPoint = (link*)malloc(sizeof(link));
    newPoint->elem2 = newElem;

    //!向链表中插入节点
    newPoint->next = temp->next;

    //!!******************** 每次对节点进行操作的时候，都要将临时指针temp指向变更过的节点 ***********************!!
    temp->next = newPoint;
    return p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//!删除某个结点
link* delElem(link* p,int position)
{
    link* temp = p;

    for(int i = 0;i<position;i++)
    {
        temp = temp->next;//!temp指向被删除的结点的上一个节点
    }
    link* del = temp->next;//!定义一个del指针来保存被删除的结点，用于后面释放内存空间
    temp->next = temp->next->next;//!删除一个结点就是改变其上一个结点的指针域

    free(del);//!释放内存，不然会造成内存泄露，因为用malloc函数申请的内存空间只能手动释放，直到程序结束
    return p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//!输出链表
void output(link* p)
{
    link* temp = p;
    printf("\n/*******************************!\n");
    while(temp->next != NULL)
    {
        printf("%d ",temp->elem2);
        temp = temp->next;
    }
    printf("\n!*******************************/\n");
}
int main()
{
    link* head;
    head = initLink();
    SearchElem(head,1024);
    changeElem(head,1023,1024);
    insertElem(head,1025,1025);
    delElem(head,0);
    output(head);
}


/**
    线性表的储存方式：链式储存 VS 顺序储存

    1. 对内存的利用：链式储存，物理上是在内存中无序的、随机地储存的，无需开辟一块较大的连续的空间。且由于链表每创建一个结点是使用malloc函数创建单个空间(可以利用内存碎片)，故在对资源的使用上效率更高；
                      顺序储存，则必须事先在内存中开辟一块较大的连续的空间，故对内存的利用不充分；

    2. 删除/插入操作的速度：链式储存，只需对指针进行操作，简单；
                             顺序储存，需对块状的数据进行整体的操作，复杂且慢；

    3. 查找的速度：链式储存，由于是逻辑上连续、物理上随机存放，故计算机查找起来速度较慢；
                    顺序储存，由于物理上是连续的，故快；

    *4. 写起来的复杂程度：链式储存，复杂......；
                           顺序储存，快啊；
*/
