int Fib(int n) {
    int x,y,z,i;
    if(n == 0||n == 1) return n;
    else{
        x = 0;
        y = 1;
        for(i = 2;i <=n;i++) {
            z = y;
            y += x;
            x = z;
        }
        return y;
    }
}
