#include<stdio.h>

int main() {
    short i,sum = 0;
    for(i = 1;;i++) {
        sum += i * i * i;
        if(sum >= 1000000)  break;
    }
    printf("count = %d\n",i);

    return 0;
}
