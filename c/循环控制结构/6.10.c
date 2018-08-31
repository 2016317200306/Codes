#include<time.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
    int magic,guess,counter = 0;
    int ret;
    char reply;
    srand(time(NULL));
    do {
        counter = 0;
        magic = rand() % 100 + 1;
        do {
            printf("Please guess a magic number: ");
            ret = scanf("%d",&guess);
            while(ret != 1) {
                while(getchar() != '\n');
                printf("PLease Please guess a magic number: ");
                ret = scanf("%d",&guess);
            }
            counter++;
            if(guess > magic)   printf("Wrong!Too big!\n");
            else if(guess < magic)  printf("Wrong!Too small!\n");
            else    printf("Right!\n");
        }while(guess !=magic && counter < 10);
        printf("counter = %d\n",counter);
        printf("Do you want to continue(Y/N or y/n)?");
        scanf("%c",&reply);
    }while(reply == 'Y' || reply == 'y');

    return 0;
}

