#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElemType;
typedef struct DLnode{//结构定义
    ElemType data;
    struct DLnode *prior;
    struct DLnode *next;
}DLnode,*DLinkList;

//初始化
void Init_DLinkLIst(DLinkList &L) {
    L = (DLnode *)malloc(sizeof(DLnode));
    L->prior = L->next = NULL;
}

//头插法创建
void Create_DLinkList(DLinkList &L,int n) {
    int i;
    DLinkList p;
    L = (DLinkList)malloc(sizeof(DLnode));
    L->next = NULL;
    L->prior = NULL;
    for(i = n;i > 0;i++) {
        p = (DLinkList)malloc(sizeof(DLnode));
        p->data = i;
        p->next = L->next;
        L->next = p;
        if(p->next != NULL) p->next->prior = p;
        p->prior = L;
    }
}

//查找元素
int Locate_DLinkList(DLinkList L,ElemType e) {
    int i = 1;
    DLinkList p = L->next;
    while(p != NULL&&p->data != e) {
        i++;
        p = p->next;
    }
    if(p == NULL){
        printf("双链表中不存在该元素！\n");
        return 0;
    }
    else return i;
}

//在第i个元素之前插入新元素
int Insert_DLinkList(DLinkList L,ElemType e) {
    int j = 1;
    DLinkList p = L,s;
    while(p != NULL&&j < i) {
        j++;
        p = p->next;
    }
    if(p == NULL) {
        printf("插入位置不正确！\n");
        return 0;
    }
    else {
        s = (DLnode *)malloc(sizeof(DLnode));
        s->data = e;
        s->prior = p->prior;
        s->next = p;
        p->prior->next = s;
        return 1;
    }
}

//删除
int Delete_DLinkList(DLinkList &L,int i,ElemType &e) {
    int j = 0;
    DLinkList p = L;
    while(j < i && p != NULL) {
        j++;
        p = p->next;
    }
    if(p == NULL) {
        printf("删除位置不正确！\n");
        return 0;
    }
    else {
        e = p->data;
        p->prior->next = p->next;
        if(p->next != NULL) p->next->prior = p->prior;
        free(p);
        return 1;
    }
}

//显示
void Display_DLinkList(DLinkList L) {
    DLinkList p;
    p = L->next;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}

int main(int argc,char *argv[]) {
    DLinkList L;
    int i,j,e,x,t;
    char ch;
    Init_DLinkLIst(L);
    Create_DLinkList(L,4);
    printf("初始化\n建立双链表如下：\n");
    Display_DLinkList(L);
    while(i < 4) {
        printf("\n        主菜单        \n");
        printf("    1  查找指定元素    \n");
        printf("    2  插入元素到指定位置    \n");
        printf("    3  删除某一指定位置元素    \n");
        printf("    4  结束程序    \n");
        printf("-------------------------------------------\n");
        printf("请输入您选择的菜单号<1,2,3,4>：");
        scanf("%d",&i);
        switch(i) {
        case 1:
            printf("请输入查找元素：");
            scanf("%d",&x);
            j = Locate_DLinkList(L,x);
            if(j != 0)  printf("指定元素位置=%d\n",j);
            break;
        case 2:
            printf("请输入插入元素位置后结点序号：")；
            scanf("%d",&t);
            printf("请输入元素值：");
            scanf("%d",&x);
            j = Insert_DLinkList(L,t,x);
            if(j != 0) {
                printf("插入后双链表如下所示：\n");
                Display_DLinkList(L);
            }
            break;
        case 3:
            printf("请输入删除元素位置：");
            scanf("%d",&t);
            j = Delete_DLinkList(L,t,e);
            if(j != 0) {
                printf("删除后双链表如下所示：");
                Display_DLinkList(L);
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("输入有误！");
        }
    }
}
