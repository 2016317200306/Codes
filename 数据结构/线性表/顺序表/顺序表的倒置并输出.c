#include<stdio.h>
#define max 100

//����
typedef struct {
    int data[max];
    int last;
}SeqList;

int main() {
    int num[max],elem,count,sum;
    SeqList a;
    a.last = 0;

    printf("Input numbers of SeqList elements:");
    scanf("%d",&sum);

    //˳�����
    printf("Input elements:\n");
    for(count = 0;count < sum;count++) {
        if(a.last < max) {
            scanf("%d",&elem);
            a.data[count] = elem;
            a.last++;
        }
        else printf("Too much data!\n");
    }

    //�������
    for(count = 0;count < sum;count++) {
        num[count] = a.data[a.last-1];
        a.last--;
    }

    //�������
    for(count = 0;count < sum;count++) {
        a.data[a.last] = num[count];
        a.last++;
    }

    //˳�����
    for(count = 0;count < sum;count++) {
        printf("%d ",a.data[count]);
    }

    return 0;
}
