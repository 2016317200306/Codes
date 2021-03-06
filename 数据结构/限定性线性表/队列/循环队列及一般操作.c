#include<stdio.h>
#define Max 50

//定义
typedef struct{
    int elem[Max];
    int front;
    int rear;
}SeqQueue;

//初始化
void Initial(SeqQueue *q) {
    q->front = q->rear = q; //收尾相连
}

//入队
int Enter(SeqQueue *q,int x) {
    if((q->rear + 1) % Max == q->front) return 0;//尾指针加1追上头指针，表示队列已满
    q->elem[q->rear] = x;
    q->rear = (q->rear + 1) % Max;//重置尾指针
    return 1;
}

//出队
int Delete(SeqQueue *q,int *x) {//删除队头，记录为x
    if(q->front == q->rear) return 0;//队列为空
    *x = q->elem[q->front];
    q->front = (q->front + 1) % Max;
    return 1;
}

//判断是否为空
int IsEmpty(SeqQueue *q) {
    if(q->front == q->rear) return 1;
    else return 0;
}
