#include<stdio.h>

//����
typedef struct Node {
    struct Node * next;
    char data;
}Node,*LinkList;

//��ʼ��
void InitCLinkList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = *L;
}

//����
void CreateCLinkList(LinkList L) {
    Node *rear,*s;
    char c;
    rear = L;
    c = getchar();
    while(c != NULL) {
        s = (Node *)malloc(sizeof(Node));
        s->data = c;
        rear->next = s;
        rear = s;
        c = getchar();
    }

    rear->next = L;

}

int main() {
    LinkList a,b,c,d;
    Node *pa,*pb,*pc,*pd;
    InitCLinkList(&b);
    InitCLinkList(&c);
    InitCLinkList(&d);
    printf("Input elements in a:");
    CreateCLinkList(a);
    pa = a->next;
    if(pa->next!=a) {
        if(pa->data)
        pa = pa->next;
    }


    return 0;
}
