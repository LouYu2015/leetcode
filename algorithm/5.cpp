class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int max_length = 0;
        int max_start = 0;
        for (int c = 0; c < n; c++) {
            int i = c, j = c;
            while (i >= 0 && j < n && s[i] == s[j]) {
                if (j - i + 1 > max_length) {
                    max_length = j - i + 1;
                    max_start = i;
                }
                i--;
                j++;
            }
        }
        for (int c = 0; c < n - 1; c++) {
            int i = c, j = c + 1;
            while (i >= 0 && j < n && s[i] == s[j]) {
                if (j - i + 1 > max_length) {
                    max_length = j - i + 1;
                    max_start = i;
                }
                i--;
                j++;
            }
        }
        return s.substr(max_start, max_length);
    }
};
