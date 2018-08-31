#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define Max 50
typedef char ElemType;
typedef struct Seqlist {
    ElemType *elem[Max];
    int length;
}*JSeqlist;

//��ʼ��
JSeqlist Init_SeqList(void) {
    JSeqlist L;
    L = (JSeqlist)malloc(sizeof(struct Seqlist));
    if(L != NULL)   L->length = 0;
    else printf("������Χ��\n");
    return L;
}

//�����±�Ϊp��Ԫ��
ElemType *Locate_Seqlist(JSeqlist L,int p) {
    if(p >= 0 && p < L->length) return (L->elem);
    else {
        printf("˳����в��������Ԫ�أ�\n");
        return NULL;
    }
}

//��ָ��Ԫ��ǰ����Ԫ��
int Insert_Seqlist(JSeqlist L,int i,ElemType *x) {
    int j;
    if(L->length == Max) {//L.length�����һ��Ԫ�ص�λ��
        printf("˳����������޷����в��������\n");
        return 0;
    }
    if(i < 0 || i > L->length) {//L.length�����һ��Ԫ�ص�λ��
        printf("����λ�ò��ԣ�����˳����ȣ�\n");
        return 0;
    }
    if(i == 0) {
        L->elem[i] = x;
        L->length++;
        return 1;
    }
    for(j = L->length;j <= i;j++) {//�ӱ�β����i���������
        L->length++;                //��ɲ��룬����1
        return 1;
    }
}

//ɾ����i��Ԫ��
int Delete_SeqList(JSeqlist L,int i) {
    int j;
    if(i < 0 || i > L->length - 1) {//iֵ���Ϸ�
        printf("ɾ��λ�ò��ԣ�����˳����ȣ�\n");
        return 0;
    }
    for(j = i;j < L->length;j++) {
        L->elem[j] = L->elem[j + 1];//��elem[i]֮���Ԫ��ǰ��
    }
    L->length--;                    //����1
    return 1;                       //ɾ���ɹ�
}

//Josephus������⺯��
void josephus(JSeqlist  L,int start,int m) {
    int s,i;
    ElemType *w;
    s = start - 1;
    for(i = L->length;i > 0;i--) {//˳�����˳���
        s = (s + m - 1) % i;
        w = Locate_Seqlist(L,s);    //����˳������±�Ϊs��Ԫ��ֵ
        printf("������ԱΪ�� %s\n",w);
        Delete_SeqList(L,s);        //ɾ��˳������±�Ϊs��Ԫ��
    }
}

int main() {
    JSeqlist Josephus;
    int n,m,i,k,s;
    Josephus = Init_SeqList();  //˳����ʼ��
    printf("         Josephus����˳������\n\n");
    printf("�����뱾Josephus�����е���������n=");scanf("%d",&n);
    printf("�����뱾Josephus�����еĿ�ʼ��Աλ��s=");scanf("%d",&s);
    printf("�����뱾Josephus�����еļ���ֵm=");scanf("%d",&m);
    printf("�����뱾Josephus�����е���Ա���ƻ��߱�ţ�\n");
    for(i = 0;i < n;i++) {
        printf("��%dλ����Ա����Ϊ��",i + 1);
        Josephus->elem[i] = (ElemType *)calloc(10,sizeof(char));
        scanf("%s",Josephus->elem[i]);
        k = Insert_Seqlist(Josephus,i,Josephus->elem[i]);
        if(k == 0)  exit(1);
    }
    josephus(Josephus,s,m);
    free(Josephus);
    getchar();

    return 0;
}
