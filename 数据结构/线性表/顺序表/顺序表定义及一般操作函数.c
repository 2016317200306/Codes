#include<stdio.h>
#define max 100

//定义

typedef struct {
    int elem[max];  //数组形式存储元素
    int last;       //记录最后一个元素
}SeqList;

//基本操作


//查找传回位置值（否则-1）

int Locate(SeqList L,int e) {
    int i=0;
    while((i <= L.last)&&(L.elem[i] != e))
        i++;
    if(i <= L.last)
        return (i+1);
    else
        return (-1);
}

//在i位置插入元素e

int Insert(SeqList *L,int i,int e) {
    int k;
    if((i < 1) || (i > (*L).last + 2)) {   //判断是否合法
        printf("无效的插入位置!");
        return 0;
    }
    for(k = (*L).last;k>=i - 1;k--) {   //元素后移
       (*L).elem[k + 1] = (*L).elem[k];
    }
    (*L).elem[i - 1] = e;   //插入元素
    (*L).last++;
    return 1;
}

//删除i处元素，返回值e

int Delete(SeqList *L,int i,int *e) {
    int k;
    if((i < 1)||(i > (*L).last + 1)) {
        printf("无效的位置!");
        return 0;
    }
    *e = (*L).elem[i - 1];
    for(k = i;i <= (*L).last;k++) {
        (*L).elem[k-1] = (*L).elem[k];  //元素前移
    }
    (*L).last--;
    return 1;
}

//删除特定元素

int Delete_Special(SeqList *L,int e) {
    int i = 0,j;
    while(i < (*L).last&&(*L).elem[i]!=e) {
        i++;
    }
    for(j = i + 1;j < (*L).last;j++) {
        (*L).elem[i++] = (*L).elem[j];
    }
    (*L).last = i;
}
