#include <stdio.h>
#include <string.h>
#define max 100

int main()
{
    char a[max],s[max];
    int len,mid,next,top,i;

    gets(a);
    len = strlen(a);
    mid = len/2 - 1;             ////���ַ������е㣨��Ҫ��ջ���ַ�����

    top = 0;                     //��ʼ��ջ
    for(i = 0; i <= mid; ++i)//��midǰ���ַ�������ջ
    {
        s[++top] = a[i];
    }

    //�ж��ַ����ĳ��ȵ�����������ż�������ҳ���Ҫ�����ַ�ƥ�����ʼ�±�
    if(len % 2 == 0)
    {
        next = mid + 1;
    }
    else
    {
        next = mid + 2;
    }
    //��ʼƥ��
    for(i = next; i <= len-1; ++i)
    {
        if(a[i] != s[top])
        {
            break;
        }
        else
            top--;
    }

    //���top��ֵΪ0����˵��ջ�ڵ����е��ַ�����һһƥ����
    if(top==0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
