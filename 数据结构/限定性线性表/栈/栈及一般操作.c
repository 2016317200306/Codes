#include<stdio.h>
#define Stack_Size 50


//˳��ջ
typedef struct {
    int elem[Stack_Size];
    int top;
}SeqStack;

//��ʼ��
void Initial(SeqStack *S) {
    S->top = -1;
}

//��ջ
int Push(SeqStack *S,int x) {
    if(S->top == Stack_Size - 1) return 0;
    S->top++;
    S->elem[S->top] = x;
    return 1;
}

//��ջ
int pop(SeqStack *S,int *x) {
    if(S->top == -1) return 0;
    else {
        *x = S->elem[S->top];
        S->top--;
        return 1;
    }
}

//��ȡջ������
int GetTop(SeqStack *S,int *x) {
    if(S->top == -1)    return 0;
    else {
        *x = S->elem[S->top];
        S->top--;
        return 1;
    }
}
