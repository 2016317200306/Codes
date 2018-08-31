#include<stdio.h>

static long m = 0;

//从A移动到C
void Move(char A,char C) {
    printf("\n移动顶部盘子从%c到%c",A,C);
    m++;
}

//执行程序
//把n个盘子从A移动到C，B作为辅助
void Hanoi(int n,char A,char B,char C) {
    if(n == 1)  Move(A,C);  //将1号盘从A移动到C
    else {
        Hanoi(n - 1,A,C,B); //将A上1号盘至n-1号盘通过C辅助移动到B
        Move(A,C);          //将n号盘从A移动到C
        Hanoi(n - 1,B,A,C); //将B上1号盘至n-1号盘通过A辅助移动到C
    }
}

int main() {
    int n;
    printf("请输入盘子个数：");
    scanf("%d",&n);
    printf("\n移动步骤如下：\n");
    Hanoi(n,'A','B','C');
    printf("\n\n移动步骤总数为:%d\n",m);
    return 0;
}
