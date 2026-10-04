#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows <= 1 || numRows >= len) {
        char* res = (char*)malloc(len + 1);
        strcpy(res, s);
        return res;
    }

    char* res = (char*)malloc(len + 1);
    int idx = 0;
    int cycleLen = 2 * numRows - 2;

    for (int r = 0; r < numRows; r++) {
        for (int j = 0; j + r < len; j += cycleLen) {
            // Vertical column element
            res[idx++] = s[j + r];

            // Diagonal element (for middle rows)
            int diagIdx = j + cycleLen - r;
            if (r != 0 && r != numRows - 1 && diagIdx < len) {
                res[idx++] = s[diagIdx];
            }
        }
    }

    res[idx] = '\0';
    return res;
}