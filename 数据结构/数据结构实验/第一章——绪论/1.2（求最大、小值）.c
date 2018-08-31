#include<stdio.h>
#include<stdlib.h>

void GetMax_Min(int a[],int n,int &Max,int &Min) {
    int i;
    Max = a[0];
    Min = a[0];
    for(i = 0;i < n;i++) {
        if(a[i] > Max)  Max = a[i];
        if(a[i] < Min)  Min = a[i];
    }
}

int main() {
    int i,Max,Min,int num[10];
    for(i = 0;i < 10;i++) {
        num[i] = rand();
        printf("%d\n",num[i]);
    }
    GetMax_Min(num,10,Max,Min);
    printf("Max = %d\n",Max);
    printf("Min = %d\n",Min);
    return 0;
}
