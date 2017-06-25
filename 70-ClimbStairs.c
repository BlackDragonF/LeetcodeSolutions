int climbStairs(int n) {
    int a = 1;
    int b = 2;
    if (n == 1) return a;
    if (n == 2) return b;
    int count;
    int c;
    for (count = 3 ; count <= n ; ++count) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
