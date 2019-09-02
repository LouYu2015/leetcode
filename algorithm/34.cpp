class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Find lower bound of index
        int lowerBound = binarySearch(nums, target);
        
        if (lowerBound >= nums.size() || nums[lowerBound] != target) {
            // Target not found
            vector<int> result;
            result.push_back(-1);
            result.push_back(-1);
            return result;
        } else {
            // Find upper bound of index
            int upperBound = binarySearch(nums, target + 1) - 1;
            
            // Return
            vector<int> result;
            result.push_back(lowerBound);
            result.push_back(upperBound);
            return result;
        }
    }
    
    // Binary search for first index where the number is greater or equal to target
    int binarySearch(vector<int>& nums, int target) {
        int n = nums.size();
        int low = -1, high = n, mid = (low + high) / 2;
        // invariant: nums[low] < target <= nums[high]
        while (high - low > 1) {
            if (nums[mid] < target) {
                low = mid;
            } else {
                high = mid;
            }
            mid = (low + high) / 2;
        }
        return low + 1;
    }
};
