#include<time.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
    int magic,guess,counter = 0;
    srand(time(NULL));
    magic = rand() % 100 + 1;
    do {
        printf("Please guess a magic number: ");
        scanf("%d",&guess);
        counter++;
        if(guess > magic)   printf("Wrong!Too big!\n");
        else if(guess < magic)  printf("Wrong!Too small!\n");
        else printf("Right!\n");
    }while(guess != magic && counter < 10);
    printf("counter = %d\n",counter);

    return 0;
}
