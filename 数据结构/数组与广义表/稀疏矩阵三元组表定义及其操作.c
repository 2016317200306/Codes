#include<stdio.h>
#define Max 100

//定义
typedef struct {
    int row,col;//行、列下标
    ElementType e;
}Triple;

typedef struct {
    Triple data[Max+1];//data[0]未用
    int m,n,len;//行列数，非零元素个数
}TSMatrix;

//转置

//常用
void TransMatrix(elementType source[m][n],elementType dest[n][m]) {//dest存放转置后的矩阵
    int i,j;
    for(i = 0;i < m;i++) {
        for(j = 0;j < n;j++)
            dest[j][i] = source[i][j];
    }
}

//三元组实现

//列序递增
void TransposeTSMatrix(TSMatrix A,TSMatrix *B) {
    int i,j,k;
    B->m = A.n;
    B->n = A.m;
    B->len = A->len;
    if(B->len > 0) {
        j = 1;//记录B中下标值
        for(k = 1;i <= A.len;i++) {
            if(A.data[i].col == k) {
                B->data[j].row = A.data[i].col;//行列互换
                B->data[j].col = A.data[i].row;
                B->data[j].e = A.data[i].e;//元素互换
                j++;
            }
        }
    }
}

//一次定位快速转置
void FastTransTSMatrix(TSMatrix A,TSMatrix *B) {
    int col,t,p,q;
    int num[Max],position[Max];
    B->len = A.len;
    B->n = A.m;
    B->m = A.n;
    if(B->len) {
        for(col = 1;col <= A.n;col++)   num[col] = 0;
        for(t = 1;t <= A.len;t++)   num[A.data[t].col]++;
        position[1] = 1;
        for(col = 2;col <= A.n;col++)   position[col] = position[col - 1] + num[col - 1];
        for(p = 1;p <= A.n;p++) {
            col = A.data[p].col;
            q = position[col];
            B->data[q].row = A.data[p].col;
            B->data[q].col = A.data[p].row;
            B->data[q].e = A.data[p].e;
            position[col]++;
        }
    }
}
