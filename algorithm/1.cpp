class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int n = nums.size();
        unordered_map<int, int> index;
        
        for (int i = 0; i < n; i++) {
            if (index.find(nums[i]) != index.end()) {
                if (nums[i] * 2 == target) {
                    result.push_back(index[nums[i]]);
                    result.push_back(i);
                    return result;
                }
            }
            index[nums[i]] = i;
        }
        for (auto entry : index) {
            int num = entry.first;
            int i = entry.second;
            if (index.find(target-num) != index.end() && index[target-num] != i) {
                result.push_back(index[target-num]);
                result.push_back(i);
                return result;
            }
        }
        return result;
    }
};
