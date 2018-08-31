#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define Max 100

typedef struct DList{
    int data;
    struct DList *pre,*next;
}DList,*DNode;

void Ini(DNode *d) {
    (*d) = (DNode)malloc(sizeof(DNode));
    (*d)->next = *d;
    (*d)->pre = *d;
    (*d)->data = 0;
}

void output(DNode d) {
    DList *s;
    s = d->next;
    while(s != d) {
        printf("%d ",s->data);
        s = s->next;
    }
    printf("\n");
}

void input(DNode d,int data,int pos) {
    DNode p,s;
    int i;
    s = (DNode)malloc(sizeof(DNode));
    s->data = data;
    p = d->next;
    for(i = 1;i < pos-1;i++) {
        p = p->next;
    }

    s->pre = p;
    s->next = p->next;
    p->next->pre = s;
    p->next = s;

}

void delete(DNode d,int pos){
    int i;
    DNode p;
    p = (DNode)malloc(sizeof(DNode));
    p = d->next;

    for(i = 0;i < pos;i++) {
        p = p->next;
    }

    p->pre->next = p->next;
    p->next->pre = p->pre;

}

int main() {
    DNode d;
    int a,b,c;
    Ini(&d);
    while(1){
    scanf("%d",&a);


        if(a == 0)
        output(d);

        else if(a == 1){
        scanf("%d",&b);
        scanf("%d",&c);
        input(d,c,b);
        }

        else if(a == 2){
        scanf("%d",&b);
        delete(d,b);
        }



    }


    return 0;
}
