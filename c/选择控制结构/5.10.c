#include<stdio.h>

int main() {
    int a,b,max,ret;
    printf("Input a,b: ");
    ret = scanf("%d,%d",&a,&b);
    if(ret != 2) {
        printf("Input data quantity or format error!\n");
        fflush(stdin);
    }
    else {
        max = a > b ? a : b;
        printf("max = %d\n",max);
    }

    return 0;
}
