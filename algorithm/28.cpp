class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        if (n == 0) {
            return 0;
        }
        
        for (int i = 0; i <= m - n; i++) {
            bool found = true;
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
