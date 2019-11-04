class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        for (int i = 0; i < m; i++) {
            bool found = true;;
            for (int j = 0; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    found = false;
                }
            }
            if (found) {
                return i;
            }
        }
        return -1;
    }
};
