#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Lnode{
    int data;
    struct Lnode *next;
}Lnode,*LinkList;

//���ҵ�i��Ԫ��
Lnode *Get_LinkList(LinkList L,int i) {
    Lnode *p = L;
    int j = 0;
    while(p != NULL&&j < i) {
        p = p->next;
        j++;
    }
    return p;
}

int Locate_LinkList(LinkList L,int x) {
    LinkList p;
    int j = 1;
    p = L->next;
    while(p != NULL&&p->data != x){//���ǲ��ҽ������һ��
        p = p->next;
        j++;
    }
    if(p) {
        printf("%d�������У��ǵ�%d��Ԫ�ء�\n",p->data,j);
        return j;
    }
    else {
        printf("����ֵ���������С�\n");
        return 0;
    }
}

//��iλ�ú����x
int Insert_LinkList(LinkList &L,int i,int x) {
    Lnode *p,*s;
    p = Get_LinkList(L,i);
    if(p == NULL) {
        printf("����i��������\n");
        return 0;
    }
    else {
        s = (Lnode *)malloc(sizeof(Lnode));
        s->data = x;
        s->next = p->next;
        p->next = s;
        return 1;
    }
}

//ɾ����i�����
int Delete_LinkList(LinkList L,int i){
    LinkList p,s;
    p = Get_LinkList(L,i - 1);//���ҵ�i-1�����
    if(p == NULL) {
        printf("��ɾ���ǰ��㲻���ڣ�\n");
        return 0;
    }
    else if(p->next == NULL){
        printf("�ý�㲻���ڣ�\n");
        return 0;
    }
    else {
        s = p->next;
        p->next = s->next;
        free(s);
        return 1;
    }
}

//ͷ�巨����������
void Create_LinkLIst(LinkList &L,int n) {
    int i;
    LinkList p;
    L = (LinkList)malloc(sizeof(Lnode));
    L->next = NULL;
    for(i = n;i > 0;--i) {
        p = (LinkList)malloc(sizeof(Lnode));
        p->data = i;
        p->next = L->next;
        L->next = p;
    }
}

//��ʾ
void Display_LinkList(LinkList L) {
    LinkList p;
    p = L;
    while(p->next) {
        printf("%d ",p->data);
        p = p->next;
    }
}

int main(int argc,char *argv[]) {
    printf("��ʼ��\n�������������£�\n");
    LinkList L;
    int x,y,cord,i;
    Create_LinkLIst(L,4);
    Display_LinkList(L);
    do{
        printf("\n        ���˵�        \n");
        printf("    1  β�巨����Ԫ�ص�ָ��λ��   \n");
        printf("    2  ɾ��ĳһָ��Ԫ��    \n");
        printf("    3  ����ָ��Ԫ��    \n");
        printf("    0  ��������    \n");
        printf("---------------------------------------\n");
        printf("��������ѡ��Ĳ˵���<1,2,3,0>:");
        scanf("%d",&cord);
        switch(cord) {
        case 1:
            printf("���������Ԫ��λ��ǰ���i�� ");
            scanf("%d",&x);
            printf("��������������y�� ");
            scanf("%d",&y);
            Insert_LinkList(L,x,y);
            printf("������������£�\n");
            Display_LinkList(L);
            break;
        case 2:
            printf("������ɾ��Ԫ�����x=?");
            scanf("%d",&x);
            Delete_LinkList(L,x);
            printf("������������£�\n");
            Display_LinkList(L);
            break;
        case 3:
            printf("���������Ԫ��ֵx�� ");
            scanf("%d",&x);
            i = Locate_LinkList(L,x);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("��������");
        }
    }while(cord <= 3&&cord >= 0);
    return 0;

}
