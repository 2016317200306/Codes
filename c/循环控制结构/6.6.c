#include<stdio.h>

int main() {
    int magic;
    int guess;
    magic = rand();
    printf("Please guess a magic number: ");
    scanf("%d",&guess);
    if(guess > magic)   printf("Wrong!Too big!\n");
    else if(guess < magic)  printf("Wrong!Too small!\n");
    else printf("Right!\n");

    return 0;
}
