#include<stdio.h>

//����
typedef struct Node {
    int data;
    struct Node *next;
}LinkQueueNode;

typedef struct{
    LinkQueueNode *front;
    LinkQueueNode *rear;
}LinkQueue;

//��ʼ��
int Initial(LinkQueue *q) {
    q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(q->front != NULL){
        q->rear = q->front;
        q->front->next = NULL;
        return 1;
    }
    else return 0;
}

//���
int Enter(LinkQueue *q,int *x) {
    LinkQueueNode *p;
    if(q->front == q->rear) return 0;
    p = q->front->next;
    q->front->next = p->next;
    if(q->rear == p)    q->rear = q->front;
    *x = p->data;
    free(p);
    return 1;
}

//����
int Delete(LinkQueue *q,int *x) {
    LinkQueueNode *p;
    if(q->front == q->rear) return 0;
    p = q->front->next;
    q->front->next = p->next;   //��ͷԪ��p����
    if(q->rear == p)    q->rear = q->front; //������ֻ��һ��Ԫ��p����p���Ӻ��Ϊ�ն�
    *x = p->data;
    free(p);
    return 1;
}
