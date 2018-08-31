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

void Doctor(){
    SeqQueue q;
    int flag,n;
    char ch;
    Initial(&q);
    flag = 1;
    while(flag) {
        printf("\n ���������");
        ch = getchar();
        switch(ch){
        case 'a':
            printf("\n�����ţ�");
            scanf("%d",&n);
            Enter(&q,n);
            break;
        case 'n':
            if(!IsEmpty(&q)){
                Delete(&q,&n);
                printf("\n������Ϊ%d�Ĳ��˾���",n);
            }
            else printf("�޲��˾���");
            break;
        case 'q':
            printf("\n����ֹͣ�Һ�,���в������ξ���");
            while(!IsEmpty(&q)) {
                Delete(&q,&n);
                printf("%d",n);
            }
            flag = 0;
            break;
        default:
            printf("\n �Ƿ�����");
        }
    }
}
