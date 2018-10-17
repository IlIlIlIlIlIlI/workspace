#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR 0
#define OK 1

typedef struct Stack {
    int *elements;
    int max_size, top_index;
} Stack;

void init(Stack *s, int length_input) {

    s->elements = (int *)malloc(sizeof(int) * length_input);
    s->max_size = length_input;
    s->top_index = -1;
}

int push(Stack *s, int element) {
     if (s->top_index >= s->max_size - 1) {
        return ERROR;
    }
    s->top_index++;
    s->elements[s->top_index] = element;
    return OK;
}

int pop(Stack *s) {
    if (s->top_index < 0) {
        return ERROR;
    }
    s->top_index--;
    return OK;
}

int top(Stack *s) {
       return s->elements[s->top_index];
}

int empty(Stack *s) {
        if (s->top_index < 0) {
        return 1;
    } else {
        return 0;
    }
}

void bfana(Stack *a,Stack *b){
    while(!empty(a)){
        pop(a);
    }
    while(!empty(b)){
        push(a,top(b));
        pop(b);
    }
}

typedef struct {
    Stack *a;
    Stack *b;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
    q->a = (Stack*)malloc(sizeof(Stack));
    q->b = (Stack*)malloc(sizeof(Stack));
    init(q->a,maxSize);
    init(q->b,maxSize);
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    push(obj->a,x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(empty(obj->a)){
        return 0;
    }
    bfana(obj->b,obj->a);
    int q = top(obj->b);
    pop(obj->b);
    bfana(obj->a,obj->b);
    return q;

}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    bfana(obj->b,obj->a);
    int q = top(obj->b);
    bfana(obj->a,obj->b);
    return q;

}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return empty(obj->a);
}

void myQueueFree(MyQueue* obj) {

}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */


typedef struct {
int *base;
int front;
int rear;
int currLen;
int listLen;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
    q->base = (int*)malloc(maxSize*sizeof(int));
    q->front = 0;
    q->rear = 0;
    q->currLen = 0;
    q->listLen = maxSize;
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if(obj->currLen == obj->listLen)
    {
        obj->base = (int*)realloc(obj,(obj->listLen+100)*sizeof(int));
    }
    obj->base[(obj->rear)++] = x;
    obj->currLen++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(obj->currLen)
    {
        obj->currLen--;
        return obj->base[obj->front++];
    }
    else
    {
        return 0xffffffff;
    }
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(obj->currLen)
    {
        return obj->base[obj->front];
    }
    else
    {
        return 0xffffffff;
    }
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(obj->front == obj->rear && obj->currLen == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */
