#include<stdio.h>
#define max 100

//∂®“Â
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

    //À≥–Ú¥Ê»Î
    printf("Input elements:\n");
    for(count = 0;count < sum;count++) {
        if(a.last < max) {
            scanf("%d",&elem);
            a.data[count] = elem;
            a.last++;
        }
        else printf("Too much data!\n");
    }

    //µπ–Ú ‰≥ˆ
    for(count = 0;count < sum;count++) {
        num[count] = a.data[a.last-1];
        a.last--;
    }

    //µπ–Ú¥Ê»Î
    for(count = 0;count < sum;count++) {
        a.data[a.last] = num[count];
        a.last++;
    }

    //À≥–Ú ‰≥ˆ
    for(count = 0;count < sum;count++) {
        printf("%d ",a.data[count]);
    }

    return 0;
}
