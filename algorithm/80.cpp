class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }
        int top = 1;
        int count = 1;
        for(int current = 1; current < n; current++) {
            if (nums[current] == nums[current - 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count <= 2) {
                nums[top++] = nums[current];
            }
        }
        return top;
    }
};
