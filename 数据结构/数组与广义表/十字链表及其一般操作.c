#include<stdio.h>

typedef struct OLNode {
    int row,col;
    int value;
    struct OLNode *right,*left; //����Ԫ�������б��б�ĺ������
}OLNode,*OLink;

typedef struct {
    OLink *row_head,*col_head;//����ͷָ������
    int m,n,len;//����������������Ԫ�ظ���
}CrossList;

//����
void Create(CrossList *M) {
    int m,n,t,i,j,e;
    scanf("%d %d %d",&m,&n,&t);
    M->m = m;M->n = n;M->len = t;
    if(!(M->row_head = (OLink *)malloc((m + 1)sizeof(OLink))))  exit(OVERFLOW);
    if(!(M->col_head = (OLink *)malloc((n + 1)sizeof(OLink))))  exit(OVERFLOW);
    M->row_head[] = M->col_head[] = NULL;
    for(scanf("%d %d %d",&m,&n,&t);i!=0;scanf("%d %d %d",&m,&n,&t)) {
        if(!(p = (OLNode *)malloc(sizeof(OLNode)))) exit(OVERFLOW);
        p->row = i;p->col = j;p->value = e;
        if(M->row_head[i] == NULL)  M->row_head[i] = p;
        else {
            q = M->row_head[i];
            while(q->right != NULL&&q->right->col < j)
                q = q->right;
            p->right = q->right;q->right = p;
        }
        if(M->col_head[j] == NULL)  M->col_head[j] = p;
        else {
            q = M->col_head[j];
            while(q->left != NULL&&q->down->cow < i)
                q = q->left;
            p->down = q->down;q->down = p;
        }
    }
}
