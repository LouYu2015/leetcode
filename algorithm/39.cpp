class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (target < 0) {
            // Defensive case (not possible)
            return vector<vector<int>>();
        } else if (target == 0) {
            // Base case: a solution is found
            vector<vector<int>> result;
            result.push_back(vector<int>());
            return result;
        } else if (candidates.size() == 0) {
            // Base case: not solution is possible
            return vector<vector<int>>();
        } else {
            // Recursive case: consider one candidate
            // Current candidate
            int current = candidates.back();
            // Sub-problems won't need to consider current candidate,
            // so remove current candidate
            candidates.pop_back();
            // Result
            vector<vector<int>> result;
            
            // Consider how many times this candidate is used
            for (int n = 0; target - current * n >= 0; n++) {
                // Sub-problem: recursively consider other candidates
                vector<vector<int>> sub_result = combinationSum(candidates, target - n * current);
                
                // Generate solution from sub-problem solution
                for (vector<int> item : sub_result) {
                    // Add current candidate to solution
                    for (int k = 0; k < n; k++) {
                        item.push_back(current);
                    }
                    
                    // Got a solution from sub-problem
                    result.push_back(item);
                }
            }
            
            // Ensure that the list of candidate is unchanged upon return
            // to prepare for next call
            candidates.push_back(current);
            
            // Return
            return result;
        }
    }
};
