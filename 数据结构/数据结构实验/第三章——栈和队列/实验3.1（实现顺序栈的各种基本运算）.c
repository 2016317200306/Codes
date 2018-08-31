#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
#define ElemType int

typedef struct SqStack{
    ElemType elem[MaxSize]; //栈元素存储空间
    int top;                //栈顶指针
}SqStack;                   //类型名

//初始化
void Init_SqStack(SqStack *s) {
    s->top = -1;
}

//入栈
void Push(SqStack *s,ElemType x) {
    if(s->top < MaxSize - 1) {
        s->top = s->top + 1;
        s->elem[s->top] = x;//栈未满，栈顶指针递增1，元素x入栈
    }
    else printf("栈已满，不能入栈！");//栈满时不能入栈
}

//出栈
int Pop(SqStack *s) {
    ElemType x;
    if(s->top != -1) {              //栈未空，栈顶指针递减1，元素x出栈
        x = s->elem[s->top];
        s->top = s->top - 1;
        return x;
    }
    else {                          //栈空时不能出栈
        printf("栈为空，不能出栈！\n");
        return 0;
    }
}

//读栈顶元素
int Get_Top(SqStack *s,ElemType x) {
    if(s->top != -1) {              //栈非空，将栈顶元素值赋予变量x
        x = s->elem[s->top];
        return 1;
    }
    else {                          //栈为空，返回0
        printf("栈为空！\n");
        return 0;
    }
}

//顺序栈的显示
void Display_SqStack(SqStack *s) {
    int m;
    if(s->top == -1)    printf("顺序栈为空！\n");
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
    printf("初始化\n依次进栈元素为 1 2 3 4： \n");
    printf("从栈顶到栈底元素为： \n");
    Display_SqStack(&s);
    do{
        printf("\n      主菜单             \n");
        printf("     1    入栈             \n");
        printf("     2    出栈             \n");
        printf("     3    读栈顶元素       \n");
        printf("     4    结束程序        \n");
        printf("-----------------------------------------------\n");
        printf("请输入你选择的菜单号<1,2,3,4>:");
        scanf("%d",&cord);
        switch(cord) {
        case 1:
            printf("请输入入栈元素!");
            scanf("%d",&a);
            Push(&s,a);
            printf("由栈顶到栈底元素为：");
            Display_SqStack(&s);
            break;
        case 2:
            x = Pop(&s);
            printf("出栈元素为：%d\n",x);
            printf("由栈顶到栈底元素为：");
            Display_SqStack(&s);
            break;
        case 3:
            y = Get_Top(&s,x);
            printf("栈顶元素为%d:\n",y);
            printf("由栈顶到栈底元素为：");
            Display_SqStack(&s);
            break;
        case 4:exit(0);
                break;
        default:
            printf("输入有误！");

        }
    }while(cord <= 4);
    return 0;
}
