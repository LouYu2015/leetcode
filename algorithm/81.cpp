class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return false;
        }
        int low = find_start(nums, 0, n - 1);
        if (low == -1) {
            low = 0;
        }
        int high = low + n;
        int mid;
        while (high - low > 1) {
            mid = (low + high) / 2;
            if (nums[mid % n] <= target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return nums[low % n] == target;
    }
    
    int find_start(vector<int> &nums, int low, int high) {
        if (high - low == 0) {
            return -1;
        } else if (high - low == 1) {
            return nums[high] < nums[low]? high : -1;
        }
        int mid = (low + high) / 2;
        int left_result = -1;
        int right_result = -1;
        if (nums[high] <= nums[mid]) {
            left_result = find_start(nums, mid, high);
        }
        if (nums[mid] <= nums[low]) {
            right_result = find_start(nums, low, mid);
        }
        return left_result == -1? right_result : left_result;
    }
};
