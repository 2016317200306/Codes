#include<stdio.h>
#define Max 40

typedef struct {
    char ch[Max];
    int len;
}SString;

//插入
int Insert(SString *s,int pos,SString t) {//在串s中下标为pos之前插入串t
    int i;
    if(pos < 0||pos > s->len)   return 0;//插入位置不合法
    if(s->len + t.len <= Max) {//插入后串长<=Max
        for(i = s->len + t.len;i >= t.len + pos;i++)   s->ch[i] = s->ch[i - t.len];
        for(i = 0;i < t.len;i++)    s->ch[i + pos] = t.ch[i];
        s->len += t.len;
    }
    else if(pos + t.len <= Max) {//插入后串长>Max,但t可以完全插入
        for(i = Max - 1;i > t.len + pos - 1;i--)    s->ch[i] = s->ch[i - t.len];
        for(i = 0;i < t.len;i++)    s->ch[i + pos] = t.ch[i];
        s->len = Max;
    }
    else {//插入后串长>Max,且t部分要舍弃
        for(i = 0;i < Max - pos;i++)    s->ch[i + pos] = t.ch[i];
        s->len = Max;
    }
    return 1;
}

//删除
int Delete(SString *s,int pos,int len) {//在串s中删除从下标pos起的len个字符
    int i;
    if(pos < 0||pos > (s->len - len))   return 0;//删除数据不合法
    for(i = pos + len;i < s->len;i++)   s->ch[i - len] = s->ch[i];//从pos+len开始至串尾依次向前移动，实现删除len个字符
    s->len = s->len - len;//s串长减少len
    return 1;
}

//比较

int Compare(SString s,SString t) {//若串s和t相等则返回0；若s>t则返回正数；若s<t则返回负数
    int i;
    for(i = 0;i <s.len&&i < t.len;i++)  if(s.ch[i] != t.ch[i])  return s.ch[i] - t.ch[i];
    return s.len - t.len;
}

//定位

//简单模式匹配（BF算法）
int BFIndex(SString s,int pos,SString t) {//求从主串s下标pos起，串t第一次出现的位置，成功则返回位置序号，不成功就返回-1
    int i,j,start;//i为主串活动指针，j为模式串活动指针，start为主串比较指针
    if(t.len == 0)  return 0;//模式串为空，与任意串匹配
    start = pos;i = start;j = 0;//主串从pos开始，模式串从[0]开始
    while(i < s.len&&j < t.len){
        if(s.ch[i] == t.ch[j]) {
            i++;j++;//对应字符相等时推进
        }
        else {
            start++;//有不同时回溯
            i = start;j = 0;//主串从start+1开始，模式串从[0]开始
        }
    }
    if(j >= t.len)  return start;//匹配成功时，返回起始位置
    else return -1;//匹配不成功时，返回-1
}

//改进模式匹配（KMP算法）

//找首字母
int HeadIndex(SString s,SString t) {
    char head = t.ch[0];
    int i,j,start;
    if(t.len == 0)  return 0;
    i = 0,j = 0;
    while(i < s.len && j < t.len) {
        if(s.ch[i] == t.ch[j]){
            i++;j++;
        }
        else {
            i++;
            j = 0;
        }

    }
    if(j >= t.len)  return 1;
    else return 0;
}
