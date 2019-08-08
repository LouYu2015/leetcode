class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Store result
        vector<string> result;
        
        // Special case: avoid adding empty string to result
        if (n == 0) {
            return result;
        }
        
        helper(result, "", 0, 0, n);
        return result;
    }
    
    // result: result
    // current: the string currently generated
    // opened: number of left parentheses in `current`
    // closed: number of right parentheses in `current`
    // n: target pair of parentheses
    void helper(vector<string> &result, string current, int opened, int closed, int n) {
        // All parentheses are closed
        if (closed == n) {
            result.push_back(current);
            return;
        }
        
        // Can open a parentheses
        if (opened < n) {
            helper(result, current + '(', opened + 1, closed, n);
        }
        
        // If there's a parentheses that is not closed, we can close it
        if (opened > closed) {
            helper(result, current + ')', opened, closed + 1, n);
        }
    }
};
