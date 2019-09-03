class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (target < 0) {
            return vector<vector<int>>();
        } else if (target == 0) {
            vector<vector<int>> result;
            result.push_back(vector<int>());
            return result;
        } else if (candidates.size() == 0) {
            return vector<vector<int>>();
        } else {
            int current = candidates.back();
            candidates.pop_back();
            vector<vector<int>> result;
            
            for (int n = 0; target - current * n >= 0; n++) {
                vector<vector<int>> sub_result = combinationSum(candidates, target - n * current);
                for (vector<int> item : sub_result) {
                    for (int k = 0; k < n; k++) {
                        item.push_back(current);
                    }
                    result.push_back(item);
                }
            }
            candidates.push_back(current);
            return result;
        }
    }
};
