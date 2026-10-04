int lengthOfLongestSubstring(char *s)
{
    int last[256] = {0};
    int start = 0;
    int max = 0;
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        unsigned char ch = s[i];

        if (last[ch] > start)
        {
            start = last[ch];
        }

        if (i - start + 1 > max)
        {
            max = i - start + 1;
        }

        last[ch] = i + 1;
    }

    return max;
}