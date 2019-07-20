class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a = 0;
        int n = s.length();
        bool chars[256];
        memset(chars, 0, sizeof(chars));
        int longest = 0;
        for (int i = 0; i < n; i++) {
            if (chars[s[i]]) {
                do {
                    chars[s[a]] = false;
                    a++;
                } while (s[a - 1] != s[i]);
            }
            chars[s[i]] = true;
            longest = max(longest, i - a + 1);
        }
        return longest;
    }
};
