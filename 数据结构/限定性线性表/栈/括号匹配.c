#include<stdio.h>
#define Stack_Size 50


//˳��ջ
typedef struct {
    int elem[Stack_Size];
    int top;
}Stack;

//��ʼ��
void Initial(Stack *S) {
    S->top = -1;
}

//��ջ
int Push(Stack *S,int x) {
    if(S->top == Stack_Size - 1) return 0;
    S->top++;
    S->elem[S->top] = x;
    return 1;
}

//��ջ
int pop(Stack *S,int *x) {
    if(S->top == -1) return 0;
    else {
        *x = S->elem[S->top];
        S->top--;
        return 1;
    }
}

//��ȡջ������
int GetTop(Stack *S,int *x) {
    if(S->top == -1)    return 0;
    else {
        *x = S->elem[S->top];
        S->top--;
        return 1;
    }
}

void BracketMatch(char *str) {
    Stack s;
    int i;
    char ch;
    Initial(&s);
    for(i = 0;str[i] != '\0';i++) {
        switch(str[i]){
        case '(':
        case '[':
        case '{':
            Push(&s,str[i]);
            break;
        case ')':
        case '[':
        case '}':
            if(s->top == NULL) {
                printf("right extra!");
                return;
            }
            else {
                GetTop(&s,&ch);
                if(Match(ch,str[i]))    pop(&s,&ch);
                else {
                    printf("not the same!");
                    return;
                }
            }
        }
    }
    if(s->top == NULL)  printf("\n confirmed!");
        else printf("left extra!");
}
