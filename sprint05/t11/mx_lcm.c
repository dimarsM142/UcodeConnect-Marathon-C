int mx_gcd(int, int);

int mx_lcm(int a, int b) {
    long long check = 0;
    if(a < 0) {
        a *= -1;
    }
    if(b < 0) {
        b *= -1;
    }
    for(int i = 0; i < b; i++) {
        check += a;
    }
    if(check > 2147483647) {
        return 0;
    }
    return (a * b) / mx_gcd(a, b);
}
