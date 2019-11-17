class Solution {
public:
    int numDecodings(string s) {
        vector<int> ways(s.length() + 2, 1); // ways[i] = Number of ways to decode the string starting from index i
        for (int i = s.length() - 1; i >= 0; i--) {
            ways[i] = s[i] == '0' ? 0 : ways[i + 1]; // Zero is not valid
            if (i + 1 < s.length()) {
                int num = (s[i] - '0') * 10 + s[i + 1] - '0';
                if (num <= 26 && num >= 10) {
                    ways[i] += ways[i + 2];
                }
            }
        }
        return ways[0];
    }
};
