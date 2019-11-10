class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0;
        int min_sum = 0;
        int result = 0;
        
        for (int num : nums) {
            current_sum += num;
            min_sum = min(min_sum, current_sum);
            result = max(result, current_sum - min_sum);
        }
        
        return result;
    }
};
