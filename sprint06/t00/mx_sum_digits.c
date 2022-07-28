int mx_sum_digits(int num) {
    int counter = 0;
    int temp = num;
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    if (sum < 0) {
        sum *= -1;
    }
    return sum;
}
