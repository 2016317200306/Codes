#include<stdio.h>
#include<stdlib.h>
#define MaxSize 255

typedef struct BiNode{
    char data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiTree;

//����������
BiTree *CreateBiTreepre(char *str) {
    BiTree *bt,*stack[MaxSize],*p = NULL;
    int top = -1,k,j = 0;
    char ch;
    bt = NULL;
    ch = str[j];
    while(ch != '\0') {
        switch(ch) {
        case '(':{
            top++;
            stack[top] = p;
            k = 1;
            break;
        }
        case ')':{
            top--;
            break;
        }
        case ',':{
            k = 2;
            break;
        }
        default:{
            p = (BiTree *)malloc(sizeof(BiTree));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if(bt == NULL)  bt = p;
            else {
                switch(k){
                case 1:
                    stack[top]->lchild = p;
                    break;
                case 2:
                    stack[top]->rchild = p;
                    break;
                }
            }
        }
        }
        j++;
        ch = str[j];
    }
    return bt;
}

//�������������
void Preorder(BiTree *bt) {
    if(bt != NULL) {
        printf("%c",bt->data);
        Preorder(bt->lchild);
        Preorder(bt->rchild);
    }
}

//�������������
void Inorder(BiTree *bt) {
    if(bt != NULL) {
        Inorder(bt->lchild);
        printf("%c",bt->data);
        Inorder(bt->rchild);
    }
}

//�������������
void Postorder(BiTree *bt) {
    if(bt != NULL) {
        Postorder(bt->lchild);
        Postorder(bt->rchild);
        printf("%c",bt->data);
    }
}

int main() {
    BiTree *bt;
    char choice;
    char *gyb = "a(b(c,d(e,f)),i(j,k(x,y)))";
    int j = 1;
    int x;
    printf("\n***********************************");
    printf("\n* 1--------�������� *");
    printf("\n* 2--------������� *");
    printf("\n* 3--------������� *");
    printf("\n* 4--------������� *");
    printf("\n* 0--------��     �� *");
    printf("\n**********************************\n");
    printf("\n��ѡ��");
    while(j) {
        scanf("%c",&choice);
        if(choice == '1') {
            printf("���������Ķ������Ĺ������ʽ��a(b(c,d(e,f)),i(j,k(x,y)))\n");
            bt = CreateBiTreepre(gyb);
            printf("�����������ɹ���\n");
            printf("\n��ѡ�� ");
        }
        else if(choice == '2') {
            printf("�����������Ϊ��");
            Preorder(bt);
            printf("\n��ѡ��");
        }
        else if(choice == '3') {
            printf("�����������Ϊ��");
            Inorder(bt);
            printf("\n��ѡ��");
        }
        else if(choice == '4') {
            printf("�����������Ϊ��");
            Postorder(bt);
            printf("\n��ѡ��");
        }
        else if(choice == '0') {
            j = 0;
            printf("\t�˳�\n");
        }
    }
    return 0;
}
