class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        combine_helper(result, current, n+1, 1, k);
        return result;
    }
    void combine_helper(vector<vector<int>> &result, vector<int> &current, int n, int i, int k) {
        if (n - i < k) {
            return;
        }
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        combine_helper(result, current, n, i+1, k);
        current.push_back(i);
        combine_helper(result, current, n, i+1, k-1);
        current.pop_back();
        return;
    }
};
