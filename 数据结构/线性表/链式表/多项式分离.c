#include<stdio.h>

//����
typedef struct PolyNode {
    struct PolyNode * next;
    int coef;//ϵ��
    int exp;//ָ��
}PolyNode,*PolyList;

//����
PolyList PoleCreate() {
    PolyNode *head,*rear,*s;
    int c,e;
    head = (PolyNode *)malloc(sizeof(PolyNode));
    rear = head;
    scanf("%d %d",&c,&e);
    while(c!=0) {//����0 0����
        s = (PolyNode *)malloc(sizeof(PolyNode));
        s->coef = c;
        s->exp = e;
        rear->next = s;
        rear = s;
        scanf("%d %d",&c,&e);
    }
    rear->next = NULL;
    return head;
}
