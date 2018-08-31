#include<stdio.h>

typedef struct Polynode {
    int coef;
    int exp;
    struct Polynode *next;
}Polynode,*Polylist;

//Î²²å·¨½¨Á¢
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
