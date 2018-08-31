#include<stdio.h>
#include<stdlib.h>

int main() {
    int magic;
    int guess;
    int counter = 0;
    magic = rand() % 100 + 1;
    do {
        printf("Please guess a magic number: ");
        scanf("%d",&guess);
        counter++;
        if(guess > magic)   printf("Wrong!Too high!\n");
        else if(guess < magic)  printf("Wrong!Too small!\n");
        else printf("Right!\n");
    }while(guess != magic);
    printf("counter = %d\n",counter);

    return 0;
}
