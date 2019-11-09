class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n, mid;
        while (high - low > 1) {
            mid = (low + high) / 2;
            if (nums[mid] <= target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
