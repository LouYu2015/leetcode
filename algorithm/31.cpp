class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Special case: empty or single element
        // permutation won't change
        if (nums.size() <= 1) {
            return;
        }
        
        int i;
        for (i = nums.size() - 2; i >= 0; i--) {
            // Find another number that can increase nums[i]
            int min_index = -1;
            for (int j = i + 1; j < nums.size(); j++) {
                // The number should be greater than this number, but it shoud also be minimum so that the new permutation is adjacent to current one
                if (nums[j] > nums[i] && (min_index == -1 || nums[j] < nums[min_index])) {
                    min_index = j;
                }
            }
            
            // If such a number is found, increase this number
            // else, continue to other position
            if (min_index != -1) {
                // Increase nums[i]
                swap(nums[i], nums[min_index]);
                break;
            }
        }
        
        // Other parts should be sorted so that it's a lexicorgraphically minimum permutation
        sort(nums.begin() + (i + 1), nums.end());
    }
};
