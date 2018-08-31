#include<stdio.h>
#include<malloc.h>

typedef struct BiThrNode {
    char data;
    struct BiThrNode *lchild,*rchild;   //左右指针
    int LTag,RTag;                      //左右标志
}BiThrNode,*BiThrTree;

BiThrTree pre;                          //全局变量，指示上一结点

//中序遍历线索二叉树的非递归方法
void InOrderTraverse(BiThrTree T) {
    BiThrNode *p;
    p = T->lchild;                      //p指向根节点
    while(p != T) {                     //空树或遍历结束时，p==T
        while(p->LTag == 0) p = p->lchild;
                                        //第一个结点
        printf("%c ",p->data);
        while(p->RTag == 1 && p->rchild != T) {
            p = p->rchild;              //访问后继节点
            printf("%c ",p->data);
        }
    p = p->rchild;                      //p进入右子树根
    }
}

//对以p为根的非空二叉树进行线索化
void InThreading(BiThrTree p) {
    if(p) {
        InThreading(p->lchild);         //左子树线索化
        if(!p->lchild){                 //建立前驱线索
            p->LTag = 1;
            p->lchild = pre;
        }
        else p->LTag = 0;

        if(!p->rchild)  p->RTag = 1;
        else p->RTag = 0;

        if(!pre->rchild) {               //建立后继线索
            pre->RTag = 1;
            pre->rchild = p;
        }
        else p->RTag = 0;
        pre = p;
        InThreading(p->rchild);          //右子树线索化
    }
}

//建立中序线索链表
int InOrderThreading(BiThrTree *Thrt,BiThrTree T) {
    if(!((*Thrt) = (BiThrNode *)malloc(sizeof(BiThrNode))))      return 0;
    (*Thrt)->LTag = 0;
    (*Thrt)->rchild = (*Thrt);                //添加头结点
    if(!T) {
        (*Thrt)->lchild = (*Thrt);
        (*Thrt)->rchild = (*Thrt);
    }
    else {
        (*Thrt)->lchild = T;
        pre = (*Thrt);
        InThreading(T);                 //对以T为根的非空二叉树进行线索化
        pre->rchild = (*Thrt);             //处理最后一个节点
        pre->RTag = 1;
        (*Thrt)->rchild = pre;
    }
    return 1;
}

//先序次序建立树
void CreateBiThrTree(BiThrTree *T) {
    char x;
    scanf("%c",&x);
    if(x == ' ')    (*T) = NULL;
    else {
        (*T) = (BiThrNode *)malloc(sizeof(BiThrNode));
        (*T)->data = x;                    //生成根节点
        CreateBiThrTree(&(*T)->lchild);     //生成左子树
        CreateBiThrTree(&(*T)->rchild);     //生成右子树
    }
}

int main() {
    BiThrTree ThrTree,h;
    printf("按先序次序输入字符序列，空格表示空树：\n");
    CreateBiThrTree(&ThrTree);
    InOrderThreading(&h,ThrTree);          //建立中序线索链表
    printf("二叉线索链表构建完成！\n");
    printf("二叉线索树中序遍历结果：\n");
    InOrderTraverse(h);                 //中序遍历二叉线索树的非递归算法
    printf("\n");
    return  0;
}
