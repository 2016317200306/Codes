#include<stdio.h>
#define M 100

typedef struct {
    int Stack[M];//Õ»Çø
    int top[2]; //Á½¸öÕ»¶¥Ö¸Ê¾Æ÷
}DqStack;

//³õÊ¼»¯
void initial(DqStack *s) {
    s->top[0] = -1;
    s->top[1] = M;
}

//½øÕ»
int Push(DqStack *s,int x,int i) {//°ÑxÑ¹ÈëiºÅÕ»
    if(s->top[0] + 1 == s->top[1]) //Õ»Âú
    return 0;
    switch(i) {
    case 0: //0ºÅÕ»
        s->top[0]++;
        s->Stack[s->top[0]] = x;
        break;

    case 1: //1ºÅÕ»
        s->top[1]--;
        s->Stack[s->top[1]] = x;
        break;
    default:
        return 0;
    }
    return 1;
}

//³öÕ»
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
