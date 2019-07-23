class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int low1 = 0, high1 = nums1.size(), mid1;
        int low2 = 0, high2 = nums2.size(), mid2;
        int target_index = (nums1.size() + nums2.size()) / 2;
        
        while (high1 > low1) {
            mid1 = (low1 + high1)/2;
            mid2 = binary_search(nums2, low2, high2, nums1[mid1]);
            if (mid1 + mid2 > target_index) {
                high1 = mid1;
            } else {
                low1 = mid1 + 1;
            }
        }
        
        if (mid1 + mid2 == target_index) {
            return nums1[mid1];
        } else {
            return nums2[target_index - mid1]; 
        }
    }
    
    // Return the smallest index of numbers that are greater or equal to target
    int binary_search(vector<int> &nums, int low, int high, int target) {
        int mid = (low + high)/2;
        while (high > low) {
            if (nums[mid] > target) {
                high = mid;
            } else if (nums[mid] == target && (mid == 0 || nums[mid - 1] < target)) {
                return mid;
            } else {
                low = mid + 1;
            }
            mid = (low + high)/2;
        }
        return low;
    }
};
