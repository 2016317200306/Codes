#include<stdio.h>
#define M 100

typedef struct {
    int Stack[M];//ջ��
    int top[2]; //����ջ��ָʾ��
}DqStack;

//��ʼ��
void initial(DqStack *s) {
    s->top[0] = -1;
    s->top[1] = M;
}

//��ջ
int Push(DqStack *s,int x,int i) {//��xѹ��i��ջ
    if(s->top[0] + 1 == s->top[1]) //ջ��
    return 0;
    switch(i) {
    case 0: //0��ջ
        s->top[0]++;
        s->Stack[s->top[0]] = x;
        break;

    case 1: //1��ջ
        s->top[1]--;
        s->Stack[s->top[1]] = x;
        break;
    default:
        return 0;
    }
    return 1;
}

//��ջ
int pop(DqStack *s,int *x,int i) {
    switch(i) {
    case 0:
        if(s->top[0] == -1) return 0;
        *x = s->Stack[s->top[0]];
        s->top[0]--;
        break;

    case 1:
        if(s->top[1] == M) return 0;
        *x = s->Stack[s->top[1]];
        s->top[1]--;
        break;

    default:
        return 0;
    }
    return 1;
}
