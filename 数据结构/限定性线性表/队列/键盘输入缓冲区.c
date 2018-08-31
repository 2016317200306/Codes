#include<stdio.h>
#include<conio.h>
#define Max 50

//����
typedef struct{
    char elem[Max];
    int front;
    int rear;
}SeqQueue;

//��ʼ��
void Initial(SeqQueue *q) {
    q->front = q->rear = q; //��β����
}

//���
int Enter(SeqQueue *q,char x) {
    if((q->rear + 1) % Max == q->front) return 0;//βָ���1׷��ͷָ�룬��ʾ��������
    q->elem[q->rear] = x;
    q->rear = (q->rear + 1) % Max;//����βָ��
    return 1;
}

//����
int Delete(SeqQueue *q,char *x) {//ɾ����ͷ����¼Ϊx
    if(q->front == q->rear) return 0;//����Ϊ��
    *x = q->elem[q->front];
    q->front = (q->front + 1) % Max;
    return 1;
}

int IsEmpty(SeqQueue *q){
    if(q->front == q->rear) return 1;
    else return 0;
}

int main() {
    char ch1,ch2;
    SeqQueue q;
    int f;
    Initial(&q);
    for(;;) {
        for(;;) {
            printf("A");
            if(kbhit()) {
                ch1 = getchar();
                if(ch1 == ';'||ch1 == ',')   break;
                f = Enter(&q,ch1);
                if(f == 0) {
                    printf("ѭ������������");
                    break;
                }
            }
        }
        while(!IsEmpty(&q)) {
            Delete(&q,&ch2);
            putchar(ch2);
        }
        if(ch1 == ';')  break;
    }
    return 0;
}
