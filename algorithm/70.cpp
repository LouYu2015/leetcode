class Solution {
public:
    int climbStairs(int n) {
        vector<int> ways(n + 2, 1);
        for (int i = n - 1; i >= 0; i--) {
            ways[i] = ways[i+1] + ways[i+2];
        }
        return ways[0];
    }
};
