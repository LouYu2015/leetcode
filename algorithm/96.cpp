class Solution {
public:
    int numTrees(int n) {
        vector<int> result;
        result.push_back(1);
        result.push_back(1);
        for (int i = 2; i <= n; i++) {
            int count = 0;
            for (int left = 0; left < i; left++) {
                int right = i - 1 - left;
                count += result[left] * result[right];
            }
            result.push_back(count);
        }
        return result[n];
    }
};
