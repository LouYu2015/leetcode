class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        set<set<int>> original_result = combinationSumHelper(candidates, target);
        for (set<int> item : original_result) {
            vector<int> result_item;
            for (int num : item) {
                result_item.push_back(num);
            }
            result.push_back(result_item);
        }
        return result;
    }
    
    set<set<int>> combinationSumHelper(vector<int>& candidates, int target) {
        if (target < 0) {
            return set<set<int>>();
        } else if (target == 0) {
            set<set<int>> result;
            result.insert(set<int>());
            return result;
        } else if (candidates.size() == 0) {
            return set<set<int>>();
        } else {
            int current = candidates.back();
            candidates.pop_back();
            set<set<int>> result;
            
            for (int n = 0; target - current * n >= 0; n++) {
                set<set<int>> sub_result = combinationSumHelper(candidates, target - n * current);
                for (set<int> item : sub_result) {
                    for (int k = 0; k < n; k++) {
                        item.insert(current);
                    }
                    result.insert(item);
                }
            }
            candidates.push_back(current);
            return result;
        }
    }
};
