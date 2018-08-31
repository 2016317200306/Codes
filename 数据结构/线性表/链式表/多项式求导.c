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


int main() {
    PolyNode *p,*temp;
    PolyList a;
    a = PoleCreate();

    //���ԭ����ʽ
    p = a->next;
    while(p!=NULL) {
        printf("%d %d ",p->coef,p->exp);
        p = p->next;
    }
    printf("\n");

    //��
    p = a->next;
    while(p!=NULL) {
        if(p->exp > 0) {
            p->coef *= p->exp;
            p->exp--;
        }
        else p->coef = 0;
            p = p->next;
    }

    //����󵼺�Ķ���ʽ
    p = a->next;
    while(p!=NULL) {
        printf("%d %d ",p->coef,p->exp);
        p = p->next;
    }

    return 0;
}
