#include<stdio.h>

typedef struct Block{
    char ch[Max];
    struct Block *next;
}Block;

typedef struct {
    Block *head;
    Block *tail;
    int len;
}BLString;

Block * StrIndex(BLString *s,BLString *t) {
    Block *sp,*tp,*start;

    if(t->len == 0) return s->head->next;
    start = s->head->next;
    sp = start;
    tp = t->head->next;

    while(sp != NULL && tp != NULL) {
        if(sp->ch == tp->ch) {
            sp = sp->next;
            tp = tp->next;
        }
        else {
            start = start->next;
            sp = start;
            tp = t->head->next;
        }
    }
    if(tp == NULL)  return start;
    else return NULL;

}
