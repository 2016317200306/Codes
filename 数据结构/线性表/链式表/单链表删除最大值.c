#include<stdio.h>

//����
typedef struct Node {
    struct Node * next;
    int data;
}Node,*LinkList;

int Delete(LinkList L,int i) {
    Node *pre,*r;
    int k,*e;
    pre = L;
    k = 0;
    while(pre->next!=NULL&&k < i - 1) {
        pre = pre->next;
        k++;
    }
    if(pre->next == NULL) {
        return 0;
    }
    r = pre->next;
    pre->next = r->next;
    *e = r->data;
    free(r);

    return *e;
}

void CreateFromTail(LinkList *L) {
    Node *r,*s;
    int c;
    int flag = 1;
    r = L;
    while(flag) {
        scanf("%d",&c);
        if(c != 0) {
            s = (Node *)malloc(sizeof(Node));
            s->data = c;
            r->next = s;
            r = s;
        }
        else {
            flag = 0;
            r->next = NULL;
        }
    }
}

int FindMax(LinkList *L) {
    Node *s;
    int max = 0;
    s = L;
    if(s->next!=NULL) {
        if(s->data > max)   max = s->data;
        s = s->next;
    }
    return max;
}

Node *Locate(LinkList L,int key) {
    Node *p;
    p = L->next;
    while(p != NULL) {
        if(p->data != key)  p = p->next;
        else break;
    }

    return p;
}

int main() {
    LinkList a;
    Node *k;
    CreateDromHead(&a);
    int max = FindMax(&a);
    k = Locate(a,max);
    printf("%d",Delete(a,k));

    return 0;
}
