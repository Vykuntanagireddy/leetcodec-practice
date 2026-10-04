#include <limits.h>

int reverse(int x) {
    // 1. INT_MIN cannot be negated without overflowing
    if (x == INT_MIN) return 0;

    signed int temp = x;
    signed int sum = 0;
    int neg = 0;
    signed int n;

    if (x < 0) {
        temp = -x;
        neg = 1;
    }

    while (temp != 0) {
        n = (temp % 10);

        // 2. Check for overflow before multiplying by 10
        if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && n > 7)) {
            return 0;
        }

        sum = (sum * 10) + n;
        temp = temp / 10;
    }

    if (neg) {
        sum = -sum;
    }

    return sum;
}