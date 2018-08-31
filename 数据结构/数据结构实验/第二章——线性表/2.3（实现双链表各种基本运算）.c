#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElemType;
typedef struct DLnode{//�ṹ����
    ElemType data;
    struct DLnode *prior;
    struct DLnode *next;
}DLnode,*DLinkList;

//��ʼ��
void Init_DLinkLIst(DLinkList &L) {
    L = (DLnode *)malloc(sizeof(DLnode));
    L->prior = L->next = NULL;
}

//ͷ�巨����
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

//����Ԫ��
int Locate_DLinkList(DLinkList L,ElemType e) {
    int i = 1;
    DLinkList p = L->next;
    while(p != NULL&&p->data != e) {
        i++;
        p = p->next;
    }
    if(p == NULL){
        printf("˫�����в����ڸ�Ԫ�أ�\n");
        return 0;
    }
    else return i;
}

//�ڵ�i��Ԫ��֮ǰ������Ԫ��
int Insert_DLinkList(DLinkList L,ElemType e) {
    int j = 1;
    DLinkList p = L,s;
    while(p != NULL&&j < i) {
        j++;
        p = p->next;
    }
    if(p == NULL) {
        printf("����λ�ò���ȷ��\n");
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

//ɾ��
int Delete_DLinkList(DLinkList &L,int i,ElemType &e) {
    int j = 0;
    DLinkList p = L;
    while(j < i && p != NULL) {
        j++;
        p = p->next;
    }
    if(p == NULL) {
        printf("ɾ��λ�ò���ȷ��\n");
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

//��ʾ
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
    printf("��ʼ��\n����˫�������£�\n");
    Display_DLinkList(L);
    while(i < 4) {
        printf("\n        ���˵�        \n");
        printf("    1  ����ָ��Ԫ��    \n");
        printf("    2  ����Ԫ�ص�ָ��λ��    \n");
        printf("    3  ɾ��ĳһָ��λ��Ԫ��    \n");
        printf("    4  ��������    \n");
        printf("-------------------------------------------\n");
        printf("��������ѡ��Ĳ˵���<1,2,3,4>��");
        scanf("%d",&i);
        switch(i) {
        case 1:
            printf("���������Ԫ�أ�");
            scanf("%d",&x);
            j = Locate_DLinkList(L,x);
            if(j != 0)  printf("ָ��Ԫ��λ��=%d\n",j);
            break;
        case 2:
            printf("���������Ԫ��λ�ú�����ţ�")��
            scanf("%d",&t);
            printf("������Ԫ��ֵ��");
            scanf("%d",&x);
            j = Insert_DLinkList(L,t,x);
            if(j != 0) {
                printf("�����˫����������ʾ��\n");
                Display_DLinkList(L);
            }
            break;
        case 3:
            printf("������ɾ��Ԫ��λ�ã�");
            scanf("%d",&t);
            j = Delete_DLinkList(L,t,e);
            if(j != 0) {
                printf("ɾ����˫����������ʾ��");
                Display_DLinkList(L);
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("��������");
        }
    }
}
