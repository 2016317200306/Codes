#include<stdio.h>

//ͷβ������
typedef enum {ATOM,LIST} ElemTag;
typedef struct GLNode{
    ElemTag tag;
    union {
        int atom;
        struct {
            struct GLNode * hp,*tp;
        }htp;
    }atom_htp;
}GLNode,*GList;

//ͬ��ڵ���ʽ�洢
typedef enum {ATOM,LIST} ElemTag;
typedef struct GLNode {
    ElemTag tag;
    union {
        int atom;
        struct GLNode *hp;
    }atom_hp;
    struct GLNode *tp;
}GLNode,*GList;

//���ͷ
GList Head(GList L) {
    if(L == NULL)   return NULL;
    if(L->tag == ATOM)  exit(0);
    else return L->atom_htp.htp.hp;
}

//���β
GList Tail(GList L) {
    if(L == NULL)   return NULL;
    if(L->tag == ATOM)  exit(0);
    else return L->atom_htp.htp.tp;
}

//�󳤶�
int Lnegth(GList L) {
    int k = 0;
    GLNode *s;
    if(L == NULL)   return 0;
    if(L->tag == ATOM)  exit(0);
    s = L;
    while(s != NULL) {
        k++;
        s = s->atom_htp.htp.tp;
    }
    return k;
}

//�����
int Depth(GList L) {
    int d,max;
    GLNode *s;
    if(L == NULL)   return 1;
    if(L->tag == ATOM)  return 0;
    s = L;
    while(s != NULL) {
        d = Depth(s->atom_htp.htp.hp);
        if(d > max) max = d;
        s = s->atom_htp.htp.tp;
    }
    return max + 1;
}

//����
int Copy(GList S,GList *T) {
    if(S == NULL)   {*T = NULL;return 1;}
    *T = (GLNode*)malloc(sizeof(GLNode));
    if(*T == NULL)  return 0;
    (*T)->tag = S->tag;
    if(S->tag == ATOM)  (*T)->atom = S->atom;
    else {
        Copy(S->atom_htp.htp.hp,&((*T)->atom_htp.htp.hp));
        Copy(S->atom_htp.htp.tp,&((*T)->atom_htp.htp.tp));
    }
    return 1;
}
