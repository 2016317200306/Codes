#include<stdio.h>
#define max 100

//����

typedef struct {
    int elem[max];  //������ʽ�洢Ԫ��
    int last;       //��¼���һ��Ԫ��
}SeqList;

//��������


//���Ҵ���λ��ֵ������-1��

int Locate(SeqList L,int e) {
    int i=0;
    while((i <= L.last)&&(L.elem[i] != e))
        i++;
    if(i <= L.last)
        return (i+1);
    else
        return (-1);
}

//��iλ�ò���Ԫ��e

int Insert(SeqList *L,int i,int e) {
    int k;
    if((i < 1) || (i > (*L).last + 2)) {   //�ж��Ƿ�Ϸ�
        printf("��Ч�Ĳ���λ��!");
        return 0;
    }
    for(k = (*L).last;k>=i - 1;k--) {   //Ԫ�غ���
       (*L).elem[k + 1] = (*L).elem[k];
    }
    (*L).elem[i - 1] = e;   //����Ԫ��
    (*L).last++;
    return 1;
}

//ɾ��i��Ԫ�أ�����ֵe

int Delete(SeqList *L,int i,int *e) {
    int k;
    if((i < 1)||(i > (*L).last + 1)) {
        printf("��Ч��λ��!");
        return 0;
    }
    *e = (*L).elem[i - 1];
    for(k = i;i <= (*L).last;k++) {
        (*L).elem[k-1] = (*L).elem[k];  //Ԫ��ǰ��
    }
    (*L).last--;
    return 1;
}

//ɾ���ض�Ԫ��

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
