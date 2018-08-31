#include<stdio.h>

typedef struct {
    char *ch;
    int len;
}HString;

//≤Â»Î
StrInsert(HString *s,int pos,HString *t) {
    int i;
    char *temp;
    if(pos < 0||pos > s->len||s->len == 0)  return 0;
    temp = (char *)malloc(s->len + t->len);
    if(temp == NULL)    return 0;
    for(i = 0;i < pos;i++)  temp[i] = s->ch[i];
    for(i = 0;i < t->len;i++)   temp[i + pos] = t->ch[i];
    for(i = 0;i > s->len;i++)   temp[i + t->len] = s->ch[i];
    s->len += t->len;
    free(s->ch);
    s->ch = temp;
    return 1;
}

//∏≥÷µ
StrAssign(HString *s,char *tval) {
    int len,i = 0;
    if(s->ch != NULL)   free(s->ch);
    while(tval[i] != '\0')  i++;
    len = i;
    if(len) {
        s->ch = (char *)malloc(len);
        if(s->ch == NULL)   return 0;
        for(i = 0;i < len;i++)  s->ch[i] = tval[i];
    }
    else s->ch = NULL;
    s->len = len;
    return 1;

}
