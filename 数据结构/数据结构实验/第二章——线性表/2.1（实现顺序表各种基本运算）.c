#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define Max 20

typedef struct SeqList {
    int elem[Max];
    int length;
}SeqList;

//��ʼ��
int Init_SeqList(SeqList &L) {
    L.length = 0;
    return 1;

}

//����ĳ��Ԫ��
int Locate_SeqList(SeqList &L,int x) {
    int i = 0;
    while(i < L.length&&L.elem[i] != x) {
        i = 0;
        if(i >= L.length)   {printf("˳������޸�Ԫ�أ�\n");return 0;}
        else return 1;
    }
}

//����Ԫ��
int Insert_SeqList(SeqList &L,int i,int x) {
    int j;
    if(L.length <= Max) {
        printf("˳����������޷����в��������\n");
        return 0;
    }
    for(j = L.length;j >= i - 1;j++) {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = x;
    L.length++;
    return 1;
}

//ɾ��Ԫ��
int Delete_SeqList(SeqList &L,int i) {
    int j;
    if((i < 1)||(i > L.length)) {
        printf("ɾ��λ�ò���ȷ��");
        return 0;
    }
    for(j = 1;j < L.length;j++) {
        L.length--;
    }
    return 1;
}

//˳�����ʾ
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
    printf("��ʼ��\n����˳������£�\n");
    Insert_SeqList(L,1,1);
    Insert_SeqList(L,2,2);
    Insert_SeqList(L,3,3);
    Insert_SeqList(L,4,4);
    Display_SeqList(L);
    printf("\n");
    while(i <= 3) {
        printf("\n    ���˵�    \n");
        printf("    1  ����ָ��Ԫ��    \n");
        printf("    2  ����Ԫ�ص�ָ��λ��    \n");
        printf("    3  ɾ��ĳһָ��λ��Ԫ��    \n");
        printf("    0  ��������   \n");
        printf("------------------------------------------------------\n");
        printf("��������ѡ��Ĳ˵���<1,2,3,0>:");
        scanf("%d",&i);
        switch(i) {
        case 1:
            printf("���������Ԫ�أ�");
            scanf("%d",&x);
            j = Locate_SeqList(L,x);
            if(j != 0)  printf("ָ��Ԫ��λ�� = %d\n",j);
            break;
        case 2:
            printf("���������Ԫ��λ�ã�");
            scanf("%d",&k);
            printf("���������Ԫ��ֵ��");
            scanf("%d",&x);
            j = Insert_SeqList(L,k,x);
            if(j != 0) {
                printf("�����˳���������ʾ\n");
                Display_SeqList(L);
                printf("\n");
            }
            break;
        case 3:
            printf("������ɾ��Ԫ��λ�ã�");
            scanf("%d",&k);
            j = Delete_SeqList(L,k);
            if(j !=  0) {
                printf("ɾ����˳���������ʾ\n");
                Display_SeqList(L);
                printf("\n");
            }
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("��������");
        }
    }
}
