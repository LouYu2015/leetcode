class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lowerBound = binarySearch(nums, target);
        
        if (lowerBound >= nums.size() || nums[lowerBound] != target) {
            vector<int> result;
            result.push_back(-1);
            result.push_back(-1);
            return result;
        } else {
            int upperBound = binarySearch(nums, target + 1) - 1;
            vector<int> result;
            result.push_back(lowerBound);
            result.push_back(upperBound);
            return result;
        }
    }
    
    int binarySearch(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n, mid = (low + high) / 2;
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
