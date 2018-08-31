#include<stdio.h>
#define Max 40

typedef struct {
    char ch[Max];
    int len;
}SString;

//����
int Insert(SString *s,int pos,SString t) {//�ڴ�s���±�Ϊpos֮ǰ���봮t
    int i;
    if(pos < 0||pos > s->len)   return 0;//����λ�ò��Ϸ�
    if(s->len + t.len <= Max) {//����󴮳�<=Max
        for(i = s->len + t.len;i >= t.len + pos;i++)   s->ch[i] = s->ch[i - t.len];
        for(i = 0;i < t.len;i++)    s->ch[i + pos] = t.ch[i];
        s->len += t.len;
    }
    else if(pos + t.len <= Max) {//����󴮳�>Max,��t������ȫ����
        for(i = Max - 1;i > t.len + pos - 1;i--)    s->ch[i] = s->ch[i - t.len];
        for(i = 0;i < t.len;i++)    s->ch[i + pos] = t.ch[i];
        s->len = Max;
    }
    else {//����󴮳�>Max,��t����Ҫ����
        for(i = 0;i < Max - pos;i++)    s->ch[i + pos] = t.ch[i];
        s->len = Max;
    }
    return 1;
}

//ɾ��
int Delete(SString *s,int pos,int len) {//�ڴ�s��ɾ�����±�pos���len���ַ�
    int i;
    if(pos < 0||pos > (s->len - len))   return 0;//ɾ�����ݲ��Ϸ�
    for(i = pos + len;i < s->len;i++)   s->ch[i - len] = s->ch[i];//��pos+len��ʼ����β������ǰ�ƶ���ʵ��ɾ��len���ַ�
    s->len = s->len - len;//s��������len
    return 1;
}

//�Ƚ�

int Compare(SString s,SString t) {//����s��t����򷵻�0����s>t�򷵻���������s<t�򷵻ظ���
    int i;
    for(i = 0;i <s.len&&i < t.len;i++)  if(s.ch[i] != t.ch[i])  return s.ch[i] - t.ch[i];
    return s.len - t.len;
}

//��λ

//��ģʽƥ�䣨BF�㷨��
int BFIndex(SString s,int pos,SString t) {//�������s�±�pos�𣬴�t��һ�γ��ֵ�λ�ã��ɹ��򷵻�λ����ţ����ɹ��ͷ���-1
    int i,j,start;//iΪ�����ָ�룬jΪģʽ���ָ�룬startΪ�����Ƚ�ָ��
    if(t.len == 0)  return 0;//ģʽ��Ϊ�գ������⴮ƥ��
    start = pos;i = start;j = 0;//������pos��ʼ��ģʽ����[0]��ʼ
    while(i < s.len&&j < t.len){
        if(s.ch[i] == t.ch[j]) {
            i++;j++;//��Ӧ�ַ����ʱ�ƽ�
        }
        else {
            start++;//�в�ͬʱ����
            i = start;j = 0;//������start+1��ʼ��ģʽ����[0]��ʼ
        }
    }
    if(j >= t.len)  return start;//ƥ��ɹ�ʱ��������ʼλ��
    else return -1;//ƥ�䲻�ɹ�ʱ������-1
}

//�Ľ�ģʽƥ�䣨KMP�㷨��

//������ĸ
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
