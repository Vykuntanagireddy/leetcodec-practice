#include <limits.h>

int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    long sum = 0;

    // 1. Whitespace: skip leading spaces only
    while (s[i] == ' ') {
        i++;
    }

    // 2. Signedness: check for '+' or '-'
    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // 3. Conversion & 4. Rounding: read consecutive digits only
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        // Check for 32-bit signed overflow / underflow before multiplying
        if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && digit > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        sum = sum * 10 + digit;
        i++;
    }

    return (int)(sign * sum);
}