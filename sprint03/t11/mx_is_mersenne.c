#include <stdbool.h>

bool mx_is_prime(int);
double mx_pow(double, unsigned int);

bool mx_is_mersenne(int n) {
    bool flag = false;
    if (mx_is_prime (n)) {
        for (int i = 0; i < n; i++) {
            if (mx_is_prime(i)){
                if ((mx_pow (2, i) - 1) == n) {
                    flag = true;
                    break;
                }
            }
            else {
                continue;
            }
        }
    }
    else {
        flag = false;
    }
    return flag;
}
