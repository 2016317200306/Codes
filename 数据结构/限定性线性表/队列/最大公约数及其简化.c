//շת�����

//�ݹ�ѭ��
int fun(int m,int n) {
    int r;
    if(n > m)   return fun(n,m);
    else if(n == 0) return m;
    else {
        r = m % n;
        return fun(n,r);
    }
}

//ֱ��ѭ��
int fun_change(int m,int n) {
    int r;
    do{
        r = m % n;
        m = n;
        n = r;
    }while(r != 0);
    return m;
}
