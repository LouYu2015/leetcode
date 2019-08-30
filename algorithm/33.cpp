class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n, mid = (low + high) / 2;
        int seperator;
        if (nums[low] < nums[high - 1]) {
            seperator = 0;
        } else {
            // invariant: nums[low] > nums[high - 1]
            while (high - low > 1) {
                if (nums[low] < nums[mid]) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            seperator = low + 1;
        }
        
        low = seperator;
        high = seperator + n;
        mid = (low + high) / 2;
        // invariant: nums[low] <= target < nums[high]
        while (high - low > 1) {
            if (nums[mid % n] > target) {
                high = mid;
            } else {
                low = mid;
            }
        }
        
        if (nums[low % n] == target) {
            return low % n;
        } else {
            return -1;
        }
    }
};
