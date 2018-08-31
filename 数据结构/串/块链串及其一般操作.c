#include<stdio.h>
#define Max 4

typedef struct Block{
    char ch[Max];
    struct Block *next;
}Block;

typedef struct {
    Block *head;
    Block *tail;
    int len;
}BLString;
