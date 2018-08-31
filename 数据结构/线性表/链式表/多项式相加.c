#include<stdio.h>

typedef struct Polynode {
    int coef;
    int exp;
    struct Polynode *next;
}Polynode,*Polylist;

//β�巨����
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

//��Ӻ���
void PolyAdd(Polylist a,Polylist b) { //���,�����ŵ�a�У�ɾ��b
    Polynode *p,*q,*tail,*temp;
    int sum;
    p = a->next;
    q = b->next;    //��p��q�ֱ�ָ��a��bͷ���
    tail = a;   //tailָ������β�ڵ�
    while(p != NULL && q != NULL) {//��������ûɨ����ʱ
        if(p->exp < q->exp) { //pָ��Ķ���ʽָ��С��q��ʱ����p��������
            tail->next = p;
            tail = p;
            p = p->next;
        }
        else if(p->exp == q->exp) { //p��qָ��Ķ���ʽָ����ͬʱ���������
            sum = p->coef + q->coef;
            if(sum != 0){    //ϵ���ͷ�0��ָ�����
                p->coef = sum;
                tail->next = p;
                tail = p;
                p = p->next;
                temp = q;
                q = q->next;
                free(temp);
            }
            else {//��Ϊ0��ɾ��p��q��ָ�����
                temp = p;
                p = p->next;
                free(temp);

                temp = q;
                q = q->next;
                free(temp);
            }
        }
        else{   //��q�ڵ��������
            tail->next = q;
            tail = q;
            q = q->next;
        }
        if(p != NULL)   //��a���ж���������ڵ���
            tail->next = p;
        else    //����b������
            tail->next = q;
    }
}
