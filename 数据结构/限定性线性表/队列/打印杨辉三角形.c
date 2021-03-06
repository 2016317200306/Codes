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

void Triangle() {
    int i,temp,n,x;
    SeqQueue q;
    Initial(&q);
    Enter(&q,1);//第一行入队
    for(n = 2;n <= Max - 2;i++) {//产生n行入队，打印n-1行元素
        Enter(&q,1);//第n行第一个元素入队
        for(i = 1;i <= n - 2;i++){//利用队中n-1行元素产生第n行的中间n-2个元素并入队
            Delete(&q,&temp);
            printf("%d",temp);//打印第n-1行元素
            GetHead(q,&x);
            temp += x;//利用第n-1行元素产生第n行元素
            Enter(&q,temp);
        }
    Delete(&q,&x);
    printf("%d",x);
    Enter(&q,1);
    }
    while(!IsEmpty(q)) {//打印最后一行元素
        DeleteQueue(&q,&x);
        printf("$d",x);
    }
}
