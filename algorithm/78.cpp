class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        subset_helper(result, current, nums, 0);
        return result;
    }
    
    void subset_helper(vector<vector<int>> &result, vector<int> &current, vector<int> &nums, int i) {
        if (i == nums.size()) {
            result.push_back(current);
            return;
        }
        subset_helper(result, current, nums, i+1);
        current.push_back(nums[i]);
        subset_helper(result, current, nums, i+1);
        current.pop_back();
    }
};
