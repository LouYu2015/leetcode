class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        // Edge case: array is empty
        if (n == 0) {
            return true;
        }
        
        int min_possible = n - 1;
        // invariant: min_possible is the first position in nums[i..n-1] that is possible to jump to last position
        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= min_possible) {
                min_possible = i;
            }
        }
        return min_possible == 0;
    }
};
