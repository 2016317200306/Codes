#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
#define ElemType int

typedef struct SqStack{
    ElemType elem[MaxSize]; //ջԪ�ش洢�ռ�
    int top;                //ջ��ָ��
}SqStack;                   //������

//��ʼ��
void Init_SqStack(SqStack *s) {
    s->top = -1;
}

//��ջ
void Push(SqStack *s,ElemType x) {
    if(s->top < MaxSize - 1) {
        s->top = s->top + 1;
        s->elem[s->top] = x;//ջδ����ջ��ָ�����1��Ԫ��x��ջ
    }
    else printf("ջ������������ջ��");//ջ��ʱ������ջ
}

//��ջ
int Pop(SqStack *s) {
    ElemType x;
    if(s->top != -1) {              //ջδ�գ�ջ��ָ��ݼ�1��Ԫ��x��ջ
        x = s->elem[s->top];
        s->top = s->top - 1;
        return x;
    }
    else {                          //ջ��ʱ���ܳ�ջ
        printf("ջΪ�գ����ܳ�ջ��\n");
        return 0;
    }
}

//��ջ��Ԫ��
int Get_Top(SqStack *s,ElemType x) {
    if(s->top != -1) {              //ջ�ǿգ���ջ��Ԫ��ֵ�������x
        x = s->elem[s->top];
        return 1;
    }
    else {                          //ջΪ�գ�����0
        printf("ջΪ�գ�\n");
        return 0;
    }
}

//˳��ջ����ʾ
void Display_SqStack(SqStack *s) {
    int m;
    if(s->top == -1)    printf("˳��ջΪ�գ�\n");
    else {
        for(m = s->top;m >= 0;m--) {
            printf("%2d",s->elem[m]);
            printf("\n");
    }
}

int main() {
    SqStack s;
    int x,y,cord;
    ElemType a;
    Init_SqStack(&s);
    Push(&s,1);
    Push(&s,2);
    Push(&s,3);
    Push(&s,4);
    printf("��ʼ��\n���ν�ջԪ��Ϊ 1 2 3 4�� \n");
    printf("��ջ����ջ��Ԫ��Ϊ�� \n");
    Display_SqStack(&s);
    do{
        printf("\n      ���˵�             \n");
        printf("     1    ��ջ             \n");
        printf("     2    ��ջ             \n");
        printf("     3    ��ջ��Ԫ��       \n");
        printf("     4    ��������        \n");
        printf("-----------------------------------------------\n");
        printf("��������ѡ��Ĳ˵���<1,2,3,4>:");
        scanf("%d",&cord);
        switch(cord) {
        case 1:
            printf("��������ջԪ��!");
            scanf("%d",&a);
            Push(&s,a);
            printf("��ջ����ջ��Ԫ��Ϊ��");
            Display_SqStack(&s);
            break;
        case 2:
            x = Pop(&s);
            printf("��ջԪ��Ϊ��%d\n",x);
            printf("��ջ����ջ��Ԫ��Ϊ��");
            Display_SqStack(&s);
            break;
        case 3:
            y = Get_Top(&s,x);
            printf("ջ��Ԫ��Ϊ%d:\n",y);
            printf("��ջ����ջ��Ԫ��Ϊ��");
            Display_SqStack(&s);
            break;
        case 4:exit(0);
                break;
        default:
            printf("��������");

        }
    }while(cord <= 4);
    return 0;
}
