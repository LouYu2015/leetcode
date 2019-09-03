class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> result = combinationSumHelper(candidates, target);
        return vector<vector<int>>(result.begin(), result.end());
    }
    
    set<vector<int>> combinationSumHelper(vector<int>& candidates, int target) {
        if (target < 0) {
            return set<vector<int>>();
        } else if (target == 0) {
            set<vector<int>> result;
            result.insert(vector<int>());
            return result;
        } else if (candidates.size() == 0) {
            return set<vector<int>>();
        } else {
            int current = candidates.back();
            candidates.pop_back();
            set<vector<int>> result = combinationSumHelper(candidates, target);
            set<vector<int>> sub_result = combinationSumHelper(candidates, target - current);
            
            for (vector<int> item : sub_result) {
                item.push_back(current);
                result.insert(item);
            }
            candidates.push_back(current);
            
            return result;
        }
    }
};
