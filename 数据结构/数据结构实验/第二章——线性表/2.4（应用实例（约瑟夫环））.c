#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define Max 50
typedef char ElemType;
typedef struct Seqlist {
    ElemType *elem[Max];
    int length;
}*JSeqlist;

//初始化
JSeqlist Init_SeqList(void) {
    JSeqlist L;
    L = (JSeqlist)malloc(sizeof(struct Seqlist));
    if(L != NULL)   L->length = 0;
    else printf("超出范围！\n");
    return L;
}

//查找下标为p的元素
ElemType *Locate_Seqlist(JSeqlist L,int p) {
    if(p >= 0 && p < L->length) return (L->elem);
    else {
        printf("顺序表中不存在相关元素！\n");
        return NULL;
    }
}

//在指定元素前插入元素
int Insert_Seqlist(JSeqlist L,int i,ElemType *x) {
    int j;
    if(L->length == Max) {//L.length是最后一个元素的位置
        printf("顺序表已满，无法进行插入操作！\n");
        return 0;
    }
    if(i < 0 || i > L->length) {//L.length是最后一个元素的位置
        printf("插入位置不对，超出顺序表长度！\n");
        return 0;
    }
    if(i == 0) {
        L->elem[i] = x;
        L->length++;
        return 1;
    }
    for(j = L->length;j <= i;j++) {//从表尾到第i个逐个后移
        L->length++;                //完成插入，表长加1
        return 1;
    }
}

//删除第i个元素
int Delete_SeqList(JSeqlist L,int i) {
    int j;
    if(i < 0 || i > L->length - 1) {//i值不合法
        printf("删除位置不对，超出顺序表长度！\n");
        return 0;
    }
    for(j = i;j < L->length;j++) {
        L->elem[j] = L->elem[j + 1];//将elem[i]之后的元素前移
    }
    L->length--;                    //表长减1
    return 1;                       //删除成功
}

//Josephus问题求解函数
void josephus(JSeqlist  L,int start,int m) {
    int s,i;
    ElemType *w;
    s = start - 1;
    for(i = L->length;i > 0;i--) {//顺序遍历顺序表
        s = (s + m - 1) % i;
        w = Locate_Seqlist(L,s);    //查找顺序表中下标为s的元素值
        printf("出列人员为： %s\n",w);
        Delete_SeqList(L,s);        //删除顺序表中下标为s的元素
    }
}

int main() {
    JSeqlist Josephus;
    int n,m,i,k,s;
    Josephus = Init_SeqList();  //顺序表初始化
    printf("         Josephus问题顺序表求解\n\n");
    printf("请输入本Josephus问题中的总人数：n=");scanf("%d",&n);
    printf("请输入本Josephus问题中的开始人员位置s=");scanf("%d",&s);
    printf("请输入本Josephus问题中的计数值m=");scanf("%d",&m);
    printf("请输入本Josephus问题中的人员名称或者编号：\n");
    for(i = 0;i < n;i++) {
        printf("第%d位置人员名称为：",i + 1);
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
