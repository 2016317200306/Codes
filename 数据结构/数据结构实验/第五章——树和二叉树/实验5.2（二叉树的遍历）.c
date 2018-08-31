#include<stdio.h>
#include<stdlib.h>
#define MaxSize 255

typedef struct BiNode{
    char data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiTree;

//创建二叉树
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

//先序遍历二叉树
void Preorder(BiTree *bt) {
    if(bt != NULL) {
        printf("%c",bt->data);
        Preorder(bt->lchild);
        Preorder(bt->rchild);
    }
}

//中序遍历二叉树
void Inorder(BiTree *bt) {
    if(bt != NULL) {
        Inorder(bt->lchild);
        printf("%c",bt->data);
        Inorder(bt->rchild);
    }
}

//后序遍历二叉树
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
    printf("\n* 1--------建二叉树 *");
    printf("\n* 2--------先序遍历 *");
    printf("\n* 3--------中序遍历 *");
    printf("\n* 4--------后序遍历 *");
    printf("\n* 0--------退     出 *");
    printf("\n**********************************\n");
    printf("\n请选择：");
    while(j) {
        scanf("%c",&choice);
        if(choice == '1') {
            printf("即将创建的二叉树的广义表形式：a(b(c,d(e,f)),i(j,k(x,y)))\n");
            bt = CreateBiTreepre(gyb);
            printf("二叉树建立成功！\n");
            printf("\n请选择： ");
        }
        else if(choice == '2') {
            printf("先序遍历序列为：");
            Preorder(bt);
            printf("\n请选择：");
        }
        else if(choice == '3') {
            printf("中序遍历序列为：");
            Inorder(bt);
            printf("\n请选择：");
        }
        else if(choice == '4') {
            printf("后序遍历序列为：");
            Postorder(bt);
            printf("\n请选择：");
        }
        else if(choice == '0') {
            j = 0;
            printf("\t退出\n");
        }
    }
    return 0;
}
