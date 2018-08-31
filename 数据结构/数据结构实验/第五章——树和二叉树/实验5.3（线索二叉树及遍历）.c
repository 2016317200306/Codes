#include<stdio.h>
#include<malloc.h>

typedef struct BiThrNode {
    char data;
    struct BiThrNode *lchild,*rchild;   //����ָ��
    int LTag,RTag;                      //���ұ�־
}BiThrNode,*BiThrTree;

BiThrTree pre;                          //ȫ�ֱ�����ָʾ��һ���

//������������������ķǵݹ鷽��
void InOrderTraverse(BiThrTree T) {
    BiThrNode *p;
    p = T->lchild;                      //pָ����ڵ�
    while(p != T) {                     //�������������ʱ��p==T
        while(p->LTag == 0) p = p->lchild;
                                        //��һ�����
        printf("%c ",p->data);
        while(p->RTag == 1 && p->rchild != T) {
            p = p->rchild;              //���ʺ�̽ڵ�
            printf("%c ",p->data);
        }
    p = p->rchild;                      //p������������
    }
}

//����pΪ���ķǿն���������������
void InThreading(BiThrTree p) {
    if(p) {
        InThreading(p->lchild);         //������������
        if(!p->lchild){                 //����ǰ������
            p->LTag = 1;
            p->lchild = pre;
        }
        else p->LTag = 0;

        if(!p->rchild)  p->RTag = 1;
        else p->RTag = 0;

        if(!pre->rchild) {               //�����������
            pre->RTag = 1;
            pre->rchild = p;
        }
        else p->RTag = 0;
        pre = p;
        InThreading(p->rchild);          //������������
    }
}

//����������������
int InOrderThreading(BiThrTree *Thrt,BiThrTree T) {
    if(!((*Thrt) = (BiThrNode *)malloc(sizeof(BiThrNode))))      return 0;
    (*Thrt)->LTag = 0;
    (*Thrt)->rchild = (*Thrt);                //���ͷ���
    if(!T) {
        (*Thrt)->lchild = (*Thrt);
        (*Thrt)->rchild = (*Thrt);
    }
    else {
        (*Thrt)->lchild = T;
        pre = (*Thrt);
        InThreading(T);                 //����TΪ���ķǿն���������������
        pre->rchild = (*Thrt);             //�������һ���ڵ�
        pre->RTag = 1;
        (*Thrt)->rchild = pre;
    }
    return 1;
}

//�����������
void CreateBiThrTree(BiThrTree *T) {
    char x;
    scanf("%c",&x);
    if(x == ' ')    (*T) = NULL;
    else {
        (*T) = (BiThrNode *)malloc(sizeof(BiThrNode));
        (*T)->data = x;                    //���ɸ��ڵ�
        CreateBiThrTree(&(*T)->lchild);     //����������
        CreateBiThrTree(&(*T)->rchild);     //����������
    }
}

int main() {
    BiThrTree ThrTree,h;
    printf("��������������ַ����У��ո��ʾ������\n");
    CreateBiThrTree(&ThrTree);
    InOrderThreading(&h,ThrTree);          //����������������
    printf("����������������ɣ�\n");
    printf("����������������������\n");
    InOrderTraverse(h);                 //������������������ķǵݹ��㷨
    printf("\n");
    return  0;
}
