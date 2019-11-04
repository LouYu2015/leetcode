class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int top = 0;
        int n = nums.size();
        for (int current = 0; current < n; current++) {
            if (nums[current] != val) {
                nums[top++] = nums[current];
            }
        }
        return top;
    }
};
