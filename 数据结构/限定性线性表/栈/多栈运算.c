#define M 10
typedef struct node{
    int data;
    struct node *next;
}LinkStackNode,*LinkStack;

LinkStack top[M];
