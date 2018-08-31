#include<stdio.h>

static long m = 0;

//��A�ƶ���C
void Move(char A,char C) {
    printf("\n�ƶ��������Ӵ�%c��%c",A,C);
    m++;
}

//ִ�г���
//��n�����Ӵ�A�ƶ���C��B��Ϊ����
void Hanoi(int n,char A,char B,char C) {
    if(n == 1)  Move(A,C);  //��1���̴�A�ƶ���C
    else {
        Hanoi(n - 1,A,C,B); //��A��1������n-1����ͨ��C�����ƶ���B
        Move(A,C);          //��n���̴�A�ƶ���C
        Hanoi(n - 1,B,A,C); //��B��1������n-1����ͨ��A�����ƶ���C
    }
}

int main() {
    int n;
    printf("���������Ӹ�����");
    scanf("%d",&n);
    printf("\n�ƶ��������£�\n");
    Hanoi(n,'A','B','C');
    printf("\n\n�ƶ���������Ϊ:%d\n",m);
    return 0;
}
