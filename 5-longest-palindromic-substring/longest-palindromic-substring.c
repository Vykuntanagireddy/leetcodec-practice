#include <string.h>
#include <stdlib.h>
 static int expand(char* s, int left, int right, int len) {
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) return "";

    int start = 0, max_len = 1;

    for (int i = 0; i < n; i++) {
        int len1 = expand(s, i, i, n);     // Odd-length palindromes (single-character center)
        int len2 = expand(s, i, i + 1, n); // Even-length palindromes (two-character center)
        int len = len1 > len2 ? len1 : len2;

        if (len > max_len) {
            max_len = len;
            start = i - (len - 1) / 2;
        }
    }
    char* result = (char*)malloc(sizeof(char) * (max_len + 1));
    strncpy(result, s + start, max_len);
    result[max_len] = '\0';

    return result;
    }