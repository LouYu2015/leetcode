class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Size of array
        int n = nums.size();
        
        // Special case: empty array
        if (n == 0) {
            return -1;
        }
        
        // Find the beginning of sorted part by binary search
        int low = 0, high = n, mid = (low + high) / 2;
        // The beginning of sorted part
        int seperator;
        // Special case: the array is not rotated
        if (nums[low] < nums[high - 1]) {
            seperator = 0;
        } else {
            // Find the index where the number decreased
            // invariant: nums[low] > nums[high - 1]
            while (high - low > 1) {
                if (nums[low] < nums[mid]) {
                    low = mid;
                } else {
                    high = mid;
                }
                mid = (low + high) / 2;
            }
            seperator = low + 1;
        }
        
        // Find the target by binary search
        // By using mod, we virtually make the array circular
        // The range nums[low..high-1] is sorted
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
            mid = (low + high) / 2;
        }
        
        // Check if the target exist
        if (nums[low % n] == target) {
            return low % n;
        } else {
            return -1;
        }
    }
};
