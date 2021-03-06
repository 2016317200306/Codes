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

void Doctor(){
    SeqQueue q;
    int flag,n;
    char ch;
    Initial(&q);
    flag = 1;
    while(flag) {
        printf("\n 请输入命令：");
        ch = getchar();
        switch(ch){
        case 'a':
            printf("\n病历号：");
            scanf("%d",&n);
            Enter(&q,n);
            break;
        case 'n':
            if(!IsEmpty(&q)){
                Delete(&q,&n);
                printf("\n病历号为%d的病人就诊",n);
            }
            else printf("无病人就诊");
            break;
        case 'q':
            printf("\n今天停止挂号,下列病人依次就诊");
            while(!IsEmpty(&q)) {
                Delete(&q,&n);
                printf("%d",n);
            }
            flag = 0;
            break;
        default:
            printf("\n 非法命令");
        }
    }
}
