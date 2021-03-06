#include<stdio.h>

typedef struct Polynode {
    int coef;
    int exp;
    struct Polynode *next;
}Polynode,*Polylist;

//尾插法建立
Polylist PolyCreate() {
    Polynode *head,*rear,*s;
    int c,e;
    head = (Polynode *)malloc(sizeof(Polynode));
    rear = head;
    scanf("%d %d",&c,&e);
    while(c != 0) {
        s = (Polynode *)malloc(sizeof(Polynode));
        s->coef = c;
        s->exp = e;
        rear->next = s;
        rear = s;
        scanf("%d %d",&c,&e);
    }
    rear->next = NULL;
    return head;
}

//相加函数
void PolyAdd(Polylist a,Polylist b) { //相加,结果存放到a中，删除b
    Polynode *p,*q,*tail,*temp;
    int sum;
    p = a->next;
    q = b->next;    //令p，q分别指向a，b头结点
    tail = a;   //tail指向结果的尾节点
    while(p != NULL && q != NULL) {//当两个都没扫描完时
        if(p->exp < q->exp) { //p指向的多项式指数小于q的时，将p加入结果中
            tail->next = p;
            tail = p;
            p = p->next;
        }
        else if(p->exp == q->exp) { //p，q指向的多项式指数相同时，两者相加
            sum = p->coef + q->coef;
            if(sum != 0){    //系数和非0，指针后移
                p->coef = sum;
                tail->next = p;
                tail = p;
                p = p->next;
                temp = q;
                q = q->next;
                free(temp);
            }
            else {//若为0，删除p，q，指针后移
                temp = p;
                p = p->next;
                free(temp);

                temp = q;
                q = q->next;
                free(temp);
            }
        }
        else{   //将q节点加入结果中
            tail->next = q;
            tail = q;
            q = q->next;
        }
        if(p != NULL)   //当a中有多余项，则加入节点中
            tail->next = p;
        else    //否则将b加入结果
            tail->next = q;
    }
}
