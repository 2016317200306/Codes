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

int ExpEvaluation() {
    SeqStack OPTR,OVS,OPSet;
    Initial(&OPTR);
    Initial(&OVS);
    Push(&OPTR,'#');
    printf("\n \n Please input an expression (Ending with #):");
    ch = getchar();
    while(ch != '#' || GetTop(OPTR) != '#') {
        if(!In(ch,OPSet)) {
            n = GetNumber(ch);
            Push(&OVS,n);
            ch = getchar();
        }
        else
        switch(Compare(ch,GetTop(OPTR))) {
        case '>':
            Push(&OPTR,ch);
            ch = getchar();
            break;
        case '=':
        case '<':
            pop(&OPTR,&op);
            pop(&OVS,&b);
            pop(&OVS,&a);
            v = Execute(a,op,b);
            Push(&OVS,v);
            break;
        }
    }
    v = GetTop(OVS);
    return v;
}
