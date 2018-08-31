#include<stdio.h>
#define Stack_Size 50

//顺序栈
typedef struct {
    char elem[Stack_Size];
    int top;
}SeqStack;

//入栈
int Push(SeqStack *S,char *x) {
    if(S->top == Stack_Size - 1) return 0;
    S->top++;
    S->elem[S->top] = x;
    return 1;
}

//出栈
char pop(SeqStack *S) {
    char *x;
    if(S->top == -1) return 0;
    else {
        *x = S->elem[S->top];
        S->top--;
        return *x;
    }
}

//顺序队列
typedef struct Node {
    char data;
    struct Node *next;
}LinkQueueNode;

typedef struct{
    LinkQueueNode *front;
    LinkQueueNode *rear;
}LinkQueue;

//入队
int Enter(LinkQueue *q,char *x) {
    LinkQueueNode *p;
    if(q->front == q->rear) return 0;
    p = q->front->next;
    q->front->next = p->next;
    if(q->rear == p)    q->rear = q->front;
    *x = p->data;

    return 1;
}

//出队
char Delete(LinkQueue *q) {
    char x;
    LinkQueueNode *p;
    if(q->front == q->rear) return '0';
    p = q->front->next;
    q->front->next = p->next;   //队头元素p出队
    if(q->rear == p)    q->rear = q->front; //若队中只有一个元素p，则p出队后成为空队
    x = p->data;

    return x;
}

int main() {
    SeqStack a;
    LinkQueue b;
    char c;
    c = getchar();
    while(c != ' ') {
        Push(&a,&c);
        Enter(&b,&c);
    }
    while(1) {
        if(pop(&a) != Delete(&b)) {
            printf("No!");
            break;
        }
    }

    return 0;
}
