class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Record which number is used
        vector<int> used;
        for (int i = 0; i < nums.size(); i++) {
            used.push_back(0);
        }
        
        // Get permutation of index
        vector<vector<int>> p = permuteHelper(used, nums.size());
        
        // Map index to number
        return mapToNums(p, nums);
    }
    
    // Map index to number
    // param p: permutation of index
    // param nums: numbers
    // return: permutation where each index is replaced by corresponding number
    vector<vector<int>> mapToNums(const vector<vector<int>> &p, const vector<int> &nums) {
        vector<vector<int>> result;
        for (const vector<int> &item : p) {
            vector<int> converted;
            for (int k : item) {
                converted.push_back(nums[k]);
            }
            result.push_back(converted);
        }
        return result;
    }
    
    // Return a lis of permutaion
    // param used: used[i] is true iff index 'i' is already used in the permutation
    // param n: total number of index
    vector<vector<int>> permuteHelper(vector<int> &used, int n) {
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                // Use this number, and generate permutations without this number
                used[i] = 1;
                vector<vector<int>> subResult = permuteHelper(used, n);
                used[i] = 0;
                
                // Place this number in the permutation
                for (vector<int> &p : subResult) {
                    p.push_back(i);
                    result.push_back(p);
                }
            }
        }
        
        // Base case: all numbers are used
        if (result.size() == 0) {
            result.push_back(vector<int>());
        }
        return result;
    }
};
