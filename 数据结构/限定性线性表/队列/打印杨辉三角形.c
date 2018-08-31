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

void Triangle() {
    int i,temp,n,x;
    SeqQueue q;
    Initial(&q);
    Enter(&q,1);//��һ�����
    for(n = 2;n <= Max - 2;i++) {//����n����ӣ���ӡn-1��Ԫ��
        Enter(&q,1);//��n�е�һ��Ԫ�����
        for(i = 1;i <= n - 2;i++){//���ö���n-1��Ԫ�ز�����n�е��м�n-2��Ԫ�ز����
            Delete(&q,&temp);
            printf("%d",temp);//��ӡ��n-1��Ԫ��
            GetHead(q,&x);
            temp += x;//���õ�n-1��Ԫ�ز�����n��Ԫ��
            Enter(&q,temp);
        }
    Delete(&q,&x);
    printf("%d",x);
    Enter(&q,1);
    }
    while(!IsEmpty(q)) {//��ӡ���һ��Ԫ��
        DeleteQueue(&q,&x);
        printf("$d",x);
    }
}
