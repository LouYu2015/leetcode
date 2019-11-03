class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int top = 1;
        for (int current = 1; current < n; current++) {
            if (nums[current] != nums[current - 1]) {
                nums[top++] = nums[current];
            }
        }
        return top;
    }
};
