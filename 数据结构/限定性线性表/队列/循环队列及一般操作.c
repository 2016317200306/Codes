#include<stdio.h>
#define Max 50

//����
typedef struct{
    int elem[Max];
    int front;
    int rear;
}SeqQueue;

//��ʼ��
void Initial(SeqQueue *q) {
    q->front = q->rear = q; //��β����
}

//���
int Enter(SeqQueue *q,int x) {
    if((q->rear + 1) % Max == q->front) return 0;//βָ���1׷��ͷָ�룬��ʾ��������
    q->elem[q->rear] = x;
    q->rear = (q->rear + 1) % Max;//����βָ��
    return 1;
}

//����
int Delete(SeqQueue *q,int *x) {//ɾ����ͷ����¼Ϊx
    if(q->front == q->rear) return 0;//����Ϊ��
    *x = q->elem[q->front];
    q->front = (q->front + 1) % Max;
    return 1;
}

//�ж��Ƿ�Ϊ��
int IsEmpty(SeqQueue *q) {
    if(q->front == q->rear) return 1;
    else return 0;
}
