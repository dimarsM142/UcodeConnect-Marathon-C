int mx_mid(int a, int b, int c) {
    int mid = a;
    if ((b <= a && b >= c) || (b >= a && b <= c)) {
        mid = b;
    }
    if ((c <= b && c >= a) || (c >= b && c <= a)) {
        mid = c;
    }
    return mid;
}
