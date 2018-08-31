#include<stdio.h>
#define max 10

typedef struct {
    int data;
    int cursor;
}Component,StaticList[max];

//��ʼ��
void initial(StaticList space, int *av) {
    int k;
    space[0].cursor = -1;

    for(k = 1;k < max - 1;k++)  space[k].cursor = k + 1;
    space[max- 1].cursor = -1;
    *av = 1;

}

//������
int getnode(StaticList space,int *av) {
    int i;
    i = *av;
    *av = space[*av].cursor;
    return i;
}

//���ս��ռ�
void freenode(StaticList space,int *av,int k) {
    space[k].cursor = *av;
    *av = k;
}
