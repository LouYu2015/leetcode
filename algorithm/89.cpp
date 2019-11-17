class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) {
            vector<int> result;
            result.push_back(0);
            return result;
        }
        vector<int> result = grayCode(n - 1);
        for (int i = result.size() - 1; i >= 0; i--) {
            result.push_back(result[i] + (1<<(n-1)));
        }
        return result;
    }
};
