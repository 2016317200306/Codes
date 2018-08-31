#include<stdio.h>

int main() {
    int i,n;
    for(i = 1;i <= 5;i++) {
        printf("Please enter n: ");
        scanf("%d",&n);
        if(n < 0)   goto END;
        printf("n = %d\n",n);
    }
END:printf("Program is over!\n");

    return 0;
}
