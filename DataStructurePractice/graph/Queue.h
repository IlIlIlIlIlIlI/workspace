
#include <stdio.h>
#include <stdlib.h>

#define GUARD -99 

typedef int Status;
typedef int QElemType;

typedef struct Node
{
    QElemType data;
    struct Node *next;
} QNode,*LinkQNode; 

 /* 当链式队列的头尾节点指针定义成为一个单独的结构体,避免在新增节点时占用过多的空间 */
typedef struct Queue 
{
    LinkQNode front;
    LinkQNode rear;
} QUEUE,*LinkQueue; 

Status InitQueue(LinkQueue &Q);//初始化链表队列Q
void InQueue (LinkQueue &Q, int elem);//入队
Status PrintQueue(LinkQueue Q);//打印队列Q
void createQueue(LinkQueue &Q);
void GetHead(LinkQueue Q);//输出对头元素
void OutQueue(LinkQueue &Q);//出队
Status EmptyQueue(LinkQueue Q);//判断队列是否为空

 
Status InitQueue(LinkQueue &Q)
{
	LinkQNode p = (LinkQNode)malloc(sizeof(QNode));
    //Q->front = Q->rear = (LinkQNode)malloc(sizeof(QNode));
    Q=new QUEUE;
    Q->front = Q->rear=p;
    Q->rear->next = NULL; //rear.next始终指向NULL,头结点front不动
    return 1;
}
void InQueue (LinkQueue &Q, int elem)
{
    LinkQNode p = (LinkQNode)malloc(sizeof(QNode));
    p->data = elem;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}
Status PrintQueue(LinkQueue Q)
{
    LinkQNode p;
    p = Q->front->next;
    printf("the queue is:");
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    return 1;
}

void createQueue(LinkQueue &Q){
    InitQueue(Q);
    
    int val[100];
    int i=0; 
    int length;
    printf("输入队列，以-99结束: \n"); 
    scanf("%d", &val[i]);
    while(val[i]!=GUARD)
	{
		i++; 
		scanf("%d", &val[i]);	
	}
	length=i;
    
    for(i=0; i<length; i++)
    {
        InQueue(Q,val[i]);
        PrintQueue(Q);
        printf("\n");
    }   //for
}

void GetHead(LinkQueue Q)
{
	LinkQNode p;
    p = Q->front->next;
	if(p!=NULL){
		printf("%d ",p->data);
	}
}

void OutQueue(LinkQueue &Q, int &m)
{
    LinkQNode p;

    p = Q->front;
    Q->front = Q->front->next;
    m = p->data; 
    free(p);
    p = NULL;
}
Status EmptyQueue(LinkQueue Q)
{
    if (Q->front->next == NULL)
        printf("\nThe queue is empty!\n");
    return 1;
}



