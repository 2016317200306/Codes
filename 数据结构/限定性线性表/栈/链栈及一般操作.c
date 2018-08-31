#include<stdio.h>

//����
typedef struct node{
    int data;
    struct node *next;
}LinkStackNode;

typedef LinkStackNode *LinkStack;

//��ջ
int push(LinkStack top,int x) {
    LinkStackNode *temp;
    temp = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    if(temp == NULL)    return 0;
    temp->data = x;
    temp->next = top->next;
    top->next = temp;
    return 1;
}

//��ջ
int pop(LinkStack top,int *x) {
    LinkStackNode *temp;
    temp = top->next;
    if(temp == NULL) return 0;
    top->next = temp->next;
    *x = temp->data;
    free(temp);
    return 1;
}
