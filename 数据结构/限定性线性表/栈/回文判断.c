#include <stdio.h>
#include <string.h>
#define max 100

int main()
{
    char a[max],s[max];
    int len,mid,next,top,i;

    gets(a);
    len = strlen(a);
    mid = len/2 - 1;             ////求字符串的中点（需要入栈的字符串）

    top = 0;                     //初始化栈
    for(i = 0; i <= mid; ++i)//将mid前的字符依次入栈
    {
        s[++top] = a[i];
    }

    //判断字符串的长度的是奇数还是偶数，并找出需要进行字符匹配的起始下标
    if(len % 2 == 0)
    {
        next = mid + 1;
    }
    else
    {
        next = mid + 2;
    }
    //开始匹配
    for(i = next; i <= len-1; ++i)
    {
        if(a[i] != s[top])
        {
            break;
        }
        else
            top--;
    }

    //如果top的值为0，则说明栈内的所有的字符都被一一匹配了
    if(top==0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
