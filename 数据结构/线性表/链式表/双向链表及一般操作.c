#include<stdio.h>

typedef struct DNode {
    int data;
    struct DNode *prior,*next;
}DNode,*Doublelist;

//����
int DlinkIns(Doublelist L,int i,int e) {
    DNode *s,*p;
    //���iλ���Ƿ�Ϸ�
    //�ҵ�i��㲢��ָ��ָ����
    s = (DNode *)malloc(sizeof(DNode));
    if(s) {
        s->data = e;
        s->prior = p->prior;
        p->prior->next = s;
        s->next = p;
        p->prior = s;
        return 1;
    }
    else return 0;
}

//ɾ��
int DlinkDelete(Doublelist L,int i,int *e) {
    DNode *p;
    //���i�Ƿ�Ϸ�
    //�ҵ�i��㲢��ָ��ָ����
    *e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return 1;
}
