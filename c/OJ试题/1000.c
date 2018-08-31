#include<stdio.h>

int main() {
    int a,i;
    float b,c,d;
    scanf("%d",&a);
    for(i = 0;i < a;i++) {
        scanf("%f %f",&b,&c);
        d = c / b;
        printf("%.2f\n",d);
    }
    return 0;
}
