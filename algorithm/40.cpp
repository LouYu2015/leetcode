class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Make sure that all result are sorted so that duplicates are removed
        sort(candidates.begin(), candidates.end());
        
        // Get result
        set<vector<int>> result = combinationSumHelper(candidates, target);
        
        // Convert to vector
        return vector<vector<int>>(result.begin(), result.end());
    }
    
    set<vector<int>> combinationSumHelper(vector<int>& candidates, int target) {
        if (target < 0) {
            // Base case: impossible target
            return set<vector<int>>();
        } else if (target == 0) {
            // Base case: target reached
            set<vector<int>> result;
            result.insert(vector<int>());
            return result;
        } else if (candidates.size() == 0) {
            // Base case: not solution found
            return set<vector<int>>();
        } else {
            // Consider current candidate
            int current = candidates.back();
            candidates.pop_back();
            
            // Consider excluding this candidate
            set<vector<int>> result = combinationSumHelper(candidates, target);
            // Consider including this candidate
            set<vector<int>> sub_result = combinationSumHelper(candidates, target - current);
            
            for (vector<int> item : sub_result) {
                // Include this candidate
                item.push_back(current);
                result.insert(item);
            }
            
            // Make sure that candidates are unchanged upon return
            candidates.push_back(current);
            
            return result;
        }
    }
};
