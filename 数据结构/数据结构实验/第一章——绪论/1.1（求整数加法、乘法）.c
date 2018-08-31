#include<stdio.h>

int Add(int x,int y) {
    return x + y;
}

long Mul(int x,int y) {
    return x*y;
}

int main() {
    int x,y,s;
    long m;
    scanf("%d %d",&x,&y);
    s = Add(x,y);
    m - Mul(x,y);
    printf("x + y = %d\n",s);
    printf("x * y = %d\n",m);
    return 0;
}
