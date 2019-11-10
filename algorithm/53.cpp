class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        assert(nums.size() > 0);
        
        int current_sum = 0;
        int min_sum = 0;
        int result = nums[0];
        
        for (int num : nums) {
            current_sum += num;
            result = max(result, current_sum - min_sum);
            min_sum = min(min_sum, current_sum);
        }
        
        return result;
    }
};
