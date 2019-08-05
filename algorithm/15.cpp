class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> num_set;
        
        // Number of numbers
        int n = nums.size();
        // Result
        vector<vector<int>> result;
        
        // For all pair of numbers, check if the other element in the triplet exist in the set
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 2 && nums[i+1] == nums[i] && nums[i+1] == nums[i+2]) {
                continue;
            }
            int a = nums[i];
            for (int j = 0; j < i; j++) {
                if (j > 0 && nums[j-1] == nums[j]) {
                    j++;
                }
                int b = nums[j];
                int c = -nums[i]-nums[j];
                if (num_set.find(c) != num_set.end()) {
                    // Found a triplet
                    vector<int> entry;
                    entry.push_back(a);
                    entry.push_back(b);
                    entry.push_back(c);
                    result.push_back(entry);
                }
            }
            num_set.insert(a);
        }
        return result;
    }
};
