#include<stdio.h>
#define max 100

//定义

typedef struct {
    int elem[max];  //数组形式存储元素
    int last;       //记录最后一个元素
}SeqList;

int main() {
    int num,count,left,right,temp;
    SeqList a;
    printf("Input numbers of elements:");
    scanf("%d",&num);
    for(count = 0;count < num;count++) {
        scanf("%d",&a.elem[count]);
    }
    left = 0;
    right = num - 1;
    while(left < right) {
        while(a.elem[left]%2==0)  left++;
        while(a.elem[right]%2==1) right--;
        if(left < right) {
        temp = a.elem[left];
        a.elem[left] = a.elem[right];
        a.elem[right] = temp;
        }
    }

    for(count = 0;count < num;count++) {
        printf("%d ",a.elem[count]);
    }

    return 0;
}
