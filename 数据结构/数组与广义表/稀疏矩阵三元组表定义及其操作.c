#include<stdio.h>
#define Max 100

//����
typedef struct {
    int row,col;//�С����±�
    ElementType e;
}Triple;

typedef struct {
    Triple data[Max+1];//data[0]δ��
    int m,n,len;//������������Ԫ�ظ���
}TSMatrix;

//ת��

//����
void TransMatrix(elementType source[m][n],elementType dest[n][m]) {//dest���ת�ú�ľ���
    int i,j;
    for(i = 0;i < m;i++) {
        for(j = 0;j < n;j++)
            dest[j][i] = source[i][j];
    }
}

//��Ԫ��ʵ��

//�������
void TransposeTSMatrix(TSMatrix A,TSMatrix *B) {
    int i,j,k;
    B->m = A.n;
    B->n = A.m;
    B->len = A->len;
    if(B->len > 0) {
        j = 1;//��¼B���±�ֵ
        for(k = 1;i <= A.len;i++) {
            if(A.data[i].col == k) {
                B->data[j].row = A.data[i].col;//���л���
                B->data[j].col = A.data[i].row;
                B->data[j].e = A.data[i].e;//Ԫ�ػ���
                j++;
            }
        }
    }
}

//һ�ζ�λ����ת��
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
