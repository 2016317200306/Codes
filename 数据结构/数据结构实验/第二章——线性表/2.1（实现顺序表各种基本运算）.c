#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define Max 20

typedef struct SeqList {
    int elem[Max];
    int length;
}SeqList;

//初始化
int Init_SeqList(SeqList &L) {
    L.length = 0;
    return 1;

}

//查找某个元素
int Locate_SeqList(SeqList &L,int x) {
    int i = 0;
    while(i < L.length&&L.elem[i] != x) {
        i = 0;
        if(i >= L.length)   {printf("顺序表中无该元素！\n");return 0;}
        else return 1;
    }
}

//插入元素
int Insert_SeqList(SeqList &L,int i,int x) {
    int j;
    if(L.length <= Max) {
        printf("顺序表已满，无法进行插入操作！\n");
        return 0;
    }
    for(j = L.length;j >= i - 1;j++) {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = x;
    L.length++;
    return 1;
}

//删除元素
int Delete_SeqList(SeqList &L,int i) {
    int j;
    if((i < 1)||(i > L.length)) {
        printf("删除位置不正确！");
        return 0;
    }
    for(j = 1;j < L.length;j++) {
        L.length--;
    }
    return 1;
}

//顺序表显示
int Display_SeqList(SeqList L) {
    int i;
    for(i = 0;i < L.length;i++) {
        printf("%d ",L.elem[i]);
    }
    return 1;
}

int main() {
    SeqList L;
    int e,x;
    int i = 1,k,j;
    Init_SeqList(L);
    printf("初始化\n建立顺序表如下：\n");
    Insert_SeqList(L,1,1);
    Insert_SeqList(L,2,2);
    Insert_SeqList(L,3,3);
    Insert_SeqList(L,4,4);
    Display_SeqList(L);
    printf("\n");
    while(i <= 3) {
        printf("\n    主菜单    \n");
        printf("    1  查找指定元素    \n");
        printf("    2  插入元素到指定位置    \n");
        printf("    3  删除某一指定位置元素    \n");
        printf("    0  结束程序   \n");
        printf("------------------------------------------------------\n");
        printf("请输入您选择的菜单号<1,2,3,0>:");
        scanf("%d",&i);
        switch(i) {
        case 1:
            printf("请输入查找元素：");
            scanf("%d",&x);
            j = Locate_SeqList(L,x);
            if(j != 0)  printf("指定元素位置 = %d\n",j);
            break;
        case 2:
            printf("请输入插入元素位置：");
            scanf("%d",&k);
            printf("请输入插入元素值：");
            scanf("%d",&x);
            j = Insert_SeqList(L,k,x);
            if(j != 0) {
                printf("插入后顺序表如下所示\n");
                Display_SeqList(L);
                printf("\n");
            }
            break;
        case 3:
            printf("请输入删除元素位置：");
            scanf("%d",&k);
            j = Delete_SeqList(L,k);
            if(j !=  0) {
                printf("删除后顺序表如下所示\n");
                Display_SeqList(L);
                printf("\n");
            }
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("输入有误！");
        }
    }
}
