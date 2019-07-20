class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a = 0;
        int n = s.length();
        set<char> chars;
        int longest = 0;
        for (int i = 0; i < n; i++) {
            if (chars.find(s[i]) != chars.end()) {
                do {
                    chars.erase(s[a]);
                    a++;
                } while (s[a - 1] != s[i]);
            }
            chars.insert(s[i]);
            longest = max(longest, i - a + 1);
        }
        return longest;
    }
};
