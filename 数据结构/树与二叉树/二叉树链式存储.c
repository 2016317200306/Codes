#include<stdio.h>

typedef struct Node{
    int data;
    struct Node *LChild;
    struct Node *RChild;
}BiTNode,*BiTree;

void Visit(int i) {
    printf("%d ",i);
}

void PreOrder(BiTree root) {
    if(root != NULL) {
        Visit(root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}

void InOrder(BiTree root) {
    if(root != NULL) {
        InOrder(root->LChild);
        Visit(root->data);
        InOrder(root->RChild);
    }
}

void PostOrder(BiTree root) {
    if(root != NULL) {
        PostOrder(root->LChild);
        PostOrder(root->RChild);
        Visit(root->data);
    }
}

void leaf(BiTree root) {
    int count;
    if(root != NULL) {
        leaf(root->LChild);
        leaf(root->RChild);
        if(root->LChild == NULL && root->RChild == NULL)    count++;
    }

}

int Leaf(BiTree root) {
    int count;
    if(root == NULL) count = 0;
    else if((root->LChild == NULL)&&(root->RChild == NULL)) count = 1;
    else count = Leaf(root->LChild) + Leaf(root->RChild);
    return count;
}
