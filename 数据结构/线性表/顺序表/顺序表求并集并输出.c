#include<stdio.h>
#define max 100

//����
typedef struct {
    int data[max];
    int last;
}SeqList;

//����
int Locate(SeqList *L,int e) {
    int i=0;
    while((i <= (*L).last)&&((*L).data[i] != e)){
        i++;
    }
    if(i <= (*L).last)
        return 1;
    else
        return 0;
}

int main() {
    SeqList a,b,combine;
    combine.last = 0;
    int sum_a,sum_b,count,number,log[max],sum_log;

    //a��Ԫ������
    printf("Input numbers of elements in Seqlist a:");
    scanf("%d",&sum_a);
    printf("Input elements in a:\n");
    for(count = 0;count < sum_a;count++) {
        scanf("%d",&a.data[count]);
    }

    //b��Ԫ������
    printf("Input numbers of elements in Seqlist b:");
    scanf("%d",&sum_b);
    printf("Input elements in b:\n");
    for(count = 0;count < sum_b;count++) {
        scanf("%d",&b.data[count]);
    }


    //�Ȳ���a��
    for(count = 0;count < sum_a;count++) {
        combine.data[count] = a.data[count];
        combine.last++;
    }

    //�ų��ظ�Ԫ�ز���b��
    for(count = 0;count < sum_b;count++) {
        if(!Locate(&a,b.data[count])) {combine.data[combine.last] = b.data[count];combine.last++;}
    }

    //�������
    for(count = 0;count < combine.last;count++) {
        printf("%d ",combine.data[count]);
    }

    return 0;
}
