// mapping[i] is the ID of the first letter for button i + 2
int mapping[9] = {0, 3, 6, 9, 12, 15, 19, 22, 26};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        helper(digits, 0, result, "");
        return result;
    }
    
    void helper(string &digits, int i, vector<string> &result, string current) {
        if (i < digits.length()) {
            // Iterate through all letters for this button
            for (int k = mapping[digits[i] - '2']; k < mapping[digits[i] - '2'  + 1]; k++) {
                helper(digits, i + 1, result, current + (char)('a' + k));
            }
        } else if (i > 0) {
            // Save result only if the string is not empty
            result.push_back(current);
        }
    }
};
